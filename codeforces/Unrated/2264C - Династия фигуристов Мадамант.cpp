#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 998244353;
const ll N = 200005;

ll fact[N], inv[N];

ll modpow(ll a, ll b)
{
    ll ans = 1;

    while (b)
    {
        if (b & 1)
            ans = ans * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;

    for (ll i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }

    // inverse
    inv[1] = 1;

    for (ll i = 2; i < N; i++)
    {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> a(n);

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        ll total = fact[n - 1];

        vector<ll> parentCnt(n, 0);


        for (ll i = 1; i < n; i++)
        {
            parentCnt[i] =
                (parentCnt[i - 1]
                 + total * inv[n - i]) % MOD;
        }

        ll ans = 0;

        for (ll i = 0; i < n; i++)
        {
            // a[i] as parent
            ans += (a[i] % MOD) * parentCnt[i] % MOD;
            ans %= MOD;

            // a[i] as child
            if (i != n - 1)
            {
                ans -= (a[i] % MOD) * total % MOD;
                ans %= MOD;
            }
        }

        if (ans < 0)
            ans += MOD;

        cout << ans << '\n';
    }

    return 0;
}