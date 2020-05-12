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
#include <algorithm>
#include <iostream>

//WHITE -- non visited vertices
//GRAY  -- visited vertex excluding its adjacent vertices
//BLACK -- visited vertex and its adjacent vertices
enum color_t {WHITE, GRAY, BLACK};

class Graph
{
	private:

		std::map<int, std::vector<int> > vertices;

		std::map<int,color_t> colors;
		std::map<int,int> distance;
		std::map<int,int> parents;
		std::map<int,int> finish;

		bool isDirected, aCyclic;

		int time;

		//private function to print content of a vector
		void printVect(std::vector<int>);

		//walks the graph whiles doing dfs
		void Dfs_visit(int);

		void strongConnect_visit(int, Graph&);

	public:

		Graph(bool);

		~Graph();

		//add a vertex to the graph
		void addVertex(int);

		//add an undirected edge to the graph
		void addEdge(int,int);

		//prints the adjacency list of each vertex, to show the structure
		void print();

		//prints the vertices discovered by BFS, starting at a given vertex
		void printBfs(int);

		//prints the vertices discored by DFS, if true data is outputed
		void printDfs(bool);

		//prints a valid topological ordering, if one exists
		void topoSort();

		//prints each fully connected component of the graph using DFS
		void strongConnect();
};

#endif