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
        {
            cin >> a[i];
        }
        ll cnt = 0;
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (a[i] % 2 != 0)
                {
                    cnt++;
                }
                sum+=a[i];

                cout << a[i] << " ";
            }
            else
            {
                if (a[i] % 2 != 0)
                {
                    cnt++;
                }
                sum += a[i];
                ll val = cnt / 3;
                ll rem = cnt % 3;
                val = val + (rem == 1 ? 1 : 0);
                cout << sum - val << " ";
            }
        }
        cout << endl;
    }

    return 0;
}