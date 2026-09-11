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
        ll n, c, d;
        cin >> n >> c >> d;

        vector<ll> a(n * n);

        for (ll i = 0; i < n * n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        ll a1 = 0;
        vector<ll> ans;

        for (ll i = 0; i < n * n; i++)
        {
            if (i % n == 0)
            {
                if (i == 0)
                {
                    ans.push_back(a[0]);
                    a1 = a[0];
                }
                else
                {
                    ll val = a1 + c;
                    a1 = val;
                    ans.push_back(val);
                }
            }
            else
            {
                ll val = ans[i - 1] + d;
                ans.push_back(val);
            }
        }

        sort(ans.begin(), ans.end());

        if (a == ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}