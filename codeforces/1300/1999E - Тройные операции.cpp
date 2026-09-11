#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 2e5 + 5;
ll pre[N];

ll cnt3(ll n)
{
    ll cnt = 0;

    while (n > 0)
    {
        n /= 3;
        cnt++;
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (ll i = 1; i < N; i++)
    {
        pre[i] = pre[i - 1] + cnt3(i);
    }

    ll t;
    cin >> t;

    while (t--)
    {
        ll l, r;
        cin >> l >> r;

        ll ans = 2*cnt3(l) + pre[r] - pre[l];

        cout << ans << '\n';
    }

    return 0;
}