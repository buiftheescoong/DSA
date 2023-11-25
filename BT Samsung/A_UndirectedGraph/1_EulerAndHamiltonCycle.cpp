#include<bits/stdc++.h>

using namespace std;
vector<int> adj[1005];
bool visited[1005];
int cnt[1005];
int n, m;
void nhap() {
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        cnt[x]++;
        cnt[y]++;
    }
    memset(visited, false, sizeof(visited));
}
void DFS(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            DFS(v);
        }
    }
}
int tplt(){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ++count;
            DFS(i);
        }
    }
    return count;
}

bool isConnected() {
    return (tplt() == 1);
}
bool hasEulerCycle() {
    bool allVerticesHasEvenDegree = true;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] % 2 != 0) {
            allVerticesHasEvenDegree = false;
        }
    }
    return (allVerticesHasEvenDegree && isConnected());
}

bool hasHamiltonCycle() {
    if (!isConnected()) {
        return false;
    }
    if (n < 2) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    int deg = n / 2;
    bool verticesDegree = true;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] < deg) {}
        verticesDegree = false;
    }
    return verticesDegree;
}
int main() {
    nhap();
    if (hasEulerCycle()) {
        cout << "Has Euler Cycle";
    } else {
        cout << "No Euler Cycle";
    }
    if (hasHamiltonCycle()) {
        cout << "Has Hamilton Cycle";
    } else {
        cout << "No Hamilton Cycle";
    }


    return 0;
}
