/*
	Florent Dondjeu Tschoufack
	Cosc320 - 002
	lab 11
	Apr 29, 2020
	main.cpp
*/

#include "graph.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "Need at least two arguments\n";
		exit(1);
	}

	std::ifstream infile;
	infile.open(argv[1]);
	Graph myGraph0(true);

	if(infile.tellg() == 0)
	{
		int u;
		
		while(!infile.eof())
		{
			infile >> u;
			myGraph0.addVertex(u);
		}
	}

	std::cout << "Graph from file input\n";
	myGraph0.print();

	Graph myGraph(false);	//undirected
	std::cout << "\n======================================================\n";
	std::cout << "UNDIRECTED Graph Demo: {vertex: adjecent vertices}\n\n";

	std::cout << "add vertex 1\n";
	myGraph.addVertex(1);
	myGraph.print();

	std::cout << "\nadd vertex 2 3 4 5 6\n";
	myGraph.addVertex(2);
	myGraph.addVertex(3);
	myGraph.addVertex(4);
	myGraph.addVertex(5);
	myGraph.addVertex(6);
	myGraph.print();

	std::cout << "\nadd edge 3 to 4\n";
	myGraph.addEdge(3,4);
	myGraph.print();

	std::cout << "\nadd edge 2 to 6\n";
	myGraph.addEdge(2,6);
	myGraph.print();

	std::cout << "\nadd edge 4 to 5\n";
	myGraph.addEdge(4,5);
	myGraph.print();

	std::cout << "\nadd edge 6 to 3\n";
	myGraph.addEdge(6,3);
	myGraph.print();

	myGraph.printBfs(2);

	myGraph.printDfs(true);

	std::cout << "\nTopological sort attemp:\n";
	myGraph.topoSort();

	myGraph.strongConnect();

	std::cout << "\n======================================================\n";

	Graph myGraph2(true);	//directed
	std::cout << "DIRECTED Graph Demo: {vertex: adjecent vertices}\n\n";

	std::cout << "add vertex 1 to 8 excluding 7\n";
	myGraph2.addVertex(1);
	myGraph2.addVertex(2);
	myGraph2.addVertex(3);
	myGraph2.addVertex(4);
	myGraph2.addVertex(5);
	myGraph2.addVertex(6);
	myGraph2.addVertex(8);
	myGraph2.print();

	std::cout << "\nadd edge 1 to 2\n";
	myGraph2.addEdge(1,2);
	myGraph2.print();

	std::cout << "\nadd edge 1 to 3\n";
	myGraph2.addEdge(1,3);
	myGraph2.print();

	std::cout << "\nadd edge 2 to 4 *\n";
	myGraph2.addEdge(2,4);
	myGraph2.print();

	std::cout << "\nadd edge 4 to 2 *\n";
	myGraph2.addEdge(4,2);
	myGraph2.print();

	std::cout << "\nadd edge 2 to 5\n";
	myGraph2.addEdge(2,5);
	myGraph2.print();

	std::cout << "\nadd edge 3 to 6\n";
	myGraph2.addEdge(3,6);
	myGraph2.print();

	std::cout << "\nadd edge 6 to 8 *\n";
	myGraph2.addEdge(6,8);
	myGraph2.print();

	std::cout << "\nadd edge 8 to 6 *\n";
	myGraph2.addEdge(8,6);
	myGraph2.print();

	myGraph2.printBfs(1);

	myGraph2.printDfs(true);

	myGraph2.topoSort();
	myGraph2.strongConnect();

	return 0;
}