#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        string x;
        cin >> x;

        ll sum = 0;
        vector<ll> a2, a3;

        for (ll i = 0; i < x.size(); i++)
        {
            ll digit = x[i] - '0';

            sum += digit;

            if (digit == 2)
            {
                a2.push_back(digit);
            }
            else if (digit == 3)
            {
                a3.push_back(digit);
            }
        }

        if (sum % 9 == 0)
        {
            cout << "YES" << endl;
            continue;
        }

        bool found = false;

        for (ll i = 0; i <= a2.size(); i++)
        {
            for (ll j = 0; j <= a3.size(); j++)
            {
                
                ll val = 2 * i + 6 * j;

                if ((sum + val) % 9 == 0)
                {
                    cout << "YES" << endl;
                    found = true;
                    break;
                }
            }

            if (found)
                break;
        }

        if (!found)
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}