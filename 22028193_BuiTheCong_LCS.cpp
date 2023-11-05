#include<bits/stdc++.h>

using namespace std;

int main() {
    int m, n; cin >> m >> n;
    int a[m], b[n];
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < n; j++) {
        cin >> b[j];
    }
    int f[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                f[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i][j - 1], f[i - 1][j]);
            }
        }
    }

    cout << f[m][n];
    return 0;
}
