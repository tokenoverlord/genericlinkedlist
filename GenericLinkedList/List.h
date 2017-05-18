#ifndef LIST_H
#define LIST_H

#include "ListNode.h"
#include <iostream>

using std::cout;
using std::endl;

template <typename T> class List
{
public:
	List();
	~List();

	void InsertBegin(T);
	void InsertEnd(T);
	void Remove(T);

	void Insert(T);
	void ToString();
	int Count();

private:
	ListNode<T> *head;
	ListNode<T> *tail;
	int count;
};


template <typename T>
List<T>::List()
{
	count = 0;
	head = NULL;
	tail = NULL;
}

template <typename T>
List<T>::~List()
{
}

template<typename T>
void List<T>::ToString(){
	// get the temp pointer to the head
	ListNode<T> *tmp = head;

	// check if the head is null
	if (tmp == NULL){
		// list is empty
		cout << "EMPTY" << endl;

		// nothing else to print return
		return;
	}

	// check if the next node is null
	if (tmp->next == NULL){
		// just display the current node's data
		cout << tmp->GetData();
		cout << " --> ";
		cout << "NULL" << endl;

		// all done return
		return;
	}

	// go through all nodes and print out all nodes
	do{
		// display the current node
		cout << tmp->GetData();
		cout << " --> ";

		// set the next
		tmp = tmp->next;

	} while (tmp != NULL);

	// we went though the list the node should be NULL.
	cout << "NULL" << endl;
}

template<typename T>
void List<T>::InsertEnd(T data){
	
	// create a node
	ListNode<T> * node = new ListNode<T>(data);

	if (Count() == 0){
		// list is empty
		head = node;
		tail = node;
	}
	else
	{
		// list is not empty
		tail->next = node;	// set the tail's next node to the new node
		tail = node;		// set the tail to the next node
	}

	// increase the count
	count++;
}

template<typename T>
void List<T>::InsertBegin(T data) {

	// create a node
	ListNode<T> * node = new ListNode<T>(data);

	if (Count() == 0) {
		// list is empty
		head = node;	// new head
		tail = node;	// new tail
	}
	else
	{
		// list is not empty
		node->next = head;	// set node's next to the head
		head = node;		// set new node as the head
	}

	// increase the count
	count++;
}

template<typename T>
void List<T>::Insert(T data) {
	// check if the list is empty
	if (Count() == 0) {
		// list is empty we need to add the node to the begining
		InsertBegin(data);
	}
	else {
		// insert the data at the end of the list.
		InsertEnd(data);
	}
}

template<typename T>
int List<T>::Count(){
	return count;
}

template<typename T>
void List<T>::Remove(T data){
	// check if the
	if (Count() == 0) {
		// nothing to remove
		return;
	}

	// find the first occurance of data and remove it from the list
	ListNode<T> *prv = NULL;
	// get the next node
	ListNode<T> *cur = head;

	while (cur != NULL) {
		// check the data in cur
		if (cur->data == data) {
			/*
			There are 4 cases we need to check for this solution:
			1. Removing the head.
			2. Removing the tail.
			3. Removing the only element.
			4. Removing the node from a list counting more than 2 nodes
			These 3 cases directly affect the pointers to the head and tail of the list.
			*/

			// Lets do case 3 here since it affects both the head and tail.
			if (Count() == 1) {
				// With the count at 1 we know that the node is both the head and tail.
				// remove the current node
				delete(cur);

				// update the count
				count--;

				// change the head and tail to null
				head = NULL;
				tail = NULL;

				// return
				return;
			}

			// since we taking care of the case that affects both head and tail above we can focus in 
			// on cases that only affect one.

			// check if the prv node is NULL?
			if (prv == NULL) {
				// the current node is the head we must change the head after we remove the current node
				head = cur->next;

				// remove the current node
				delete(cur);

				// update the count
				count--;

				// return
				return;
			}

			// check if the next node is NULL?
			if (cur->next == NULL) {
				// the current node is the tail we must change the tail after we remove the current node
				tail = prv;

				// set the new next pointer
				tail->next = NULL;

				// remove the current
				delete(cur);

				// udpate the count
				count--;

				return;
			}

			// this is the case where the node is in the middle of a list with more than 2 nodes
			prv->next = cur->next; // connect the previous node to the current node's next.
			// delete the current node
			delete(cur);
			// update the count
			count--;

			return;
		}
		else {
			// save the current node as the previous
			prv = cur;
			// go to the next node.
			cur = cur->next;
		}
	}
}
#endif LIST_H