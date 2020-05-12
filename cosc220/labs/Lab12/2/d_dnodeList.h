#ifndef DNODELIST_H
#define DNODELIST_H

#include<iostream>

#include "d_dnode.h"

template <typename T>
void display(dNode<T> *list)
{
	dNode<T> *start = list;
	list = list->right;
	//makes it so that 0 is not printed

	while(list->right != start)
	{
		std :: cout << list->value << " ";
		list = list->right;
	}
	std :: cout << std :: endl;
}

template <typename T>
dNode<T>* add(dNode<T> *currNode, T val)
{
	if(!currNode->value)
		currNode = currNode->right;

	dNode<T> *newNode, *prevNode;

	newNode = new dNode<T>(val);

	prevNode = currNode->left;

	newNode->left = prevNode;
	newNode->right = currNode;

	prevNode->right = newNode;
	currNode->left = newNode;

	return newNode;
}

template <typename T>
dNode<T>* removeOdd(dNode<T> *currNode)
{
	if(currNode->right == currNode)
		return currNode;

	int val;
	dNode<T> *del;	//node that will be deleted
	dNode<T> *prevNode = currNode->left;
	dNode<T> *succNode = currNode->right;

	dNode<T> *start = currNode;	//to end the loop
	while(currNode->right != start)
	{
		val = currNode->value;
		if(val%2 != 0)
		{
			del = currNode;

			prevNode->right = succNode;
			succNode->left = prevNode;

			delete del;
		}

		prevNode = currNode;
		currNode = currNode->right;
		succNode = currNode->right;
	}

	return currNode;
}

#endif