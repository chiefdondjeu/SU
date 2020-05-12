/*
	Florent Dondjeu Tschoufack
	COSC 320 - 002
	Lab 10
	graph.cpp
	Apr 17, 2020
*/

#include "graph.h"

Graph::Graph()
{}

Graph::~Graph()
{}

//add a vertex to the graph
void Graph::addVertex(int v)
{
	if(vertices.find(v) == vertices.end()) //if v doesn't exist
	{
		std::vector<int> vect;
		vertices[v] = vect;
	}
	else std::cout << "Vertex already exist\n";
}

//private function to search an element in a vector
bool Graph::isPresent(std::vector<int> vect, int k)
{
	for(it = vect.begin(); it!=vect.end(); it++)
		if(*it == k) break;

	if(it != vect.end())	//if found
		return true;
	else return false;
}

//add an undirected edge to the graph
void Graph::addEdge(int v, int u)
{
	//if v exist
	if(vertices.find(v) != vertices.end())
	{
		iter = vertices.find(v);
		if(!isPresent(iter->second,u))	//if edge wasn't present
			vertices[v].push_back(u);	//add edge v -> u

		if(vertices.find(u) == vertices.end())	//if u doesn't exist
		{
			std::vector<int> vect;
			vect.push_back(v);
			vertices[u] = vect;
		}
		else
		{
			iter = vertices.find(u);
			if(!isPresent(iter->second,v))
				vertices[u].push_back(v);
		}
	}

	//if v doesn't exist
	else if(vertices.find(v) == vertices.end())
	{
		std::vector<int> vect1;
		vect1.push_back(u);
		vertices[v] = vect1;
		if(vertices.find(u) == vertices.end())
		{
			std::vector<int> vect2;
			vect2.push_back(v);
			vertices[u] = vect2;
		}
		else
		{
			iter = vertices.find(u);
			if(!isPresent(iter->second,v))
				vertices[u].push_back(v);
		}
	}
}

//private function to print content of a vector
void Graph::printVect(std::vector<int> vect)
{
	for(int i = 0; i < vect.size(); i++)
		std::cout << vect.at(i) << " ";
}

//prints the adjacency list of each vertex, to show the structure
void Graph::print()
{
	std::cout << "Adjacency list: ";

	for(iter = vertices.begin(); iter!=vertices.end(); iter++)
	{
		std::cout << "{ " << iter->first << ": "; 
		printVect(iter->second);
		std::cout << "} ";
	}
	std::cout << std::endl;
}

//prints the vertices discovered by BFS, starting at a given vertex
void Graph::printBfs(int s)
{
	if(vertices.find(s) == vertices.end()) //if s doesn't exist
	{
		std::cout << s << " is not a vertex!\n";
		return;
	}

	std::map<int,color_t> colors;
	std::map<int,int> distance;
	std::map<int,int> parents;

	for(iter = vertices.begin(); iter != vertices.end(); iter++)
	{
		colors.insert(std::pair<int,color_t>(iter->first,WHITE));
		distance.insert(std::pair<int,int>(iter->first,-1));
		parents.insert(std::pair<int,int>(iter->first,-999999));
	}

	std::queue<int> Q;

	colors[s] = GRAY;
	distance[s] = 0;
	parents[s] = -999999;

	int u,v;

	Q.push(s);
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		for(it = vertices[u].begin(); it != vertices[u].end(); it++)
		{
			v = *it;
			if(colors[v] == WHITE)
			{
				colors[v] = GRAY;
				distance[v] = distance[u]+1;
				parents[v] = u;
				Q.push(v);
			}
		}
		colors[u] = BLACK;
	}

	//RESULT
	std::map<int,color_t>::iterator C = colors.begin();
	std::map<int,int>::iterator D = distance.begin();
	std::map<int,int>::iterator P = parents.begin();

	for(; C != colors.end(); C++,D++,P++)
	{
		std::cout << "{ " << C->first << ": ";
		
		if(C->second == WHITE)
			std::cout << "WHITE, ";
		else if(C->second == GRAY)
			std::cout << "GRAY, ";
		else std::cout << "BLACK, ";

		if(D->second == -1)
			std::cout << "nil, ";
		else std::cout << D->second << ", ";

		if(P->second == -999999)
			std::cout << "nil } ";
		else std::cout << P->second << " } ";
	}
	std::cout << std::endl;
}