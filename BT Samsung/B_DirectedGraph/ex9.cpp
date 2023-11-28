#include<iostream>
#include <list>
#define CHARS 26
using namespace std;


class Graph
{
	int V;
	list<int> *adj;
	int *in;
public:
	Graph(int V);
	~Graph() { delete [] adj; delete [] in; }

	void addEdge(int v, int w) { adj[v].push_back(w); (in[w])++; }

	bool isEulerianCycle();

	bool isSC();

	void DFSUtil(int v, bool visited[]);

	Graph getTranspose();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
	in = new int[V];
	for (int i = 0; i < V; i++)
	in[i] = 0;
}

bool Graph::isEulerianCycle()
{
	if (isSC() == false)
		return false;

	for (int i = 0; i < V; i++)
		if (adj[i].size() != in[i])
			return false;

	return true;
}

void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

Graph Graph::getTranspose()
{
	Graph g(V);
	for (int v = 0; v < V; v++)
	{
		list<int>::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			g.adj[*i].push_back(v);
			(g.in[v])++;
		}
	}
	return g;
}

bool Graph::isSC()
{
	bool visited[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	int n;
	for (n = 0; n < V; n++)
		if (adj[n].size() > 0)
		break;

	DFSUtil(n, visited);

	for (int i = 0; i < V; i++)
		if (adj[i].size() > 0 && visited[i] == false)
			return false;

	Graph gr = getTranspose();

	for (int i = 0; i < V; i++)
		visited[i] = false;

	for (int i = 0; i < V; i++)
		if (adj[i].size() > 0 && visited[i] == false)
			return false;

	return true;
}


int main()
{

	Graph g(6);
	g.addEdge(1, 0);
	g.addEdge(0, 2);
	g.addEdge(2, 1);
    g.addEdge(2,3);
	g.addEdge(0, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 0);
	g.addEdge(4, 1);

	if (g.isEulerianCycle())
	cout << "Has Euler Cycle";
	else
	cout << "No Has Euler Cycle";
	return 0;
}

