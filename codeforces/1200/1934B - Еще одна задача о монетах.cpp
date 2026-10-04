#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> a(200, 200);

    a[0] = 0;
    a[1] = 1;
    a[3] = 1;
    a[6] = 1;
    a[10] = 1;
    a[15] = 1;

    vector<ll> coin = {1, 3, 6, 10, 15};

    for (ll i = 2; i <= 199; i++)
    {
        for (auto x : coin)
        {
            ll c = i - x;

            if (c >= 0)
            {
                a[i] = min(a[i], a[c] + 1);
            }
        }
    }

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        ll ans = 1e18;

        for (ll k = max(0LL, n / 15 - 10); k <= n / 15; k++)
        {
            ll left = n - 15 * k;

            if (left >= 0 && left <= 199)
            {
                ans = min(ans, k + a[left]);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}