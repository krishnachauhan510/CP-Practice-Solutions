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
        ll n, m;
        cin >> n >> m;

        string a, b;
        cin >> a >> b;

        bool flag = true;

        multiset<char> s(a.begin(), a.end());

        for (auto it : b)
        {
            auto it1 = s.find(it);

            if (it1 == s.end())
            {
                flag = false;
                break;
            }
            else
            {
                s.erase(it1);
            }
        }

        if (!flag)
        {
            cout << "NO\n";
        }
        else
        {
            string x(s.begin(), s.end());

            if (x == "isx")
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}