
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

ll f(ll n) {
    if (n <= 1) return n;
    if (n == 2) return 3;
    if (n == 3) return 2;

    int k = 63 - __builtin_clzll(n);
    ll p = 1LL << k;

    return min(f(n - p + 2) + k + 1,
               (1LL << (k + 1)) - n + k);
}

void solve() {
    ll l, r;
    cin >> l >> r;

    ll ans = 0;

    for (ll n = l; n <= r; n++) {
        ans = (ans + f(n)) % MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}
