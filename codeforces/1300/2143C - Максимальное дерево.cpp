#include <bits/stdc++.h>

using namespace std;
#define ll long long
vector<ll> topoSort(ll V, vector<vector<ll>> &adj)
{
    vector<ll> indegree(V + 1, 0);

    for (ll u = 1; u <= V; u++)
    {
        for (ll v : adj[u])
        {
            indegree[v]++;
        }
    }

    queue<ll> q;

    for (ll i = 1; i <= V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<ll> ans;

    while (!q.empty())
    {
        ll u = q.front();
        q.pop();

        ans.push_back(u);

        for (ll v : adj[u])
        {
            indegree[v]--;

            if (indegree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    if (ans.size() != V)
    {
        return {};
    }

    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<vector<ll>> adj(n + 1);
        for (ll i = 0; i < n - 1; i++)
        {
            ll u, v, x, y;
            cin >> u >> v >> x >> y;
            if (x > y)
            {
                adj[v].push_back(u);
            }
            else
            {
                adj[u].push_back(v);
            }
        }
        
        vector<ll> topo = topoSort(n, adj);
        reverse(topo.begin(), topo.end());
        
        ll k = n;
        vector<ll> ans(n + 1, 0);
        for (ll i = 0; i < topo.size(); i++)
        {
            ans[topo[i]] = k;
            k--;
        }
        for (ll i = 1; i < n; i++)
        {
            if (ans[i] == 0)
            {
                ans[i] = k;
                k--;
            }
        }
        for (ll i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}