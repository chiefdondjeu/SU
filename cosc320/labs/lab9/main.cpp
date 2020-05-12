/*
 *Florent Dondjeu Tschoufack
 *COSC 320 - 002
 *lab 9
 *main.cpp
 *Apr 15, 2020
 */

#include "RBtree.h"
#include "timer.h"

#include <iostream>

void dataCollection(int);
void RBTree_Demo();

int main()
{
  RBTree_Demo();

  std::cout << "\nDATA COLLECTION\n\n";
  for(int i = 1000; i <= 1000000; i+= 1000)
  {
    dataCollection(i);
    std::cout << std::endl;
  }
  delete RBTree::nil;

  return 0;
}

void dataCollection(int n)
{
  RBTree data;
  Timer stpw;

  stpw.startTime();
  for(int i = 0; i < n; i++)
    data.insert(i);
  std::cout << "Insertion of " << n << " nodes: " << stpw.endTime() << "s\n";

  stpw.startTime();
  for(int i = 0; i < n; i++)
    data.search_timing(i);
  std::cout << "Search of " << n << " nodes:    " << stpw.endTime() << "s\n";

  stpw.startTime();
  for(int i = 0; i < n; i++)
    data.Delete(i);
  std::cout << "Deletion of " << n << " nodes:  " << stpw.endTime() << "s\n";
}

void RBTree_Demo()
{
  RBTree A;
  std::cout << "DEMO with RBTree A\n";
  std::cout << "\nNote:\n   Red nodes are colored red\n   balck nodes are the default text color of your terminal\n";

  std::cout << "\nInsert 67\n";
  A.insert(67);
  A.inorder();

  std::cout << "\nInsert 91\n";
  A.insert(91);
  A.inorder();

  std::cout << "\nInsert 18\n";
  A.insert(18);
  A.inorder();

  std::cout << "\nInsert 87\n";
  A.insert(87);
  A.inorder();

  std::cout << "\nInsert 76\n";
  A.insert(76);
  A.inorder();

  std::cout << "\nInsert 6\n";
  A.insert(6);
  A.inorder();

  std::cout << "\nInsert 20\n";
  A.insert(20);
  A.inorder();

  std::cout << "\nInsert 30\n";
  A.insert(30);
  A.inorder();

  std::cout << "\nDelete 67\n";
  A.Delete(67);
  A.inorder();

  std::cout << "\nDelete 6\n";
  A.Delete(6);
  A.inorder();

  std::cout << "\nDelete 91\n";
  A.Delete(91);
  A.inorder();

  std::cout << "\nDelete 69\n";
  A.Delete(69);
  A.inorder();

  std::cout << "\nInsert 3\n";
  A.insert(3);
  A.inorder();

  std::cout << "\nInsert 9\n";
  A.insert(9);
  A.inorder();

  std::cout << "\nInsert 105\n";
  A.insert(105);
  A.inorder();

  std::cout << "\nSearch for 3\n";
  A.search(3);

  std::cout << "\nSearch for 87\n";
  A.search(87);

  std::cout << "\nSearch for 67\n";
  A.search(67);

  std::cout << "\nSmallest node\n";
  std::cout << "    --> " << A.minimum() << std::endl;

  std::cout << "\nBiggest node\n";
  std::cout << "    ---> " << A.maximum() << std::endl;

  std::cout << "\nFor this next part: \n  -1 denotes not in tree.\n";
  std::cout << "  -2 denotes no successor.\n\n";

  A.inorder();

  std::cout << "\nSuccessor of 3";
  std::cout << "    --> " << A.successor(3) << std::endl;

  std::cout << "Successor of 105";
  std::cout << "  --> " << A.successor(105) << std::endl;

  std::cout << "Successor of 200";
  std::cout << "  --> " << A.successor(200) << std::endl;

  std::cout << "Successor of 87";
  std::cout << "   --> " << A.successor(87) << std::endl;

  std::cout << "\nOther print:\n";
  A.print();

  std::cout << "\nEND OF THE DEMO\nPress <enter> to continue";
  std::cin.ignore();
}
