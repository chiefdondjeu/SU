#ifndef DNODE_H
#define DNODE_H

template <typename T>
class dNode
{
	public:
		T value;
		dNode<T> *left;
		dNode<T> *right;

		dNode()
		{
			left = this;
			right = this;
		}

		dNode(const T& val): value(val)
		{
			left = this;
			right = this;
		}

};

#endif