#include "lab7Aux.h"

#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
void removeDup(std::vector<T> & v)
{
  int i, j; //scan array
  int N = v.size(); //vector size
  int dups = 0; //number of duplicates

  for(i = 0; i < v.size(); i++)
  {
    for(j = i+1; j < v.size(); j++)
    {
      if(v[i] == v[j])
      {
        dups++;
        v.push_back(v[j]);
        v.erase(v.begin()+j);
          //the 2 statements above move the duplicate to the back,
          //and delete it from its original position
        break;
      }
    }
  }
  v.resize(N-dups);
}


template <typename T>
void removeDup2(std::vector<T> & v)
{
  int i, j;
  int dups = 0;
  int N = v.size();
  int first = 1, last = N;

  for(i = 0; i < last; i++)
  {
    j = seqVectSearch(v, first, last, v[i]);
    if(v[i] == v[j])
    {
      first++;
      last--;
      dups++;
      v.push_back(v[j]);
      v.erase(v.begin()+j);
    }
  }
  v.resize(N-dups);
}

template <typename T>
void removeDup3(std::vector<T> & v)
{
  std::vector<T> nonDups;  // this will store the non-duplicates

  // Sort vect using a generic STL algorithm
  std::sort(v.begin(), v.end());

  int i,j,k;
  for(i = 0; i < v.size(); i++)
  {
      if(v[i] != v[i+1])
      {
        nonDups.push_back(v[i]);
      }
  }
  v = nonDups;
}

template <typename T>
unsigned seqVectSearch(const std::vector<T> & v, unsigned first, 
		       unsigned last, const T& target)
{
  int i;
  for(i = first; i < last; i++)
  {
    if(v[i] == target)
      return i;
  }

  return last;           // return last if target not found
}

template <typename T>
void writeVector(const std::vector<T> & v)
{
  unsigned i;
  unsigned n = v.size();

  for (i = 0; i < n; i++)
    std::cout << v[i] << ' ';
  std::cout << std::endl;
}