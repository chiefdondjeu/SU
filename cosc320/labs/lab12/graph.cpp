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

			E.push_back(std::pair<int,int>(v,u));
			E.push_back(std::pair<int,int>(u,v));
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

			E.push_back(std::pair<int,int>(v,u));
			E.push_back(std::pair<int,int>(u,v));
		}
	}

	//directed
	else if(isDirected == true)
	{
		//if v exist
		if(vertices.find(v) != vertices.end() && v != u)
		{
			vertices[v].push_back(u);	//add edge v -> u
			E.push_back(std::pair<int,int>(v,u));
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

void Graph::vertexCover()
{
	std::map<int,std::vector<int> > copy = vertices;
	std::vector<int> S;

	std::map<int,bool> isCovered;
	std::map<int,std::vector<int> >::iterator iter;
	for(iter = copy.begin(); iter != copy.end(); iter++)
		isCovered.insert(std::pair<int,bool>(iter->first,false));

	std::map<int,std::vector<int> >::iterator iter2;
	for(iter2 = copy.begin(); iter2 != copy.end(); iter2++)
	{
		if(isCovered[iter2->first] == false)
		{
			std::vector<int>::iterator it;
			for(it = iter2->second.begin(); it != iter2->second.end(); it++)
			{
				if(isCovered[*it] == false)
				{
					S.push_back(*it);
					isCovered[*it] = true;
				}
			}
		}
	}

	std::cout << "Covered vertices: { ";
	printVect(S);
	std::cout << "}" << std::endl;
}

//free function
void swap(int*x , int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//free function
void array_suffle(int* A, int& n)
{
	unsigned long x,y;
	for(int i = 0; i < n; i++)
	{
		x = rand()%n;
		y = rand()%n;
		swap(&A[y],&A[x]);
	}
}

void Graph::randomVertexCover()
{
	std::map<int,std::vector<int> > copy = vertices;
	std::vector<int> S;

	std::map<int,bool> isCovered;
	std::map<int,std::vector<int> >::iterator iter;
	for(iter = copy.begin(); iter != copy.end(); iter++)
		isCovered.insert(std::pair<int,bool>(iter->first,false));

	//fill array
	int *arr = new int[copy.size()];
	int i;
	std::map<int,std::vector<int> >::iterator iter2;
	for(iter2 = copy.begin(), i = 0; iter2 != copy.end(); iter2++, i++)
		arr[i] = iter2->first;	//fill array

	int n = copy.size();
	array_suffle(arr,n);

	for(i = 0; i < copy.size(); i++)
	{
		int j = arr[i];
		if(isCovered[j] == false)
		{	
			std::vector<int>::iterator it;
			for(it = copy[j].begin(); it != copy[j].end(); it++)
			{
				if(isCovered[*it] == false)
				{
					S.push_back(*it);
					isCovered[*it] = true;
				}
			}
		}
	}
	
	delete [] arr;

	std::cout << "Random Covered vertices: { ";
	printVect(S);
	std::cout << "}" << std::endl;	
}

bool Graph::isCoveredCheck(std::vector<int>& vect)
{
	for(std::vector<std::pair<int,int> >::iterator it = E.begin(); it != E.end(); it++)
	{
		bool covered = false;
		for(std::vector<int>::iterator it2 = vect.begin(); it2 != vect.end(); it2++)
		{
			if(it->first == *it2 || it->second == *it2)
				covered = true;
		}
		if(!covered)
			return false;
	}
	return true;
}

void Graph::combinations(std::vector<std::vector<int> >& S, std::vector<int>& tmp, int n, int k, int* V, int index)
{
	if(k == 0)
	{
		S.push_back(tmp);
		return;
	}

	for(int i = index; i <= n; i++)
	{
		tmp.push_back(V[i]);
		combinations(S,tmp,n,k-1,V,i+1);
		tmp.pop_back();
	}
}

void Graph::minVertexCover()
{
	std::vector<int> tmp;
	std::vector<std::vector<int> > S;

	int n = vertices.size();
	int *V = new int[n+1];

	int i;
	std::map<int,std::vector<int> >::iterator iter2;
	for(iter2 = vertices.begin(), i = 1; iter2 != vertices.end(); iter2++, i++)
		V[i] = iter2->first;	//fill array

	//all possible vertex corvers
	for(int k = 1; k < vertices.size()-1; k++)
		combinations(S,tmp,n,k,V,1);

	//check vertex covers
	int index = S.size()-1;
	for(int i = 0; i < S.size(); i++)
	{
		if(isCoveredCheck(S.at(i)) != false)
		{
			index = i;
			break;
		}
	}

	delete [] V;

	std::cout << "Min Covered vertices: { ";
	printVect(S.at(index));
	std::cout << "}" << std::endl;
}