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
        string s;

        cin >> n >> s;

        stack<ll> st;
        vector<bool> printed(n + 1, false);

        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
               
                st.push(i + 1);
            }
            else if (s[i] == '2')
            {
                if (!st.empty())
                {
                   
                    printed[st.top()] = true;
                    st.pop();
                }
                else
                {
                   
                    printed[i + 1] = true;
                }
            }
            else 
            {
                
                printed[i + 1] = true;
            }
        }

        vector<ll> ans;

        for (ll i = 1; i <= n; i++)
        {
            if (!printed[i])
                ans.push_back(i);
        }

        cout << ans.size() << '\n';

        for (ll x : ans)
            cout << x << ' ';

        cout << '\n';
    }

    return 0;
}