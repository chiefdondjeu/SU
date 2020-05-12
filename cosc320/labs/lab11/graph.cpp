/*
	Florent Dondjeu Tschoufack
	COSC 320 - 002
	Lab 10
	graph.cpp
	Apr 17, 2020
*/

#include "graph.h"

Graph::Graph(bool a)
{
	isDirected = aCyclic = a; //if true, graph is directed otherwise undirected.
}

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
	//else std::cout << "Vertex already exist\n";
}

//add an edge to the graph
void Graph::addEdge(int v, int u)
{
	if(v == u)
		return;

	//undirected
	if(isDirected == false)
	{
		//if v exist
		if(vertices.find(v) != vertices.end())
		{
			vertices[v].push_back(u);	//add edge v -> u

			if(vertices.find(u) == vertices.end())	//if u doesn't exist
			{
				std::vector<int> vect;
				vect.push_back(v);
				vertices[u] = vect;
			}
			else vertices[u].push_back(v); //add edge u -> v
		}
		//if v doesn't exist
		else if(vertices.find(v) == vertices.end())
		{
			std::vector<int> vect1;
			vect1.push_back(u);
			vertices[v] = vect1; // v-> u
			if(vertices.find(u) == vertices.end())
			{
				std::vector<int> vect2;
				vect2.push_back(v);
				vertices[u] = vect2;	// u -> v
			}
			else vertices[u].push_back(v);
		}
	}

	//directed
	else if(isDirected == true)
	{
		//if v exist
		if(vertices.find(v) != vertices.end() && v != u)
		{
			vertices[v].push_back(u);	//add edge v -> u
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

	std::map<int, std::vector<int> >::iterator iter;
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
		std::cout << "\nBreadth-first search for " << s << ":\n";
		std::cout << s << " is not a vertex!\n";
		return;
	}

	std::map<int, std::vector<int> >::iterator iter;
	for(iter = vertices.begin(); iter != vertices.end(); iter++)
	{
		colors.insert(std::pair<int,color_t>(iter->first,WHITE));
		distance.insert(std::pair<int,int>(iter->first,9999));
		parents.insert(std::pair<int,int>(iter->first,9999));
	}

	std::queue<int> Q;

	colors[s] = GRAY;
	distance[s] = 0;
	parents[s] = 9999;

	int u,v;

	Q.push(s);
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		std::vector<int>::iterator it;
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

	std::cout << "\nBreadth-first search for " << s << ": {vertex: color, distance, parent}\n";

	std::map<int,color_t>::iterator C = colors.begin();
	std::map<int,int>::iterator D = distance.begin();
	std::map<int,int>::iterator P = parents.begin();

	for(; C != colors.end(); C++,D++,P++)
	{
		std::cout << "{ " << C->first << ": ";
		
		//colors
		if(C->second == WHITE)
			std::cout << "WHITE, ";
		else if(C->second == GRAY)
			std::cout << "GRAY, ";
		else std::cout << "BLACK, ";

		//distance
		if(D->second == 9999)
			std::cout << "nil, ";
		else std::cout << D->second << ", ";

		//parents
		if(P->second == 9999)
			std::cout << "nil } ";
		else std::cout << P->second << " } ";
	}
	std::cout << std::endl;

	colors.clear();
	distance.clear();
	parents.clear();
}

//walks the graph whiles doing dfs
void Graph::Dfs_visit(int u)
{
	time++;
	distance[u] = time;
	colors[u] = GRAY;

	std::vector<int>::iterator it;
	for(it = vertices[u].begin(); it != vertices[u].end(); it++)
	{
		if(colors[*it] == GRAY)
			aCyclic = false;

		if(colors[*it] == WHITE)
		{
			parents[*it] = u;
			Dfs_visit(*it);
		}
	}
	colors[u] = BLACK;
	time++;
	finish[u] = time;
}

//prints the vertices discored by DFS, if true data is outputed
void Graph::printDfs(bool output)
{
	std::map<int, std::vector<int> >::iterator iter;
	for(iter = vertices.begin(); iter != vertices.end(); iter++)
	{
		colors.insert(std::pair<int,color_t>(iter->first,WHITE));
		distance.insert(std::pair<int,int>(iter->first,9999));
		parents.insert(std::pair<int,int>(iter->first,9999));
		finish.insert(std::pair<int,int>(iter->first,9999));
	}

	time = 0;

	std::map<int, std::vector<int> >::iterator iter2;
	for(iter2 = vertices.begin(); iter2!= vertices.end(); iter2++)
	{
		if(colors[iter2->first] == WHITE)
			Dfs_visit(iter2->first);
	}

	if(output)
	{
		std::cout << "\nDepth-first search: {vertex: color, distance, time, parent}\n";

		std::map<int,color_t>::iterator C = colors.begin();
		std::map<int,int>::iterator D = distance.begin();
		std::map<int,int>::iterator P = parents.begin();
		std::map<int,int>::iterator F = finish.begin();

		for(; C != colors.end(); C++,D++,P++,F++)
		{
			std::cout << "{ " << C->first << ": ";
			
			//colors
			if(C->second == WHITE)
				std::cout << "WHITE, ";
			else if(C->second == GRAY)
				std::cout << "GRAY, ";
			else std::cout << "BLACK, ";

			//distance
			if(D->second == 9999)
				std::cout << "nil, ";
			else std::cout << D->second << ", ";

			//time
			if(F->second == 9999)
				std::cout << "nil, ";
			else std::cout << F->second << ", ";

			//parents
			if(P->second == 9999)
				std::cout << "nil } ";
			else std::cout << P->second << " } ";
		}
		std::cout << std::endl;
	}

	colors.clear();
	distance.clear();
	parents.clear();
}

//prints a valid topological ordering, if one exists
void Graph::topoSort()
{
	finish.clear();
	printDfs(false);

	if(!isDirected && !aCyclic)
	{
		std::cout << "Error! Graph is not a DAG.\n";
		return;
	}

	std::vector<std::pair<int,int> > vect;

	std::map<int,int>::iterator F;
	for(F = finish.begin(); F != finish.end(); F++)
		vect.push_back(std::pair<int,int>(F->second, F->first));

	std::sort(vect.begin(),vect.end());

	std::cout << "\nTopological sort: {vertex: finish time}\n";
	std::vector<std::pair<int,int> >::iterator it;
	for(it = vect.end()-1; it != vect.begin()-1; it--)
		std::cout << "{ " << it->second << ": " << it->first << " } ";
	std::cout << std::endl;
}

//
void Graph::strongConnect_visit(int u, Graph& temp)
{
	temp.colors[u] = GRAY;
	std::vector<int>::iterator it;
	for(it = temp.vertices[u].begin(); it != temp.vertices[u].end(); it++)
	{
		if(temp.colors[*it] == WHITE)
			strongConnect_visit(*it,temp);
	}

	temp.colors[u] = BLACK;
	std::cout << u << " ";
}

//prints each fully connected component of the graph using DFS
void Graph::strongConnect()
{
	finish.clear();
	printDfs(false);

	Graph temp(isDirected);

	//add vertex
	std::map<int, std::vector<int> >::iterator iter;
	for(iter = vertices.begin(); iter != vertices.end(); iter++)
		temp.addVertex(iter->first);

	//add edges
	std::map<int, std::vector<int> >::iterator iter2;
	std::vector<int>::iterator it;
	for(iter2 = vertices.begin(); iter2 != vertices.end(); iter2++)
	{
		for(it = iter2->second.begin(); it != iter2->second.end(); it++)
			temp.addEdge(*it,iter2->first);
	}

	std::vector<std::pair<int,int> > vect;

	std::map<int,int>::iterator F;
	for(F = finish.begin(); F != finish.end(); F++)
		vect.push_back(std::pair<int,int>(F->second, F->first));

	std::sort(vect.begin(),vect.end());
	//std::reverse(vect.begin(),vect.end());

	//DFS
	temp.colors.clear();
	std::vector<std::pair<int,int> >::iterator it2;
	for(it2 = vect.end()-1; it2 != vect.begin()-1; it2--)
		temp.colors.insert(std::pair<int,color_t>(it2->second,WHITE));

	std::cout << "\nStrong Connect: ";

	std::vector<std::pair<int,int> >::iterator it3;
	for(it3 = vect.end()-1; it3 != vect.begin()-1; it3--)
	{
		if(temp.colors[it3->second] == WHITE)
		{
			std::cout << "{ ";
			strongConnect_visit(it3->second,temp);
			std::cout << "} ";
		}
	}
	std::cout << std::endl;
	//temp.print();
}