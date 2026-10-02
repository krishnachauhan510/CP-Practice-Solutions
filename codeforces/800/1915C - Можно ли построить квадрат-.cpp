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
        ll n;
        cin >> n;
        vector<ll> a(n);
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        ll m = sqrt(sum);
        if (m * m != sum)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}