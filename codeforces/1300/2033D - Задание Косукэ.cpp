#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;

    vector<ll> dp(n + 1, 0);

    // prefix sum -> latest index
    map<ll, int> mp;

    ll sum = 0;

    // prefix sum 0 occurs at index 0
    mp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;

        sum += x;

        // Don't take any segment ending at i
        dp[i] = dp[i - 1];

        // If same prefix sum existed before,
        // then (previous_index + 1 ... i) has sum 0
        if (mp.find(sum) != mp.end())
        {
            int j = mp[sum];

            dp[i] = max(dp[i], dp[j] + 1);
        }

        // Store latest occurrence
        mp[sum] = i;
    }

    cout << dp[n] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}