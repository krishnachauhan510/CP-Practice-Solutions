#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    ll a, b;
    cin >> a >> b;

    ll ca = a, cb = b;
    ll ans = 0;
    ll sa = 0, sb = 0;

    // a, b
    for (ll i = 0; i <= 62; i++)
    {
        if (i % 2 == 0)
        {
            sa = (1LL << i);

            if (sa <= ca)
            {
                ans = max(ans, i + 1);
                ca -= (1LL << i);
            }
            else
            {
                break;
            }
        }
        else
        {
            sb = (1LL << i);

            if (sb <= cb)
            {
                ans = max(ans, i + 1);
                cb -= (1LL << i);
            }
            else
            {
                break;
            }
        }
    }

    // b, a
    ca = a;
    cb = b;
    sa = 0;
    sb = 0;

    for (ll i = 0; i <= 62; i++)
    {
        if (i % 2 == 0)
        {
            sb = (1LL << i);

            if ( sb<= cb)
            {
                ans = max(ans, i + 1);
                cb -= (1LL << i);
            }
            else
            {
                break;
            }
        }
        else
        {
            sa = (1LL << i);

            if (sa <= ca)
            {
                ans = max(ans, i + 1);
                ca -= (1LL << i);
            }
            else
            {
                break;
            }
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}