#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n + 1);

    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<vector<ll>> adj(n + 1);

    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> ans(k + 1, 0);
    vector<ll> dist(n + 1, LLONG_MAX);

    priority_queue<
        pair<ll, ll>,
        vector<pair<ll, ll>>,
        greater<pair<ll, ll>>
    > pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        ll d = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        if (dist[u] != d)
            continue;

        for (auto nbr : adj[u])
        {
            ll dst = d + 1;

            if (dist[nbr] > dst)
            {
                dist[nbr] = dst;
                pq.push({dst, nbr});
            }
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        ll type = a[i];
        ans[type] = max(ans[type], dist[i]);
    }

    for (ll i = 1; i <= k; i++)
    {
        cout << ans[i] << " ";
    }

    cout << '\n';

    return 0;
}