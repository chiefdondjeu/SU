Florent Dondjeu Tschoufack
COSC 320
Lab3
Feb 19,2020
(a) In order to  use my code you first need to create a dynamically allocated object of type Heap, then also dynamically allocate the array that will hold your data. From there, you just pass in the object in the function HeapSort(). Heapsort() will first put the elements in the array into an Heap, looking at it like a binary tree, the parent node is always greater than its children as you go down any path in the binary tree. After the array has been put into a heap, it is then sorted. Then the timer elapsed for how long the sort took is printed out along with the number of swaps.

(b) Looking strictly at the graph, one could say that the best case is O(n) and the worst case is O(nlogn).

(d) As the number of elements increase, the sorting time also increases, but unlike the other sorts, Heap relies on the element of the array being put into a heap, so as the size of elements increases the time it takes to sort also increases. As n grows the timing mostly resembles a linear time O(n) unlike the other 5 sorts who looked closely to a quadratic time O(n^2).

(f) You would expect a sorted array (best case) to be faster than a backward sorted array (worst case) , but for heap that was not the case. Sorting in ascending order, my worst case, elements in descending order, was sorted faster then my best case, elements in ascending order, and my average case, when the elements position was randomized fell in the middle of the two.

(g) My code could be improve by utilizing the PrintMaxHeap() so that the user could select the array in a heap, and how the heap looks like depending on which section of the tree he or she chose to select i.e parent node and how far down
