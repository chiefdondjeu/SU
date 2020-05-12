/*
	Florent Dondjeu Tschoufack
	COSC 320 - 002
	lab 12
	main.cpp
	May 4, 2020
*/

#include "graph.h"

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		std::cout << "Need three arguments!\nExisting...\n";
		exit(1);
	}

	std::ifstream infile;
	infile.open(argv[1]);

	std::string type = argv[2];

	srand(time(0));

	if(type == "dir")
	{
		Graph myGraph(true);

		if(infile.tellg() == 0)
		{
			int u, v;
			std::string line;
			while(!infile.eof())
			{
				std::getline(infile,line);
				for(int i = 0; i < line.length(); i++)
				{
					u = line[0] - 48;
					myGraph.addVertex(u);
					char cur = line[i];
					if(cur != ' ')
					{
						v = line[i] - 48;
						myGraph.addVertex(v);
						myGraph.addEdge(u,v);
					}
				}
			}
		}
		else 
		{
			std::cout << "File is empty!\nExiting...\n";
			exit(1);
		}

		std:: cout << "Legend: {vertex: adjecent vertices}\n\n";
		myGraph.print();
		myGraph.vertexCover();
		myGraph.randomVertexCover();
	}
	
	else if(type == "undir")
	{
		Graph myGraph(false);

		if(infile.tellg() == 0)
		{
			int u, v;
			std::string line;
			while(!infile.eof())
			{
				std::getline(infile,line);
				for(int i = 0; i < line.length(); i++)
				{
					u = line[0] - 48;
					myGraph.addVertex(u);
					char cur = line[i];
					if(cur != ' ')
					{
						v = line[i] - 48;
						myGraph.addVertex(v);
						myGraph.addEdge(u,v);
					}
				}
			}
		}
		else 
		{
			std::cout << "File is empty!\nExiting...\n";
			exit(1);
		}

		std:: cout << "Legend: {vertex: adjecent vertices}\n\n";
		myGraph.print();
		myGraph.vertexCover();
		myGraph.randomVertexCover();
		myGraph.minVertexCover();
	}
	else
	{
		std::cout << "Graph type undeterminable!\nExisting...\n";
		exit(1);
	}

	return 0;
}