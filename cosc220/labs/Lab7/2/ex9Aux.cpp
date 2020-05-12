#include "ex9Aux.h"

template <typename T>
accumulator<T> :: accumulator (const T& value): total(value)
{}

template <typename T>
T accumulator<T> :: getTotal() const
{
	return total;
}

template <typename T>
void accumulator<T> :: addValue(const T& value)
{
	total += value;
}