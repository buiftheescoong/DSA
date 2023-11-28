#include<bits/stdc++.h>

using namespace std;


int n, m;
vector<int> adj[1005], t_adj[1005];
bool visited[1005];
stack<int> st;
void nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
    int x, y; cin >> x >> y;
    adj[x].push_back(y); // graph
    t_adj[y].push_back(x); // transpose graph
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int u, vector<int> &w) {
    visited[u] = true;
    w.push_back(u);
    for(int v : t_adj[u]){
        if(!visited[v]) DFS(v, w);
    }
}
void DFS1(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]) DFS1(v);
    }
    st.push(u);
}

void DFS2(int u){
    visited[u] = true;
    cout << u << ' ';
    for(int v : t_adj[u]){
        if(!visited[v]) DFS2(v);
    }
}
int Kosaraju(int given_vertice){
    for(int i = 1; i <= n; i++){
        if(!visited[i]) DFS1(i);
    }
    memset(visited, false, sizeof(visited));
    int scc = 0;
    while(!st.empty()){
        int u = st.top(); st.pop();
        if(!visited[u]){
            ++scc;
            vector<int> v;
            DFS(u, v);
            if (count(v.begin(), v.end(), given_vertice)) {
                for (int x : v) {
                    cout << x << " ";
                }
            }
        }
    }
    return scc;
}




int main(){
    nhap();
    int u; cin >> u;
    int so_tplt_manh = Kosaraju(u); // tìm các thành phần liên thông liên thông mạnh, và in ra thành phần liên thông mạnh chứa đỉnh u cho trước
    cout << endl << so_tplt_manh;
    return 0;
}
