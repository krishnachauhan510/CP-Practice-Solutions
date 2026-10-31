#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> a(n);
        ll mn = 1e18, mx = -1e18;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }

        if (mn == mx)
        {
            cout << "0 0\n";
        }
        else
        {

            vector<ll> v = a;
            sort(v.begin(), v.end());

            ll med = v[n / 2];
            ll cost = 0;

            for (int i = 0; i < n; i++)
            {
                cost += abs(v[i] - med);
            }

            ll ops = mx - mn;

            cout << cost << " " << ops << '\n';
        }
    }

    return 0;
}