#include "Circular_Linked_List.h"
#include<iostream>
using namespace std ;

template < typename T >
NodeC<T>::NodeC(){
    this->next = nullptr;
    this->data = nullptr;
}

template < typename T >
NodeC<T>::NodeC(T data){
    this->next = this;
    this->data = data;
}

template < typename T >
Circular_Linked_List<T>::Circular_Linked_List():head(nullptr){
}

template < typename T >
Circular_Linked_List<T>::~Circular_Linked_List()
{
    if(this->head != nullptr){
        NodeC< T > * temp = this->head;
        while ( temp -> next != nullptr ){
            this->head = temp -> next ;
            delete temp;
            temp = this->head;
        }
        delete this->head;
    }
}

template < typename T >
bool Circular_Linked_List<T>::isEmpty ( ) {
    
}

template < typename T >
void Circular_Linked_List<T>::insertElement ( T const element ) {
    
}


//*********************************************************************//
class Process {
public :
    string name;
    int executionTime;
    int remainingTime;
    Process() {
        this->name = "";
        this->executionTime = 0;
        this->remainingTime = 0;
    }
    Process(string pName, int ex_time) {
        this->name = pName;
        this->executionTime = ex_time;
        this->remainingTime = ex_time;

    }

};
class RoundRobinCLL : public Circular_Linked_List<Process> {
private:
    int quantum ;
public:
   //insertion is same as in CLL
  
    RoundRobinCLL():Circular_Linked_List() {
        this->quantum = 1;
    }
    RoundRobinCLL(int q):Circular_Linked_List() {
        this->quantum = q;
    }
    void deleteProcess(Process const p) {
       
    }
    void printRRList() {
        
    }
    void ExecuteProcess() {
       
    }

};

int main()
{
    RoundRobinCLL RR(2);  //in default  constructor , q is set to 1
    Process p1("A",5);
    Process p2("B", 3);
    Process p3("C", 6);
    Process p4("D", 4);
    Process p5("E", 3);
    RR.insertElement(p1);
    RR.insertElement(p2);
    RR.insertElement(p3);
    RR.insertElement(p4);
    RR.insertElement(p5);
    RR.printList();
	RR.ExecuteProcess();
	cout<<RR.isEmpty();
    return 0;
}