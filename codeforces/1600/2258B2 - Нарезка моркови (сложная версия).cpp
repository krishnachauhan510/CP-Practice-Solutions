
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> sf(m + 2, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sf[a[i]]++;
    }

    for (int i = m; i >= 1; i--) {
        sf[i - 1] += sf[i];
    }

    int sum = accumulate(a.begin(), a.end(), 0LL);

    for (int k = 1; k <= m; k++) {
        int ans = 0;

        if (k >= 30 || (1LL << k) >= m) {
            ans = sum;
        } else {
            for (int x = 1; x <= m / (1LL << k) + 3; x++) {
                int now = 0;

                for (int j = 1; j < (1LL << k) && x * j <= m; j++) {
                    now += sf[x * j];
                }

                if (x * (1LL << k) <= m) {
                    now += sf[x * (1LL << k)] - sf[x * (1LL << k) + 1];
                }

                ans = max(ans, now);
            }
        }

        cout << ans << (k == m ? '\n' : ' ');
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
