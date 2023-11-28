#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1005];
bool visited[1005];

void nhap() {
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
}

void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int x = q.front(); q.pop();
        cout << x << ' ';
        for(int y : adj[x]){
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
            }
        }
    }
}
int main() {
    nhap();
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            BFS(i);
        }
    }
    // với input là 4 đỉnh 3 cạnh là 1->2, 2-> 3, 4-> 3 => output là 1 2 3 4 không đảm bảo thứ tự topo.
    return 0;
}
