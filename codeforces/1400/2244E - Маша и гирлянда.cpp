#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    ll n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<ll> pre(n, 0);

    for (ll i = 0; i < n - 1; i++)
    {
        pre[i + 1] = pre[i] + (s[i] == s[i + 1]);
    }

    while (q--)
    {
        ll l, r, k;
        cin >> l >> r >> k;

        if (l == r)
        {
            cout << "YES\n";
            continue;
        }

        ll cnt = pre[r - 1] - pre[l - 1];

        ll need = (cnt + 1) / 2;

        if (need <= k)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}