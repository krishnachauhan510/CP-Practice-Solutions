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
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];

        vector<ll> du(n);

        for (ll i = 0; i <= n - 5; i++)
        {
            du[i] = a[i] + a[i + 2] - a[i + 4];
        }

        map<ll, ll> f;
        ll ans = 0;

        for (ll i = 0; i <= n - 5; i++)
        {
            ll val = du[i];

            ans += f[val];

            if (i >= 2 && du[i - 2] == val)
            {
                ans--;
            }

            if (i >= 4 && du[i - 4] == val)
            {
                ans--;
            }

            f[val]++;
        }

        cout << ans << '\n';
    }

    return 0;
}