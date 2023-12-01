/* Tham khảo geeksforgeeks */
#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

void disjoint(int size)
{
    parent.resize(size + 1);
    for (int i = 0; i <= size; i++)
        parent[i] = i;
}

int find(int u)
{
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
    int ua = find(u);
    int ub = find(v);
    parent[ua] = ub;
}

int help1(vector<vector<int> >& e, int j, int n)
{
    disjoint(n + 1);
    vector<pair<int, pair<int, int> > > v;

    for (int i = 0; i < e.size(); i++) {
        if (i == j)
            continue;
        v.push_back({ e[i][2], { e[i][0], e[i][1] } });
    }
    sort(v.begin(), v.end());

    int mst_weight = 0;
    int edges = 0;

    for (int i = 0; i < v.size(); i++) {

        auto x = v[i];
        int u = find(x.second.first);
        int v = find(x.second.second);

        if (u != v) {
            edges++;
            mst_weight += x.first;
            merge(u, v);
        }
    }
    if (edges != n - 1)
        return INT_MAX;

    return mst_weight;
}

int help2(vector<vector<int> >& e, int j, int n)
{
    disjoint(n + 1);
    int mst_weight = e[j][2];
    merge(e[j][1], e[j][0]);

    vector<pair<int, pair<int, int> > > v;
    for (int i = 0; i < e.size(); i++) {

        if (i == j)
            continue;
        v.push_back({ e[i][2], { e[i][0], e[i][1] } });
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {

        auto x = v[i];
        int u = find(x.second.first);
        int v = find(x.second.second);

        if (u != v) {
            mst_weight += x.first;
            merge(u, v);
        }
    }
    return mst_weight;
}

vector<int> findCriticalEdges(int n, vector<vector<int> >& e)
{
    disjoint(n + 1);
    int mst_weight = help1(e, -1, n);
    vector<int> v1;

    for (int i = 0; i < e.size(); i++) {
        int new_weight1 = help1(e, i, n);
        int new_weight2 = help2(e, i, n);
        if (new_weight1 > mst_weight) {
            v1.push_back(i);
        }
    }
    return v1;
}

int main()
{
    int vertices = 5;
    vector<int> result;
    vector<vector<int> > edges;
    edges.push_back({ 0, 1, 1 });
    edges.push_back({ 1, 2, 1 });
    edges.push_back({ 2, 3, 2 });
    edges.push_back({ 0, 3, 2 });
    edges.push_back({ 0, 4, 3 });
    edges.push_back({ 3, 4, 3 });
    edges.push_back({ 1, 4, 6 });
    result = findCriticalEdges(vertices, edges);
    for (int e : result) {
        cout << e << " ";
    }
    return 0;
}
