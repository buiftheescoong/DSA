#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1005];
bool visited[1005];
vector<pair<int, int>> edge;
void DFS(int u, int s, int t){
    visited[u] = true;
    for(int v : adj[u]){
        //Neu xet phai canh muon loai bo thi khong xet
        if((u == s && v == t) || (u == t && v == s)){
            continue;
        }
        if(!visited[v]){
            DFS(v, s, t);
        }
    }
}

void dfs(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

int tplt(){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ++count;
            dfs(i);
        }
    }
    return count;
}

int tplt_xoacanh(int s, int t){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ++count;
            DFS(i, s, t);
        }
    }
    return count;
}
int canh_cau(){
    int cc = tplt();
    int so_canh_cau = 0;
    for(pair<int, int> e : edge){
        int s = e.first, t = e.second;
        memset(visited, false, sizeof(visited));
        if(cc < tplt_xoacanh(s, t)){
            so_canh_cau++;
        }
    }
    return so_canh_cau;
}

void nhap() {
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        pair<int, int> p;
        p.first = x;
        p.second = y;
        edge.push_back(p);
    }
    memset(visited, false, sizeof(visited));
}


int main() {
    nhap();
    int so_canh_cau = canh_cau();
    if (so_canh_cau == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;

}

