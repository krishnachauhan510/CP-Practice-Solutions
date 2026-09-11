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

        ll px, py, qx, qy;
        cin >> px >> py >> qx >> qy;

        vector<ll> a(n);
        ll sum = 0;

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        ll dist2 =
            (px - qx) * (px - qx) +
            (py - qy) * (py - qy);

        ll mx = *max_element(a.begin(), a.end());

        if (dist2 > sum * sum)
        {
            cout << "No\n";
            continue;
        }

        ll mn = max(0LL, 2 * mx - sum);

        if (mn * mn <= dist2)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}