// GenericLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "List.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	//List<int> intList;
	List<int> myList;
	myList.ToString();
	myList.Insert(100);
	myList.ToString();
	myList.Insert(200);
	myList.ToString();
	myList.Insert(300);
	myList.ToString();

	myList.Remove(200);
	myList.ToString();
	myList.Remove(100);
	myList.ToString();
	myList.Remove(300);
	myList.ToString();
	
	char ch;
	std::cin >> ch;
	//ListNode<int> intNode(10);
	return 0;
}

