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
        ll a, b, c;
        cin >> a >> b >> c;

        ll n = a + b + c;

        if (c <= b)
        {
            cout << string(n, 'R') << '\n';
        }
        else if (a <= c)
        {
            cout << string(n, 'S') << '\n';
        }
        else
        {
            cout << string(n, 'P') << '\n';
        }
    }

    return 0;
}