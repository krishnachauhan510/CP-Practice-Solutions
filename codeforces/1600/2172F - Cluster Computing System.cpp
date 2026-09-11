#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<ll> p(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    vector<ll> g1(n), g2(n);

    g1[0] = p[0];
    g2[n - 1] = p[n - 1];

    for (ll i = 1; i < n; i++)
    {
        g1[i] = gcd(g1[i - 1], p[i]);
    }

    for (ll i = n - 2; i >= 0; i--)
    {
        g2[i] = gcd(g2[i + 1], p[i]);
    }

    ll ans = g1[n - 1];

    for (ll i = 1; i < n - 1; i++)
    {
        ans += min(g1[i], g2[i]);
    }

    cout << ans << '\n';

    return 0;
}