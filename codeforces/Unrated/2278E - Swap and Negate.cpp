
#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

        vector<ll> a(n);

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<ll> b = a;

        for (ll i = 1; i < n; i += 2)
        {
            b[i] = -b[i];
        }

        sort(b.begin(), b.end());

        ll ans = 0;
        ll i = 0;

        for (; i < n / 2; i++)
        {
            ans -= b[i];
        }

        for (; i < n; i++)
        {
            ans += b[i];
        }

        cout << ans << '\n';
    }

    return 0;
}
