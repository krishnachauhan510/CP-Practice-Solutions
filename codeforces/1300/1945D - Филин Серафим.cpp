#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n + 1), b(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (ll i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        vector<ll> suff(n + 3, 0);
        for (ll i = n; i >= 1; i--)
        {
            suff[i] = suff[i + 1] + min(a[i], b[i]);
        }
         for (ll i = 1; i <=n; i++)
        {
          // cout<<suff[i]<<" ";
        }
       // cout<<endl;
 
        ll ans=LLONG_MAX;
        for(ll i=1;i<=m;i++){
            ll x=a[i]+suff[i+1];
            //cout<<x<<" ";
            ans=min(ans,x);
        }//cout<<endl;
        cout<<ans<<endl;
    }
}