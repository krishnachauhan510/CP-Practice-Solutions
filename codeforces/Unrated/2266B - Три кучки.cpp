#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        cout << max(llabs(a - b), llabs(a + c - b)) << '\n';
    }
}