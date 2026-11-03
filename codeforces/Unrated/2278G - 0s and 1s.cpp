#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 998'244'353;
const int MX = 200005;

vector<int> p2(MX, 1);

void init(){
    for(int i = 1; i < MX; i++){
        p2[i] = 2 * p2[i - 1] % mod;
    }
}

int main(){

    init();

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<vector<int>> adj(n + 1);

        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string x, y;
        cin >> x >> y;

        x = "." + x;
        y = "." + y;

        vector<int> dep(n + 1, 0), par(n + 1, 0);

        function<void(int, int)> dfs = [&](int u, int p){
            for(auto& v : adj[u]){
                if(v == p) continue;

                par[v] = u;
                dep[v] = dep[u] + 1;

                dfs(v, u);
            }
        };

        dfs(1, -1);

        vector<int> carry(n + 1, 0);
        vector<vector<int>> nodes(n);

        for(int i = 1; i <= n; i++){
            nodes[dep[i]].push_back(i);
        }

        int ans = 0;
        bool ok = 1;

        for(int i = 0; i < n && ok; i++){

            bool req[2] = {0, 0};

            for(auto& u : nodes[i]){

                int xb = x[u] - '0';
                int yb = y[u] - '0';
                int cb = carry[par[u]];

                int rb = xb ^ yb ^ cb;

                req[rb] = 1;

                if(xb + cb + rb > 1){
                    carry[u] = 1;
                }
            }

            if(req[0] && req[1]){
                ok = 0;
            }

            ans = (ans + req[1] * p2[i]) % mod;
        }

        if(!ok) ans = -1;

        cout << ans << '\n';
    }

    return 0;
}