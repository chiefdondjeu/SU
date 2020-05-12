#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
	public:
		T value;
		Node<T> *next;

		Node():next(NULL)
		{}

		Node(const T& val, Node<T> *nextnext = NULL): 
		value(val), next(nextnext)
		{}

		~Node();

};

#endif