#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<ll>> mergeOverlap(vector<vector<ll>> &arr)
{
    sort(arr.begin(), arr.end());

    vector<vector<ll>> res;

    if (arr.empty())
        return res;

    res.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++)
    {
        vector<ll> &last = res.back();
        vector<ll> &curr = arr[i];

        if (curr[0] <= last[1])
            last[1] = max(last[1], curr[1]);
        else
            res.push_back(curr);
    }

    return res;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, m, l;
        cin >> n >> m >> l;

        vector<vector<ll>> v(n, vector<ll>(2));

        for (ll i = 0; i < n; i++)
        {
            cin >> v[i][0] >> v[i][1];
        }

        // {position, power}
        vector<pair<ll, ll>> powerups(m);

        for (ll i = 0; i < m; i++)
        {
            cin >> powerups[i].first >> powerups[i].second;
        }

        vector<vector<ll>> hurdle = mergeOverlap(v);

        sort(powerups.begin(), powerups.end());

        priority_queue<ll> pq;

        ll cnt = 0;
        ll k = 1;
        ll j = 0;

        bool flag = true;

        for (auto &it : hurdle)
        {
            ll a = it[0];
            ll b = it[1];

            while (j < m && powerups[j].first < a)
            {
                pq.push(powerups[j].second);
                j++;
            }

            ll val = b - a + 1;

            while (k <= val)
            {
                if (pq.empty())
                {
                    break;
                }

                k += pq.top();
                pq.pop();
                cnt++;
            }

            if (k <= val)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cout << cnt << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
    }

    return 0;
}