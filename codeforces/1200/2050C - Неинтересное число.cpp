#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool rec(ll ind, ll sum, const vector<ll>& a, vector<vector<ll>>& dp)
{
    if (ind == a.size())
    {
        return sum % 9 == 0;
    }

    sum %= 9;

    if (dp[ind][sum] != -1)
    {
        return dp[ind][sum];
    }

    // Pick
    ll newSum = (sum - a[ind] + a[ind] * a[ind]) % 9;
    bool pick = rec(ind + 1, newSum, a, dp);

    // Not pick
    bool not_pick = rec(ind + 1, sum, a, dp);

    return dp[ind][sum] = pick || not_pick;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        string x;
        cin >> x;

        ll sum = 0;
        vector<ll> a;

        for (ll i = 0; i < x.size(); i++)
        {
            ll digit = x[i] - '0';

            sum += digit;

            if (digit == 2 || digit == 3)
            {
                a.push_back(digit);
            }
        }

     
        vector<vector<ll>> dp(a.size(), vector<ll>(9, -1));

        bool ans = rec(0, sum % 9, a, dp);

        if (ans)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}