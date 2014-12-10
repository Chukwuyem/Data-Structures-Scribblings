/*
 * assign_1.cpp
 *
 *  Created on: 2 Mar 2014
 *      Author: Admin
 *	This program involves implementing a simple linked list structure and a function reverse
 *	which reverses the list when called.
 *
 */
#include <iostream>
using namespace std;

template <class T> //that way, the list can store in different types not just on etype which would be int
class node
{
public:
	T data;
	node *next;
	bool isEmpty(node<T> *&head);
	void insertAsFirstElement(node<T> *&head, node<T> *&last, T data);
	void insert(node<T> *&head, node<T> *&last, T data);
	void remove(node<T> *head, node<T> *last);
	void printList(node<T> *&current);
	void reverse(node<T> *&start);
};


template <class T>
bool isEmpty(node<T> *&head)
{
	if (head == NULL)
		return true;
	else
		return false;
}

template <class T>
void insertAsFirstElement(node<T> *&head, node<T> *&last, T data)
{
	node<T> *temp;
	temp= new node<T>; //initializing a new node temporary(temp)
	temp-> data= data; //the temp's data is the one enter in the argument
	temp->next= NULL; //the temp's next pointer points to null
	head= temp; //because you are inserting it as first element
	last= temp; //because you are inserting it as first element
}

template <class T>
void insert(node<T> *&head, node<T> *&last, T data)
{
	if (isEmpty(head))
		insertAsFirstElement(head, last, data);
	else
	{
		node<T> *temp;
		temp= new node<T>;
		temp->data = data;
		temp-> next = NULL;
		last->next = temp; //remember the first element was head and last, with both pointing to NULL... but now, every node added is last..
		//therefore, we first change the first element to point to temp
		last= temp; //then make the latest element last
	}

}

template <class T>
void remove(node<T> *head, node<T> *last) //remove the first element... FIFO
{
	if (isEmpty(head))
		cout<< "The list is already empty.\n";
	else if (head == last) //if it has one item
	{
		delete head;
		head== NULL;
		last== NULL;
	}
	else
	{ 
		//else, we first assign the first node to a var, make the next node head, then kill the former head
		node<T> *temp= head;
		head = head->next;
		delete temp;
	}

}

template <class T>
void printList(node<T> *&current)
{
	if (isEmpty(current))
		cout<< "This list is empty.\n";
	else
	{
		cout<< "This list contains: \n";
		node<T> *prTemp= current;
		while (prTemp != NULL)
		{
			//cout << "printing...\n";
			cout << prTemp->data << "\n";
			prTemp= prTemp->next;
		}
	}

}

template <class T>
void reverse(node<T> *&start) //the reverse function
{
	if (isEmpty(start))
		cout << "This list is empty.\n";
	else
	{
		node<T> *tempr1; //for first value
		node<T> *tempr2 = NULL;
		while(start-> next != NULL){
			tempr1 = start;
			start = start-> next;
			tempr1-> next = tempr2;
			tempr2 = tempr1;
		}

		start->next = tempr2;
	}
};

int main()
{
	node<int> *head, *last;
	head= NULL; //initializing pointers
	last= NULL;

	insertAsFirstElement(head, last, 0);

	for (int i=1; i<10; i+= 1){
		insert(head, last, i);
	}

	cout << head-> data << "\n";
	cout << last -> data << "\n";
	printList(head);
	cout << "reversing...\n";
	reverse(head);

	printList(head);

	return 0;

}



