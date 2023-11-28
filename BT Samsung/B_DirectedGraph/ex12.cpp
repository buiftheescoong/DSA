
#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1005];
bool visited[1005];
stack<int> st;
void nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]) DFS(v);
    }
    st.push(u);
}

bool isEdge(int u, int v) {
    for (int x : adj[u]) {
        if (x == v) {
            return true;
        }
    }
    return false;
}
int main(){
    nhap();
    for(int i = 1; i <= n; i++){
        if(!visited[i]) DFS(i);
    }

    while(st.size() > 1){
        int u = st.top();
        st.pop();
        int v = st.top();
        if (!isEdge(u, v)) {
            cout << "No or many Topo sort";
            return 0;
        }
    }

    cout << "Only one Topo sort";
    return 0;
}

