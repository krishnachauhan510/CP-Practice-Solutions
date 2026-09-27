#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        vector<ll> a;
        ll sm = 0;

        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;

            if (i <= k - 2)
            {
                if (i < n - k + 1)
                {
                    a.push_back(x);
                }
            }
            else if (i >= n - k + 1)
            {
                if (i > k - 2)
                {
                    a.push_back(x);
                }
            }
            else
            {
                sm += x;
            }
        }

        ll mx = 0;

        ll l = 0;
        ll r = (ll)a.size() - 1;

        while (l <= r)
        {
            mx += max(a[l], a[r]);
            l++;
            r--;
        }

        cout << sm + mx << '\n';
    }

    return 0;
}