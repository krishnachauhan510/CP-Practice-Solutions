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

        ll val1 = 0;
        ll mx = 0;
        ll num = -1;

        map<char, ll> f;
        multiset<ll> s;

        for (ll i = 0; i < x.size(); i++)
        {
            s.insert(x[i] - '0');
            f[x[i]]++;
            val1 += x[i] - '0';
        }

        ll sm = 0;
        ll cnt = 0;
        bool flag = false;

        for (auto it : s)
        {
            sm += it;

            if (sm > 9)
            {
                break;
            }
            else
            {
                if (it == x[0] - '0')
                {
                    flag = true;
                }
                cnt++;
            }
        }

        ll val2 = 0;
        string x2 = to_string(val1);

        for (ll i = 0; i < x2.size(); i++)
        {
            val2 += x2[i] - '0';
        }
  //cout<<x.size()<<endl;
        if (val1 == val2)
        {
            cout << 0 << endl;
        }
      
        else
        {
            if (flag)
            {
                cout << x.size() - cnt << endl;
            }
            else
            {
                x[0] = '1';
                cnt = 0;
                sm=1;

                for (auto it : s)
                {
                    sm += it;

                    if (sm > 9)
                    {
                        break;
                    }
                    else
                    {
                        if (it == x[0] - '0')
                        {
                            flag = true;
                        }
                        cnt++;
                    }
                }
                

                cout << x.size() - cnt << endl;
            }
        }
    }

    return 0;
}