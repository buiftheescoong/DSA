#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1005];
int degree[1005];
void nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        degree[y]++;
    }
}

void Kahn(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(degree[i] == 0) q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(int v : adj[u]){
            degree[v]--;
            if(degree[v] == 0) q.push(v);
        }
    }
    if (topo.size() < n) cout << "Do thi co chu trinh !\n";
    else{
        for(int x : topo) {
            cout << x << ' ';

        }

    }
}

int main(){
    nhap();
    Kahn();
    return 0;
}
