#include<bits/stdc++.h>

using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    pair<int, int> p[E];
    map<pair<int, int>, int> mp;
    int result = 0;
    for (int i = 0; i < E; i++) {
        cin >> p[i].first >> p[i].second;
        int min_number = min(p[i].first, p[i].second);
        int max_number = max(p[i].first, p[i].second);
        p[i].first = min_number;
        p[i].second = max_number;
        mp[p[i]]++;
    }
    for (auto it : mp) {
        if (it.second > 1) {
            result += it.second;
        }
    }
    cout << result << endl;
    return 0;
}
