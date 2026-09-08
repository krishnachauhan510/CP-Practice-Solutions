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
        ll x, y, k;
        cin >> x >> y >> k;

        ll d = y - x;

        
        if (x > d)
        {
            cout << d * k << '\n';
            continue;
        }

        ll ans = 0;

        ll cnt = min(k, d - x + 1);

        for (ll i = 0; i < cnt; i++)
        {
            ans += d % (x + i);
        }

        ans += (k - cnt) * d;

        cout << ans << '\n';
    }

    return 0;
}