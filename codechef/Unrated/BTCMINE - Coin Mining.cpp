#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    ll X, Y;
    cin >> X >> Y;

    ll mday = 1e9;
    for (ll K = 1; K <= 200; ++K) {
        ll num = 6LL * X + 1LL * Y * (4 * K + 1) * (K - 1);
        ll den = 6LL * Y * K;
        ll d_req = (num / den) + 1;
        ll d_actual = max(K, d_req);
        mday = min(mday, d_actual);
    }

    cout << mday << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}