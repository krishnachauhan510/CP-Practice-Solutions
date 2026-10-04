#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--)
    {
        ll x, y;
        cin >> x >> y;

        ll val = x ^ y;

        ll ans = val & (-val);

        cout << ans << '\n';
    }

    return 0;
}