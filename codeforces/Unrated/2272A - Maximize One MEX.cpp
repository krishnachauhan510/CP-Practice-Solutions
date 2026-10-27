#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        if (k == 1) {
            cout << -1 << '\n';
        } else {
            auto x = max_element(a.begin(), a.begin() + n - k + 1) - a.begin();
            auto y = min_element(a.begin() + n - k + 1, a.end()) - a.begin();
            if (a[x] > a[y]) {
                cout << x + 1 << ' ' << y + 1 << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}