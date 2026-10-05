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
        string s;
        cin >> s;

        char a = s[0];
        ll n = s[1] - '0';

        vector<string> ans;

        for (ll i = 1; i <= 8; i++)
        {
            string g = string(1, a) + to_string(i);
            ans.push_back(g);
        }

        for (char ch = 'a'; ch <= 'h'; ch++)
        {
            string g = string(1, ch) + to_string(n);
            ans.push_back(g);
        }

        for (ll i = 0; i < ans.size(); i++)
        {
            if (ans[i] != s)
                cout << ans[i] << endl;
        }
    }

    return 0;
}