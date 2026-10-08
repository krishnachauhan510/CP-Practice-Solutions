#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
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

        priority_queue<pair<ll, ll>> pq;
        // pick 1index
        a[1] -= (2 * a[0]);

        a[2] -= (a[0]);
        a[0] = 0;
        a[n - 2] -= (2 * a[n - 1]);

        a[n - 3] -= a[n - 1];
        a[n - 1] = 0;
        ll cnt = 0;

        for (ll i = 0; i < n; i++)
        {
            if (a[i] < 0)
            {
                cnt = -1;
            }
        }

        for (ll i = 1; i <= n - 3; i++)
        {
            if (a[i] < 0)
            {
                cnt = -1;
            }
            a[i + 1] -= (2 * a[i]);
            a[i + 2] -= a[i];
            a[i] = 0;
        }

        //cout << endl;

        if (cnt == 0)
        {
            for (ll i = 0; i < n; i++)
            {
                //cout << a[i] << " ";

                if (a[i] == 0)
                {
                    cnt++;
                }
            }
        }

        ///`cout << '\n';

        if (cnt == n)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}