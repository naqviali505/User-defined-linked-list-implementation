#pragma once
#include<iostream>
using namespace std;
template<typename T>
class LinkedList		//This is start of our Linked List class which is nested above Node class
{

private: 			//Here are defined private attributes of LinkedList class which are
                                // a nested Node class and head/tail pointers
	
	template<typename T>   //Header files only contain declaration which are resolved later but
	class Node		//Class Node is resolved within the scope because it's private attribute
	{
	public:
		Node()
		{
			data = 0;
			next = NULL;
		}	
		T data;
		Node* next;
	};
	
	
	Node<T>* head;          //Link list private attributes e;g Head/Tail
public:

	LinkedList();	
        ~LinkedList();
		              //Signatures of public member functions are defined here
	void insertAtStart(T const element);  //But it's not a recommended practice to implement these functions within the header file.
	void DeleteAtStart();
	void print();


};
