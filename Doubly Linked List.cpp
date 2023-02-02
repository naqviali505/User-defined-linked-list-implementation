#include<iostream>
#include<string>
using namespace std;
struct Term
{
	float coeffecient;
	int power;
	string nameOfCharacterOfTerm;
	Term* next;
	Term* prev;
};
class Polynomial
{
	Term* first;
public:
	Term* getfirst()
	{
		return first;
	}
	Polynomial()
	{
		first->coeffecient = 0;
		first->power = 0;
		first->nameOfCharacterOfTerm = " ";
		first->next = nullptr;
		first->prev = nullptr;
	}
	Polynomial(Polynomial& obj)
	{
		Term* node = obj.first;
		while (node != NULL)
		{
			insertAtLast(*node);
			node = node->next;
		}
	}
	Polynomial& operator=(Polynomial& obj)
	{
		first = NULL;
		Term* node = obj.first;
		while (node != NULL)
		{
			insertAtLast(*node);
			node = node->next;
		}
		return *this;
	}
	void insertAtStart(Term& t)
	{
		if (first == nullptr)
		{
			Term* node = new Term;
			node->coeffecient = t.coeffecient;
			node->nameOfCharacterOfTerm = t.nameOfCharacterOfTerm;
			node->power = t.power;
			node->next = nullptr;
			node->prev = nullptr;
			first = node;
		}
		else
		{
			Term* node = new Term;
			node->coeffecient = t.coeffecient;
			node->nameOfCharacterOfTerm = t.nameOfCharacterOfTerm;
			node->power = t.power;
			node->prev = nullptr;
			first->prev = node;
			node->next = first;
		}
	}
	void insertAtLast(Term& t)
	{
		Term* current = first;
		Term* trailcurrent = current;
		while (current->next != NULL)
		{
			trailcurrent = current;
			current = current->next;
		}
		Term* node = new Term;
		node->coeffecient = t.coeffecient;
		node->nameOfCharacterOfTerm = t.nameOfCharacterOfTerm;
		node->power = t.power;
		node->next = nullptr;
		node->prev = trailcurrent;
	}
	void deleteTerm(Term& t)
	{
		Term* temp = first;
		while (temp != NULL && temp->coeffecient != t.coeffecient && temp->nameOfCharacterOfTerm != t.nameOfCharacterOfTerm && temp->power != t.power)
		{
			temp = temp->next;
		}
		if (temp != NULL)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
	}
	void displayPolynomial()
	{
		Term* node = first;
		while (node != NULL)
		{
			cout << "Co-effecient" << " " << "Character Name" << " " << " Power" << endl;
			cout << node->coeffecient << " " << node->nameOfCharacterOfTerm << " " << node->power << endl;
			node = node->next;
		}
	}
	Polynomial& operator + (const Polynomial& ref)
	{
		Polynomial obj1;
		Term* node = first;
		while (node != NULL)
		{
			obj1.insertAtLast(*node);
			node = node->next;
		}
		Term* n1 = ref.first;
		while (n1 != NULL)
		{
			obj1.insertAtLast(*n1);
			n1 = n1->next;
		}
		return obj1;
	}
	Polynomial& operator + (const Term& t)
	{
		Term* node = first;
		while (node != NULL)
		{
			if (first->nameOfCharacterOfTerm == t.nameOfCharacterOfTerm && first->power == t.power)
			{
				Term* nptr = first;
				nptr->coeffecient = first->coeffecient + t.coeffecient;
			}
			else
			{
				insertAtLast(*node);
			}
			node = node->next;
		}
		return *this;
	}
	Polynomial& operator - (const Polynomial& ref)
	{
		Polynomial obj1;
		Term* node = first;
		while (node != NULL)
		{
			if (node->coeffecient == ref.first->coeffecient && node->nameOfCharacterOfTerm == ref.first->nameOfCharacterOfTerm && node->power == ref.first->power)
			{
				deleteTerm(*node);
			}
			node = node->next;
		}
		Term* n1 = ref.first;
		while (n1 != NULL)
		{
			if (node->coeffecient == ref.first->coeffecient && node->nameOfCharacterOfTerm == ref.first->nameOfCharacterOfTerm && node->power == ref.first->power)
			{
				deleteTerm(*n1);

			}
			n1 = n1->next;
		}
		return obj1;
	}
	Polynomial& operator - (const Term& t)
	{
		Term* node = first;
		while (node != NULL)
		{
			if (first->nameOfCharacterOfTerm == t.nameOfCharacterOfTerm && first->power == t.power)
			{
				Term* nptr = first;
				nptr->coeffecient = first->coeffecient - t.coeffecient;
			}
			else
			{
				insertAtLast(*node);
			}
			node = node->next;
		}
		return *this;
	}
	Polynomial& operator * (const float& c)
	{

	}
	Polynomial& operator * (const Term& t)
	{
		Term* node = first;
		while (node != NULL)
		{
			Term* nptr = first;
			nptr->coeffecient = first->coeffecient * t.coeffecient;
			nptr->nameOfCharacterOfTerm = first->nameOfCharacterOfTerm + t.nameOfCharacterOfTerm;
			nptr->power = first->power * t.power;
			node = node->next;
		}
		return *this;
	}
};
class QuadraticEquation :public Polynomial
{
public:
	QuadraticEquation()
	{}
	// check that highest power must not be more than 2 void insertAtStart(Term &);
	void insertAtLast(Term& t)
	{
		if (t.power > 2)
		{
			cout << "Not a quadratic equation\n";
		}
		else if (t.power <= 2)
		{
			insertAtLast(t);
		}
	}
	void insertAtLast(Term& t)
	{
		if (t.power > 2)
		{
			cout << "Not a quadratic equation\n";
		}
		else if (t.power <= 2)
		{
			insertAtStart(t);
		}
	}
	void solveQuadraticRoots() // This function print the roots of quadratic equation
	{
		int a = 0,b=0,c=0;
		Term* node = getfirst();
		while (node != NULL)
		{
			if (node->power == 2)
			{
				a = node->coeffecient;
			}
			else if (node->power == 1)
			{
				b = node->coeffecient;
			}
			else if (node->power == 0)
			{
				c = node->coeffecient;
			}
			node = node->next;
		}
		float disc1 = 0,firstval=0,secondval=0,firstroot=0,secroot=0 ;
		disc1 = pow(b * b - (4 * a * c), 0.5);
		firstval = -disc1 - b;
		secondval = disc1 + b;
		firstroot = firstval / (2 * a);
		secroot = secondval / (2 * a);
		cout << "The two roots of the quadratic equations are " << firstroot << " and " << secroot << endl;

	}
};
int main()
{

}