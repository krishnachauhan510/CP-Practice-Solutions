
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998244353;
const int B = 3000;
const int K = 60;

unordered_map<ll, ll> memoF, memoG;
ll tailPref[K][B + 1];

ll f(ll n) {
    if (n <= 1) return n;
    if (n == 2) return 3;
    if (n == 3) return 2;

    auto it = memoF.find(n);
    if (it != memoF.end())
        return it->second;

    int k = 63 - __builtin_clzll(n);
    ll p = 1LL << k;

    ll a = f(n - p + 2) + k + 1;
    ll b = (p << 1) - n + k;

    return memoF[n] = min(a, b);
}

ll g(ll n) {
    if (n < 0) return 0;
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 4;
    if (n == 3) return 6;

    auto it = memoG.find(n);
    if (it != memoG.end())
        return it->second;

    int k = 63 - __builtin_clzll(n);
    ll p = 1LL << k;
    ll q = p << 1;

    ll ans = g(p - 1);

    ll y = min(n, q - B);

    if (y >= p) {
        ll cnt = y - p + 1;

        ll add = (g(y - p + 2) - 1 + MOD) % MOD;

        add = (add + (cnt % MOD) * (k + 1)) % MOD;

        ans = (ans + add) % MOD;
    }

    ll start = max(p, y + 1);

    if (start <= n) {
        ll dLow = q - n;
        ll dHigh = q - start;

        ll add = (tailPref[k][dHigh]
                - tailPref[k][dLow - 1] + MOD) % MOD;

        ans = (ans + add) % MOD;
    }

    return memoG[n] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int k = 0; k < K; k++) {
        ll p = 1LL << k;
        ll q = p << 1;

        for (int d = 1; d <= B; d++) {
            ll n = q - d;
            ll val = 0;

            if (n >= p)
                val = f(n);

            tailPref[k][d] =
                (tailPref[k][d - 1] + val) % MOD;
        }
    }

    int t;
    cin >> t;

    while (t--) {
        ll l, r;
        cin >> l >> r;

        cout << (g(r) - g(l - 1) + MOD) % MOD << '\n';
    }

    return 0;
}
