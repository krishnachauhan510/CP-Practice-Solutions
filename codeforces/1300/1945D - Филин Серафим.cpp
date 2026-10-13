
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> a, b;
ll n, m;
ll rec(ll ind, ll bit, vector<vector<ll>> &dp)
{
    if (ind > n)
    {
        return 0;
    }

    if (bit == 1)
    {
        if (dp[ind][1] != -1)
        {
            return dp[ind][1];
        }
        return dp[ind][1] = a[ind] + min(rec(ind + 1, 0,dp), rec(ind + 1, 1,dp));
    }
    else
    {
        if (dp[ind][0] != -1)
        {
            return dp[ind][0];
        }
        return dp[ind][0] = b[ind] + min(rec(ind + 1, 0,dp), rec(ind + 1, 1,dp));
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        a.resize(n + 1);
        b.resize(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (ll i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        vector<vector<ll>> dp(n + 2, vector<ll>(2, -1));

        ll ans = rec(1, 1, dp);
        for(ll i=1;i<=m;i++){
            ans=min(ans,dp[i][1]);
        }
        cout << ans << endl;
    }
}
