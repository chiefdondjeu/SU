/*
	Florent Dondjeu Tschoufack
	COSC 320 - 002
	Lab 10
	graph.h
	Apr 17, 2020
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>
#include <map>
#include <iostream>

//WHITE -- non visited vertices
//GRAY  -- visited vertex excluding its adjacent vertices
//BLACK -- visited vertex and its adjacent vertices
enum color_t {WHITE, GRAY, BLACK};

class Graph
{
	private:

		std::map<int, std::vector<int> > vertices;
		std::map<int, std::vector<int> >::iterator iter;

		//vector iterator
		std::vector<int>::iterator it;

		//private function to search an element in a vector
		bool isPresent(std::vector<int>, int);

		//private function to print content of a vector
		void printVect(std::vector<int>);

	public:

		Graph();

		~Graph();

		//add a vertex to the graph
		void addVertex(int);

		//add an undirected edge to the graph
		void addEdge(int,int);

		//prints the adjacency list of each vertex, to show the structure
		void print();

		//prints the vertices discovered by BFS, starting at a given vertex
		void printBfs(int);
};

#endif