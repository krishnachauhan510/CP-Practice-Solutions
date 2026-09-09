#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    ll n;
    cin >> n;

    map<ll, ll> f;

    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        f[x]++;
    }

    ll ans = 0;

    for (auto [a, b] : f)
    {
        ans = max(ans, b);
    }

    ans = (ans + 1) / 2;

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}