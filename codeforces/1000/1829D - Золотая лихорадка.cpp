#include <bits/stdc++.h>
using namespace std;

#define ll long long

map<ll, bool> dp;

bool rec(ll n, ll m)
{
    if (n == m)
        return true;

    if (n % 3 != 0)
        return false;

    if (dp.count(n))
        return dp[n];

    ll a = n / 3;
    ll b = 2 * a;

    return dp[n] = rec(a, m) || rec(b, m);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        dp.clear();  
        bool ans = rec(n, m);

        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}