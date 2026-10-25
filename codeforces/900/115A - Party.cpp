#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<int> roots;

    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;

        if (p == -1) {
            roots.push_back(i);
        } else {
            adj[i].push_back(p);
            adj[p].push_back(i);
        }
    }

    vector<int> level(n + 1, -1);
    queue<int> q;

    for (int root : roots) {
        level[root] = 0;
        q.push(root);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (level[v] == -1) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }

    int maxLevel = 0;

    for (int i = 1; i <= n; i++) {
        
        maxLevel = max(maxLevel, level[i]);
    }

    cout << maxLevel+1 << '\n';

    return 0;
}