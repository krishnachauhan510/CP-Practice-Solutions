#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 2e5;

vector<vector<int>> primeDiv(MAXN + 1);
vector<ll> dp(MAXN + 1);

ll rec(ll x, ll k)
{
    if (x <= k)
        return 0;

    if (dp[x] != -1)
        return dp[x];

    dp[x] = LLONG_MAX;

    
    for (ll p : primeDiv[x])
    {
        ll cur = 1 + p * rec(x / p, k);
        dp[x] = min(dp[x], cur);
    }

    return dp[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int p = 2; p <= MAXN; p++)
    {
        if (primeDiv[p].empty())
        {
            for (int j = p; j <= MAXN; j += p)
            {
                primeDiv[j].push_back(p);
            }
        }
    }

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);

        for (ll i = 0; i < n; i++)
            cin >> a[i];

        fill(dp.begin(), dp.begin() + n + 1, -1);

        ll ans = 0;

        for (ll x : a)
        {
            ans += rec(x, k);
        }

        cout << ans << '\n';
    }

    return 0;
}