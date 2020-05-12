#include "binarytree.h"
#include "timer.h"

#include <iostream>
#include <iomanip>

void dataCollection(int);
void BtreeDemo();

int main()
{
  BtreeDemo();

  std::cout << "\nDATA COLLECTION\n\n";
  for(int i = 1000; i <= 100000; i+= 1000)
  { 
    dataCollection(i);
    std::cout << std::endl;
  }

  std::cout << "\nEnd of Progam. Good day!\n";

  return 0;
}

void dataCollection(int n)
{
  std::cout << std::setprecision(2) << std::fixed << std::showpoint;

  BinaryTree data;
  Timer stpw; //object to record time

  //time insert
  stpw.startTime();
  for(int i = 0; i < n; i++)
    data.insert(i);
  std::cout << "Insertion of " << n << " nodes: ";
  stpw.endTime();

  //time for search
  stpw.startTime();
  for(int i = 0; i < n; i++)
    data.search_timing(i);
  std::cout << "Search of " << n << " nodes:    ";
  stpw.endTime();

  //time for deletion
  stpw.startTime();
  for(int i = 0; i < n; i++)
    data.Delete(i);
  std::cout << "Deletion of " << n << " nodes:  ";
  stpw.endTime();
}

void BtreeDemo()
{
  BinaryTree A;
  std::cout << "DEMO with BT A\n";
  
  std::cout << "\ninsert 67...\n";
  A.insert(67);
  std::cout << "Tree: ";
  A.inorder();

  std::cout << "\ninsert 91...\n";
  A.insert(91);
  std::cout << "Tree: ";
  A.inorder();

  std::cout << "\ninsert 18...\n";
  A.insert(18);
  std::cout << "Tree: ";
  A.inorder();

  std::cout << "\ninsert 87 76 6 20 30...\n";
  A.insert(87);
  A.insert(76);
  A.insert(6);
  A.insert(20);
  A.insert(30);
  std::cout << "Tree: ";
  A.inorder();

  std::cout << "\ndelete 67...\n";
  A.Delete(67);
  std::cout << "Tree: ";
  A.inorder();

  std::cout << "\ndelete 6 91...\n";
  A.Delete(6);
  A.Delete(91);
  std::cout << "Tree: ";
  A.inorder();

  std::cout << "\ndelete 69...\n";
  A.Delete(69);
  std::cout << "Tree: ";
  A.inorder();

  std::cout << "\ninsert 3 9 105...\n";
  A.insert(3);
  A.insert(9);
  A.insert(105);
  std::cout << "Tree: ";
  A.inorder();

  std::cout << "\nSearch for 3...\n";
  A.search(3);

  std::cout << "\nSearch for 87...\n";
  A.search(87);

  std::cout << "\nSearch for 67...\n";
  A.search(67);

  std::cout << "\nsmallest node...\n";
  std::cout << "    --> " << A.minimum() << std::endl;

  std::cout << "\nbiggest node...\n";
  std::cout << "    ---> " << A.maximum() << std::endl;

  std::cout << "\nFor this next part: \n  -1 denotes not in tree.\n";
  std::cout << "  -2 denotes no successor.\n\n";
  
  std::cout << "Tree: ";
  A.inorder();

  std::cout << "\nsuccessor of 3";
  std::cout << "    --> " << A.successor(3) << std::endl;

  std::cout << "successor of 105";
  std::cout << "  --> " << A.successor(105) << std::endl;

  std::cout << "successor of 200";
  std::cout << "  --> " << A.successor(200) << std::endl;

  std::cout << "successor of 87";
  std::cout << "   --> " << A.successor(87) << std::endl;

  std::cout << "\nOther print:\n";
  std::cout << "Descending : ";
  A.print();

  std::cout << "\nEND OF THE DEMO\nPress <enter> to continue";
  std::cin.ignore();
}
