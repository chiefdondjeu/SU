#ifndef NODELIST_H
#define NODELIST_H

#include <iostream>

#include "d_node.h"

//display all elements in the list
template <typename T>
void display(Node<T> *list)
{
	Node<T> *nodePtr;
	nodePtr = list;

	while(nodePtr)//while nodePtr != NULL
	{
		std :: cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}
	std :: cout << std :: endl;

}

//adds elemnt at the front of the list
template <typename T>
Node<T>* push_front(Node<T> *list, T val)
{
	Node<T> *newNode;
	newNode = new Node<T>(val);

	newNode->next = list;
	list = newNode;

	return newNode;

}

//adds element at the end of the list
template <typename T>
Node<T> push_back(Node<T> *list, T val)
{
	Node<T> *newNode, *prevNode;

	newNode = new Node<T>(val);
	prevNode = list->next;

	while(prevNode->next)
		prevNode = prevNode->next;

	prevNode->next = newNode;

	return *newNode;
}

//insert an element into the list
template <typename T>
void push_in()
{

}

//search if a target value in the list or not
template <typename T>
bool isIn(Node<T> *list, T target)
{
	bool check = false;
	Node<T> *nodePtr;
	
	nodePtr = list;
	while(nodePtr)
	{
		if(nodePtr->value == target)
			check = true;

		nodePtr = nodePtr->next;
	}

	if(check != false)
		return true;

	else return false;
}

template <typename T>
Node<T>* erase(Node<T> *list, T target)
{
	Node<T> *nodePtr, *prevNode;
	if(isIn(list, target) != false)
	{
		while(isIn(list, target) != false)
		{
			if(list->value == target)//head
			{
				nodePtr = list;
				list = list->next;
				delete nodePtr;
			}

			else	
			{
				nodePtr = list;
				while(nodePtr && nodePtr->value != target)
				{
					prevNode = nodePtr;
					nodePtr = nodePtr->next;
				}
				if(nodePtr)
				{
					prevNode->next = nodePtr->next;
					delete nodePtr;
				}
			}	
		}
		return list;
	}

	else return list;

}

//display the number of elements in the list
template <typename T>
int numbElement(Node<T> *list)
{
	int count = 0;
	Node<T> *nodePtr;
	nodePtr = list;

	while(nodePtr)
	{
		nodePtr = nodePtr->next;
		count++;
	}

	return count;
}

#endif