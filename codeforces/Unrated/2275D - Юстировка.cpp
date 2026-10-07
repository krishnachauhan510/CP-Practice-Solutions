#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool check(ll mid, ll k,
           vector<ll> &a,
           vector<ll> &b,
           vector<ll> &c)
{
    ll n = a.size();
    ll need = 0;

    for (ll i = 0; i < n; i++)
    {
        ll cur = a[i] + b[i] + c[i];

        if (cur >= mid)
        {
            continue;
        }

        ll g = mid - cur;

        if (a[i] == b[i] && b[i] == c[i])
        {
            return false;
        }
        if (a[i] <= b[i] && b[i] <= c[i])
        {
            ll ex = 2 * (min(b[i] - a[i],
                             c[i] - b[i]) +
                         1);

            need += g + ex;
        }
        else
        {
            need += g;
        }

        if (need > k)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n), b(n), c(n);

        ll mn = LLONG_MAX;

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i] >> c[i];

            mn = min(mn, a[i] + b[i] + c[i]);
        }

        ll lo = mn;
        ll hi = mn + k;
        ll ans = mn;

        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;

            if (check(mid, k, a, b, c))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}