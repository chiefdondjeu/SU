#ifndef EX9AUX_H
#define EX9AUX_H

template <typename T>
class accumulator
{
	public:
		//accumulator();
		accumulator (const T& value = T()); //constrctor
		T getTotal() const;           //return total
		void addValue(const T& value);	// add (+) value to total
	private: 
		T total; //total accumulated by the object
};

#include "ex9Aux.cpp"
#endif