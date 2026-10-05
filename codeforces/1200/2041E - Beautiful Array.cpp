#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << 1 << endl;
        cout << a << endl;
    }
    else
    {
        ll len = 0;
        ll f;
        bool flag = false; // mera abhi

        for (ll i = 3; i <= 1000; i++)
        {

            ll val = (i - 1) * b;
            ll sum = i * a;
            f = sum - val;
            if (f < b)
            {
                // posi
                len = i;
                break;
            }
            else
            {
                len = i;
                flag = true;
            }
        }

        cout << len << endl;
        if (flag == false)
        {
            cout << f << " ";
            for (ll i = 2; i <= len; i++)
            {
                cout << b << " ";
            }
        }
        else{
             
            for (ll i = 2; i <= len; i++)
            {
                cout << b << " ";
            }
            cout << f << " ";

        }
        
    }

    return 0;
}