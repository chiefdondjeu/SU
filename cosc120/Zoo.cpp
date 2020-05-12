
// FILE:  Zoo.cpp
// IMPLEMENTATION FILE FOR CLASS Zoo


#include "Zoo.h"

// Pre: none
// Post: owner's name has been initialized to "Nobody".
//       count is set to 0.
//       cage pointer is set to NULL.
Zoo :: Zoo()
{
    owner="nobody";
    count=0;
    cage=NULL;
}

// Pre: none
// Post: owner's name has been initialized to the string you give it.
//       count is set to 0.
//       cage pointer is set to NULL.
Zoo :: Zoo( string n )
{
    owner=n;
    count=0;
    cage=NULL;
}


// Pre: none
// Post: returns owner's name
string Zoo :: name()
{
    return owner;
}


// Pre: none
// Post: Zoo Object has been initialized as an exact copy of z.
Zoo :: Zoo(const Zoo& z)
{
    owner=z.owner;
    count=z.count;
    cage=z.cage;
}

// Pre: none
// Post: Copied all animals to self. Does not change owner.
void Zoo :: operator=(const Zoo& z)
{
    count=z.count;
    cage=new string[count];
    for(int i=0; i<z.count; i++)
    {
        cage[i]=z.cage[i];
    }
}

// Pre: none
// Post: returns an object of Zoo with same owner and animals of z,
//       animal a added to the end.

Zoo operator+(const Zoo& z, string a) // FRIEND FUNCTION
{
    Zoo x;
    string *temp=new string[z.count+1];
    x.count=(z.count)+1;
    for(int i=0; i<z.count; i++)
    {
        temp[i]=z.cage[i];
    }
    x.cage=new string[x.count];
    for(int i=0; i<x.count; i++)
    {
        x.cage[i]=temp[i];
    }
    x.cage[x.count-1]=a;
    delete [] temp;
    temp=NULL;
    return x;
}


// Pre: none
// Post: prints out z's contents (animal1, animal2, etc.),
//       and returns out stream.
ostream& operator<<(ostream& out, const Zoo& z) // FRIEND FUNCTION
{
   out << z.owner << "'s" <<" Zoo " << '('<< z.count << " animals "
       << ')' << ':' <<endl;
   for (int i=0; i<z.count; i++)
   {
      out<< z.cage[i];
      out<< endl;
   }
   return out;
}


//Pre: none
//Post: the memory of cage has been released.
Zoo :: ~Zoo()
{
    delete [] cage;
    cage=NULL;
}

// Pre: none
// Post: returns true if animal a is in Zoo z.
//       the owner does not count as an animal.

bool operator<=(string a, const Zoo& z) // FRIEND FUNCTION
{
    for(int i=0; i<z.count; i++)
    {
        if(a==z.cage[i])
        {
            return true;
        }
    }
    return false;
}

//Pre:  none
//Post: returns an object of Zoo with same owner and animals of z,
//      animal a added to the end.

Zoo operator+(string a, const Zoo& z) // NONMEMBER FUNCTION
{
    Zoo x;
    x=z+a;
    return x;
}

//Pre: none
//Modifies: z (it means z's contents will be changed)
//Post: z has same animals and owner, animal a added to the end.
void operator+=(Zoo& z, string a) // NONMEMBER FUNCTION
{
    z=z+a;
}



