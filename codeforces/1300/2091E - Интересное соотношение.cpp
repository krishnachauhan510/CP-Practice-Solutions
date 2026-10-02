#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> primes;
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (ll i = 2; i * i <= n; i++)
        {
            if (is_prime[i])
            {
                for (ll j = i * i; j <= n; j += i)
                {
                    is_prime[j] = false;
                }
            }
        }
        ll ans = 0;
        for(ll i = 2; i <= n; i++)
        {
            if (is_prime[i])
            {
               ans+=(n/i);
            }
        }
        cout<< ans<<"\n";
    }
}