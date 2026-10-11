#include <bits/stdc++.h>
using namespace std;

#define ll long long

multiset<ll> s;
ll k;

bool check(ll t) {
    ll used = 0;
    multiset<ll> e = s;

    while (!e.empty()) {
        ll x = *e.rbegin();

        ll bound = k + t + (ll)e.size() - 1 + (t - used);

        if (x > bound) {
            if (used >= t)
                return false;

            used++;

            ll half = (x + 1) / 2;
            e.insert(half);
            e.insert(half);
        }

        e.erase(prev(e.end()));
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;

    while (T--) {
        ll n;
        cin >> n >> k;

        s.clear();

        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            s.insert(x);
        }

        ll lo = -1, hi = 2e5;

        while (hi - lo > 1) {
            ll mid = (lo + hi) / 2;

            if (check(mid))
                hi = mid;
            else
                lo = mid;
        }

        cout << n + 2 * hi << '\n';
    }

    return 0;
}