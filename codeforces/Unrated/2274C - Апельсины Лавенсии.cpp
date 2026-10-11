#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll c, ll n) {
    ll sum = 0;
    for (ll s = 1; s <= c; s++) {
        sum += s * (c / s);
        if (sum >= n) return true;
    }
    return false;
}

void solve() {
    ll n;
    cin >> n;

    ll l = 1, r = n, c = n;

    while (l <= r) {
        ll m = (l + r) / 2;
        if (check(m, n)) c = m, r = m - 1;
        else l = m + 1;
    }

    vector<ll> cnt(c + 1), a;
    ll sum = 0, id = 1;

    for (ll s = 1; s <= c; s++)
        sum += s * (cnt[s] = c / s);

    ll d = sum - n;

    for (ll s = c; s >= 2; s--) {
        ll x = min(cnt[s], d / s);
        cnt[s] -= x;
        d -= x * s;
    }

    cnt[1] -= d;

    for (ll s = 1; s <= c; s++)
        for (ll j = 0; j < cnt[s]; j++, id++)
            for (ll k = 0; k < s; k++)
                a.push_back(id);

    cout << c << '\n';
    for (ll x : a) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}