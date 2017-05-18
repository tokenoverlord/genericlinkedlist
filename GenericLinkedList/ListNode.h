#ifndef LISTNODE_H
#define LISTNODE_H

#include "stdafx.h"

template <typename T> class List;

template <typename T> class ListNode
{

	friend class List < T > ;

public:

	ListNode(T);
	T GetData();

private:
	T data;
	ListNode *next;
};

template<typename T>
ListNode<T>::ListNode(T dataIn){
	data = dataIn;
	next = NULL;
}

template<typename T>
T ListNode<T>::GetData(){
	return data;
}
#endif