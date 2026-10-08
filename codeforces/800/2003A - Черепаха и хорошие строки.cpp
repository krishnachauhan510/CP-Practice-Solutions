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

        string s;
        cin >> s;

        bool check = false;

        

        for (ll k = 1; k <= n-1; k++)
        {
            bool flag = true;
            set<char> st;

            ll l = 0, r = k - 1;

            while (r < n)
            {
                char f = s[l];
                char last = s[r];

                if (st.count(last))
                {
                    flag = false;
                    break;
                }

                st.insert(f);
                l++;
                r++;
            }

            if (flag)
            {
                check = true;
                break;
            }
        }

        cout << (check ? "YES\n" : "NO\n");
    }
}