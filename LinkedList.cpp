#include<iostream>
#include"LinkedList.h"   //Including header file in resource file

using namespace std;


template<typename T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	
}
template<typename T>
LinkedList<T>::~LinkedList()
{
	head = NULL;
	
}
	
template<typename T>
void LinkedList<T>::insertAtStart(T const element)
{
	Node<T>* node = new Node<T>();
	node->data = element;
	node->next = NULL;

	if (head==NULL)
	{
		head = node;
	
	}
	else
	{
	Node<T>* temp = head;
	node->next=temp;
	head=node;
	}
	
	
}


template<typename T>
void LinkedList<T>::DeleteAtStart()
{
	Node<T>* temp = head;

        head = temp->next;
	
	delete temp;

}


template<typename T>
void LinkedList<T>::print(){
Node<T>* temp = head;
	while(temp!=NULL){
	cout<<temp->data;
	temp=temp->next;
}
}

