
/*
 *d_dnode.h
 *double link-list class
 *Author: Florent Dondjeu Tschoufack
 *Created: November 29, 2019
 *Current: November 29, 2019
 */
#ifndef DNODE_H
#define DNODE_H

template <typename T>
class dNode
{
public:
	T value;
	dNode<T>* prev;
	dNode<T>* next;

	//dNode
	//default constructor
	//parameter: none
	//returns: none
	//precondition: none
	//postcondition: the pointers are initialized
	dNode()
	{
		prev = this;
		next = this;
	}

	//dNode
	//constructor
	//parameter: none
	//returns: none
	//precondition: none
	//postcondition: value and pointers are initialized
	dNode(const T& val) : value(val)
	{
		prev = this;
		next = this;
	}

};

#endif