
#include<bits/stdc++.h>

using namespace std;

int n, m;

int a[1005][1005];
bool visited[1005][1005];
int dx[4] = {1, -1,0, 0 };
int dy[4] = {0, 0,1, -1};


void DFS(int i, int j, int c, vector<pair<int,int>> & v){
    visited[i][j] = true;
    pair<int, int> p;
    p.first = i;
    p.second = j;
    v.push_back(p);
    for(int k = 0; k < 4; k++){
        int i1 = i + dx[k], j1 = j + dy[k];
        if(i1 >= 1 && i1 <= m && j1 >= 1 && j1 <= n && !visited[i1][j1]){
            if (a[i1][j1] == c) {
                DFS(i1, j1, c,v);
            }
        }
    }
}

int tplt() {
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (!visited[i][j]) {
                    cnt++;
                    int c = a[i][j];
                    vector<pair<int, int>> v;
                    DFS(i, j,c, v);
                    cout << "Vung cac diem anh cung mau" << " thu " << to_string(cnt) << " la " << endl;
                    for (pair<int, int> p : v) {
                        cout << p.first << " " << p.second << endl;
                    }
            }
        }
    }
    return cnt;
}
void nhap() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    memset(visited, false, sizeof(visited));

}
int main() {
    nhap();
    int so_cac_vung_diem_anh_cung_mau = tplt();
    cout <<so_cac_vung_diem_anh_cung_mau;
    return 0;
}
