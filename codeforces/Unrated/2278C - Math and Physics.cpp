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

        ll sum = 0;
        bool flag = false, md = false;

        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;

            sum += x;

            if (x >= 2)
            {
                flag = true;

                if (i > 0 && i < n - 1)
                {
                    md = true;
                }
            }
        }

        if (!flag)
        {
            cout << -1 << '\n';
        }
        else if (md)
        {
            cout << sum - 1 << '\n';
        }
        else
        {
            cout << sum - n + 1 << '\n';
        }
    }

    return 0;
}