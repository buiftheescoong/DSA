/* Tham khảo geeksforgeeks */
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

class Graph
{
	int V;
	list<int> *adj;
	vector< pair<int, iPair> > edges;
	void DFS(int v, bool visited[]);

public:
	Graph(int V);
	void addEdge(int u, int v, int w);
	bool isConnected();
	void reverseDeleteMST();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(v);
	edges.push_back({w, {u, v}});
}

void Graph::DFS(int v, bool visited[])
{
	visited[v] = true;
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i, visited);
}

bool Graph::isConnected()
{
	bool visited[V];
	memset(visited, false, sizeof(visited));
	DFS(0, visited);
	for (int i=1; i<V; i++)
		if (visited[i] == false)
			return false;
	return true;
}

void Graph::reverseDeleteMST()
{
	sort(edges.begin(), edges.end());

	int mst_wt = 0;

	cout << "Edges in MST\n";
	for (int i=edges.size()-1; i>=0; i--)
	{
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		adj[u].remove(v);
		if (isConnected() == false)
		{
			adj[u].push_back(v);
			cout << "(" << u << ", " << v << ") \n";
			mst_wt += edges[i].first;
		}
	}

	cout << "Total weight of MST is " << mst_wt;
}

int main()
{
	int v, e; cin >> v >> e;
	Graph g(v);
	for (int i = 0;i < e; i++) {
        int u, v, w; cin >> u >> v >> w;
        g.addEdge(u,v,w);
	}
	g.reverseDeleteMST();
	return 0;
}

