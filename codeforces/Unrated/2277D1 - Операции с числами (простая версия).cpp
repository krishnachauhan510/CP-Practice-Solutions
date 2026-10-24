
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 998244353;

ll f(ll n) {
    if (n == 0) return 0;

    if (n % 2 == 0) return f(n + 1) + 1;
    if (n == 1) return 1;

    int k = 1;
    while ((1LL << k) - 1 < n) k++;

    ll mx = (1LL << k) - 1;

    if (n == mx) return k;

    ll sp = (1LL << (k - 1)) + 1;
    if (n == sp) return k + 2;

    ll c1 = (1LL << k) + k - 1 - n;

    ll sb = (1LL << (k - 1)) - 2;
    ll c2 = f(n - sb) + k;

    return min(c1, c2);
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

    while (t--) {
        solve();
    }

    return 0;
}
