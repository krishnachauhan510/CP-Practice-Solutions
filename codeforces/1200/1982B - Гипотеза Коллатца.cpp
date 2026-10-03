#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        ll x, y, k;
        cin >> x >> y >> k;

        while (k > 0)
        {
            ll rem = y - (x % y);

            if (rem > k)
            {
                x += k;
                k = 0;
            }
            else
            {
                x += rem;
                k -= rem;
            }

            while (x % y == 0)
            {
                x /= y;
            }

            if (x < y)
            {
                break;
            }
        }

        if (k > 0)
        {
            if (x + k < y)
            {
                x += k;
            }
            else
            {
                k -= (y - x);
                x = 1;
                k %= (y - 1);
                x += k;
            }
        }

        cout << x << "\n";
    }
}