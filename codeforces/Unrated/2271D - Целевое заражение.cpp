
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll LIM = 1000000000000000000LL;

vector<pair<ll, ll>> segs;
vector<ll> pref;

void build()
{
    sort(segs.begin(), segs.end());

    vector<pair<ll, ll>> merged;

    for (auto p : segs)
    {
        ll l = p.first;
        ll r = p.second;

        if (merged.empty() ||
            (merged.back().second < LIM &&
             l > merged.back().second + 1))
        {
            merged.push_back({l, r});
        }
        else
        {
            merged.back().second = max(merged.back().second, r);
        }
    }

    segs = merged;

    ll sz = (ll)segs.size();
    pref.assign(sz + 1, 0);

    for (ll i = 0; i < sz; i++)
    {
        pref[i + 1] = pref[i] +
                      segs[i].second - segs[i].first + 1;
    }
}

ll countMarked(ll x)
{
    if (x <= 0)
        return 0;

    x = min(x, LIM);

    ll idx = upper_bound(
                 segs.begin(), segs.end(),
                 make_pair(x, LLONG_MAX)) -
             segs.begin();

    if (idx == 0)
        return 0;

    ll ans = pref[idx - 1];
    ll l = segs[idx - 1].first;
    ll r = segs[idx - 1].second;

    ans += max(0LL, min(x, r) - l + 1);

    return ans;
}

ll getMarked(ll L, ll R)
{
    if (L < 1 || L > R || L > LIM)
        return 0;

    R = min(R, LIM);

    return countMarked(R) - countMarked(L - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;

        segs.clear();
        segs.resize(n);

        for (ll i = 0; i < n; i++)
            cin >> segs[i].first >> segs[i].second;

        build();

        ll sz = (ll)segs.size();
        ll st = -1;

        if (k != 0)
        { // start1
            for (ll i = 0; i < sz && st == -1; i++)
            {
                ll lo = segs[i].first;
                ll hi = segs[i].second;

                while (lo <= hi)
                {
                    ll mid = lo + (hi - lo) / 2;

                    ll L = mid;
                    ll R = L + min(m - 1, LIM - L);

                    ll marked = getMarked(L, R);
                    ll len = R - L + 1;

                    if (len == m && marked == k)
                    {
                        st = L;
                        break;
                    }

                    if (marked > k)
                        hi = mid - 1;
                    else
                        lo = mid + 1;
                }
            }

            if (st == -1)
            {
                // start2
                for (ll i = 0; i < sz && st == -1; i++)
                {
                    ll lo = segs[i].first;
                    ll hi = segs[i].second;

                    while (lo <= hi)
                    {
                        ll mid = lo + (hi - lo) / 2;

                        ll L = mid;
                        ll R = L + min(m - 1, LIM - L);

                        ll marked = getMarked(L, R);
                        ll len = R - L + 1;

                        if (len == m && marked == k)
                        {
                            st = L;
                            break;
                        }

                        if (marked > k)
                        {
                            lo = mid + 1;
                        }

                        else
                        {

                            hi = mid - 1;
                        }
                    }
                }
            }
            //end1
            if (st == -1)
            {
                for (ll i = 0; i < sz && st == -1; i++)
                {
                    ll lo = segs[i].first;
                    ll hi = segs[i].second;

                    while (lo <= hi)
                    {
                        ll mid = lo + (hi - lo) / 2;

                        if (mid < m)
                        {
                            lo = mid + 1;
                            continue;
                        }

                        ll R = mid;
                        ll L = R - m + 1;

                        ll marked = getMarked(L, R);

                        if (marked == k)
                        {
                            st = L;
                            break;
                        }

                        if (marked > k)
                            hi = mid - 1;
                        else
                            lo = mid + 1;
                    }
                }
            }
             //end2
            if (st == -1)
            {
                for (ll i = 0; i < sz && st == -1; i++)
                {
                    ll lo = segs[i].first;
                    ll hi = segs[i].second;

                    while (lo <= hi)
                    {
                        ll mid = lo + (hi - lo) / 2;

                        if (mid < m)
                        {
                            lo = mid + 1;
                            continue;
                        }

                        ll R = mid;
                        ll L = R - m + 1;

                        ll marked = getMarked(L, R);

                        if (marked == k)
                        {
                            st = L;
                            break;
                        }

                        if (marked > k)
                             lo = mid + 1;
                        else
                           
                            hi = mid - 1;
                    }
                }
            }
        }
        else
        {
            for (ll i = 0; i < sz && st == -1; i++)
            {
                ll lo = segs[i].first;
                ll hi = segs[i].second;

                if (lo > 1)
                {
                    ll R = lo - 1;

                    if (R >= m)
                    {
                        ll L = R - m + 1;

                        if (getMarked(L, R) == 0)
                        {
                            st = L;
                            break;
                        }
                    }
                }

                if (hi < LIM)
                {
                    ll L = hi + 1;
                    ll R = L + min(m - 1, LIM - L);

                    if (R - L + 1 == m &&
                        getMarked(L, R) == 0)
                    {
                        st = L;
                        break;
                    }
                }
            }
        }

        cout << st << '\n';
    }

    return 0;
}
