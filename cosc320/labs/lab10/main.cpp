/*
	Florent Dondjeu Tschoufack
	COSC 320 - 002
	Lab 10
	main.cpp
	Apr 19, 2020
*/

#include "graph.h"
#include "iostream"

int main()
{
	Graph myGraph;
	std::cout << "Graph Demo: {vertex: adjecent vertices}\n";
	
	std::cout << "\nadd vertex 1\n";
	myGraph.addVertex(1);
	myGraph.print();

	std::cout << "\nadd vertex 2\n";
	myGraph.addVertex(2);
	myGraph.print();

	std::cout << "\nadd vertex 3\n";
	myGraph.addVertex(3);
	myGraph.print();

	std::cout << "\nadd vertex 2 *duplicate*\n";
	myGraph.addVertex(2);
	myGraph.print();

	std::cout << "\nadd edge 3 to 4\n";
	myGraph.addEdge(3,4);
	myGraph.print();

	std::cout << "\nadd edge 5 to 4\n";
	myGraph.addEdge(5,4);
	myGraph.print();

	std::cout << "\nadd edge 6 to 2\n";
	myGraph.addEdge(6,2);
	myGraph.print();

	std::cout << "\nadd edge 2 to 6 *duplicate*\n";
	myGraph.addEdge(2,6);
	myGraph.print();

	std::cout << "\nadd edge 6 to 3\n";
	myGraph.addEdge(6,3);
	myGraph.print();

	std::cout << "\nBreadth-first search for 2: {vertex: color, distance, parent}\n";
	myGraph.printBfs(2);

	std::cout << "\nBreadth-first search for 1:\n";
	myGraph.printBfs(1);

	std::cout << "\nBreadth-first search for 6:\n";
	myGraph.printBfs(6);

	std::cout << "\nBreadth-first search for 100:\n";
	myGraph.printBfs(100);

}