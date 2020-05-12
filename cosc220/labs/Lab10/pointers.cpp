/*
  Pointers.cpp
  COSC-220 Lab 9
*/

#include <iostream>
#include <stddef.h>     // for NULL definition

int main()
{
  using namespace std;

  int int1 = 1, int2 = 2, int3 = 3;
  double dub1 = 1.0, dub2 = 2.0, dub3 = 3.0;
  float flt1 = 1.0f;
  char chr1 = 'a', chr2 = 'b';

  //////////////////////////////////////////////////////////////////	
  // 1. Experiment with storage sizes and addresses of various data
  // types.
  //////////////////////////////////////////////////////////////////	
  //  A.  Add statements to print the addresses of each of the 9
  //  variables declared above and record the addresses. 
  //  B.  Add statements to print the sizes (in bytes) of each of the
  //  9 variables  (use the sizeof operator).
  //  C.  Add statements to print the sizes of the addresses of the 9
  //  variables (again, use the sizeof operator).
	
  //  Write your code here:
  std :: cout << "Var  \tSize\tAddress\t\tAddress-Size" << std :: endl;
  std :: cout << "int1\t" << sizeof(int1) << "\t" << &int1 << "\t" << sizeof(&int1) << std :: endl;
  std :: cout << "int2\t" << sizeof(int2) << "\t" << &int2 << "\t" << sizeof(&int2) << std :: endl;
  std :: cout << "int3\t" << sizeof(int3) << "\t" << &int3 << "\t" << sizeof(&int3) << std :: endl;
  std :: cout << "dub1\t" << sizeof(dub1) << "\t" << &dub1 << "\t" << sizeof(&dub1) << std :: endl;
  std :: cout << "dub2\t" << sizeof(dub2) << "\t" << &dub2 << "\t" << sizeof(&dub2) << std :: endl;
  std :: cout << "dub3\t" << sizeof(dub3) << "\t" << &dub3 << "\t" << sizeof(&dub3) << std :: endl;
  std :: cout << "flt1\t" << sizeof(flt1) << "\t" << &flt1 << "\t" << sizeof(&flt1) << std :: endl;
  std :: cout << "chr1\t" << sizeof(chr1) << "\t" << &chr1 << "\t\t" << sizeof(&chr1) << std :: endl;
  std :: cout << "chr2\t" << sizeof(chr2) << "\t" << &chr2 << "\t\t" << sizeof(&chr2) << std :: endl;

  cout << "-----------------------------------------" << endl << endl;

  // Record your results here:
  //  
  //  Variable  Size    Address           Address-Size
  //   int1     4       0x7ffee47f2b04    8
  //   int2     4       0x7ffee47f2b00    8
  //   int3     4       0x7ffee47f2afc    8
  //   dub1     8       0x7ffee47f2af0    8
  //   dub2     8       0x7ffee47f2ae8    8
  //   dub3     8       0x7ffee47f2ae0    8
  //   flt1     4       0x7ffee47f2adc    8
  //   chr1     1       a                 8
  //   chr2     1       ba                8

  // How many bytes of storage is allocated for each data type?  How
  // many bytes is allocated for each pointer (address). Notice that
  // the data types are not necessarily the same size, but the
  // pointers are.
  // 
  // Did the address of the char variables print as you expected?  If
  // not, why not?   You can force the printed output to be
  // interpreted as a pointer by coercing it (casting) to void* like
  // this:
  //    cout << (void *) &chr1;
  //
  // Run the program again, using the coercion for the char
  // pointers. Record your data.

  // Write your modified code here:
  std :: cout << "Var  \tSize\tAddress\t\tAddress-Size" << std :: endl;
  std :: cout << "chr1\t" << sizeof(chr1) << "\t" << (void *) &chr1 << "\t" << sizeof(&chr1) << std :: endl;
  std :: cout << "chr2\t" << sizeof(chr2) << "\t" << (void *) &chr2 << "\t" << sizeof(&chr2) << std :: endl;

  cout << "-----------------------------------------" << endl << endl;


  // Record your results here:
  //  
  //  Variable  Size   Address          Address-Size
  //     chr1   1      0x7ffeef1d5b23   8
  //     chr2   1      0x7ffeef1d5b22   8

  //////////////////////////////////////////////////////////////////	
  // 2. Experiment with pointer variables.
  //////////////////////////////////////////////////////////////////	
  //   A. Declare pointer vaiables intPtr1, intPtr2, intPtr3, dubPtr1,
  //   dubPtr2, dubPtr3, fltPtr1, chrPtr1, and chrPtr2 so that they
  //   can be used to point to the  appropriate variables.  Assign the
  //   address of the appropriate variable to them and print their
  //   values.  (The char pointers will have to be coerced as before
  //   for printing).

  //  Write your code here:
	int *intPtr1 = &int1, *intPtr2 = &int2, *intPtr3 = &int3;
  double *dubPtr1 = &dub1, *dubPtr2 = &dub2, *dubPtr3 = &dub3;
  float *fltPtr1 = &flt1;
  char *chrPtr1 = &chr1, *chrPtr2 = &chr2;

  std :: cout << "Pointer \tPrinted" << std :: endl;
  std :: cout << "intPtr1\t\t" << intPtr1 << std :: endl;
  std :: cout << "intPtr2\t\t" << intPtr2 << std :: endl;
  std :: cout << "intPtr3\t\t" << intPtr3 << std :: endl;
  std :: cout << "dubPtr1\t\t" << dubPtr1 << std :: endl;
  std :: cout << "dubPtr2\t\t" << dubPtr2 << std :: endl;
  std :: cout << "dubPtr3\t\t" << dubPtr3 << std :: endl;
  std :: cout << "fltPtr1\t\t" << fltPtr1 << std :: endl;
  std :: cout << "chrPtr1\t\t" << (void*) chrPtr1 << std :: endl;
  std :: cout << "chrPtr2\t\t" << (void*) chrPtr2 << std :: endl;

  cout << "-----------------------------------------" << endl << endl;

  //  Report your results here:
  // 
  //  Pointer  Printed
  //  intPtr1  0x7ffee47f2b04
  //  intPtr2  0x7ffee47f2b00
  //  intPtr3  0x7ffee47f2afc
  //  dubPtr1  0x7ffee47f2af0
  //  dubPtr2  0x7ffee47f2ae8
  //  dubPtr3  0x7ffee47f2ae0
  //  fltPtr1  0x7ffee47f2adc
  //  chrPtr1  0x7ffee47f2adb
  //  chrPtr2  0x7ffee47f2ada 

  // How do the values of the pointers compare to the values of the
  // addresses you got in the previous experiment?

  // They are different because the address changes each time
  // the file compiles.
  //
  //

  //////////////////////////////////////////////////////////////////	
  //  3. Experiments with NULL pointers and with dereferencing
  //////////////////////////////////////////////////////////////////	
  //   A. Assign NULL to fltPtr1, then print the value of fltPtr1.
  //   B. Accessing the storage locations through the relevant
  //   pointers, assign the following values and print them.
  //       int1  12
  //       int2  22
  //       dub1  10.1
  //       dub2  20.2
  //       flt1  30.3

  // Write your code here:
  fltPtr1 = NULL;
  std :: cout << "fltPtr1\t" << fltPtr1 << std :: endl;

  *intPtr1 = 12; *intPtr2 = 22;
  *dubPtr1 = 10.1; *dubPtr2 = 22.2;
  //*fltPtr1 = 30.3;

  std :: cout << "int1\t" << int1 << std :: endl;
  std :: cout << "int2\t" << int2 << std :: endl;
  std :: cout << "dub1\t" << dub1 << std :: endl;
  std :: cout << "dub2\t" << dub2 << std :: endl;
  //std :: cout << "flt1\t" << flt1 << std :: endl;

  // Your program should have terminated with a run-time error.
  // What error was reported?
  // segmentation fault error
  //
  // Why did it occur?
  // because fltPtr1 was not pointing to flt1
  // 

  //   C.  Fix the problem and repeat.

  // Write your code here:
  fltPtr1 = &flt1;
  *fltPtr1 = 30.3;
  std :: cout << "flt1\t" << flt1 << std :: endl;

  cout << "-----------------------------------------" << endl << endl;

  //////////////////////////////////////////////////////////////////	
  //  4. Experiments with pointer arithmetic
  //////////////////////////////////////////////////////////////////	
  //    A.  Print the values of intPtr2, (intPtr2+1) and
  //    (intPtr2-1). Did you get what you expected? 

  // Write your code here:
	std :: cout << "intPtr2\t\t" << *intPtr2 << std :: endl;
  std :: cout << "(intPtr2+1)\t" << *(intPtr2+1) << std :: endl;
  std :: cout << "(intPtr2-1)\t" << *(intPtr2-1) << std :: endl;

  // Write your explanation here:
  //  The address the pointer is pointing at is changed because
  //  of the +1 or -1 which is why a different value is printed
  //  when dereferenced
  //
  //
  //


  //   B. Print the value of intPtr1.
  //   C. Use the increment operator to increment intPtr1. 
  //   D. Print the value of intPtr1 again.  
  //   E. Print the value of the memory location pointed to by
  //   intPtr1.  Explain what is happening.
	
  // Write your code here:
  std :: cout << "intPtr1\t\t" << *intPtr1 << std :: endl;
  (intPtr1+1);
  std :: cout << "intPtr1\t\t" << *intPtr1 << std :: endl;
  std :: cout << "intPtr1\t\t" << intPtr1 << std :: endl;

  // Write your explanation here.
  //  the pointer is still pointing at int1 but it is temporarily
  //  pointing at another value when doing the pointer
  //  arithmetic
  //

  cout << "-----------------------------------------" << endl << endl;


  //////////////////////////////////////////////////////////////////	
  //  5. Experiments with dynamic allocation
  //////////////////////////////////////////////////////////////////	
  //   A.  Use the new operator to dynamically allocate an integer.
  //   B.  Assign the number 6000 to the new location.
  //   C.  Print the address of this new location.
  //   D.  Print the value stored in the new location.
  //   E.  Comment on the address of the new location compared to the
  //   addresses seen in part 2.

  //  Write your code here:
  int *intPtr4;
  intPtr4 = new int;
  *intPtr4 = 6000;
  std :: cout << "intPtr4\t" << intPtr4 << std :: endl;
  std :: cout << "\t" << *intPtr4 << std :: endl;

  
  //  Write your results and comments here:
  //  
  //  new location address = 0x7fe521c02a70
  //  contents of new location = 6000

  //  Comment: the address is 0x7fe instead of 0x7ffee
  //            like the other addresses

  //  F.  Use the new operator to allocate an array of size 10 of
  //  doubles.  Fill the array with 10.0,20.0,...100.0 and print the array.

  // Write your code here:
  double *arrayPtr;
  arrayPtr = new double[10];
  for(int i = 0; i < 10; i++)
    arrayPtr[i] = 10.0*(i+1.0);

  for(int i = 0; i < 10; i++)
    std :: cout << arrayPtr[i] << " ";
  std :: cout << std :: endl;

  return 0;
}