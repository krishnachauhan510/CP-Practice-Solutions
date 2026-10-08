#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n + 1), b(n + 1), c(n + 1);
        vector<ll> pre1(n + 2), suf(n + 2),pre2(n+2);
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (ll i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        pre1[0] = 0;
        for (ll i = 1; i <= n; i++)
        {
            ll val1 = (a[i] == b[i] ? 2 : 1);
            pre1[i] = pre1[i - 1] + val1;
             pre2[i] = pre2[i - 1] + val1;
            if (i >= 2)
            {
                ll val2 = (a[i] == b[i - 1] ? 2 : 1);
                pre1[i] += val2;
            }
             if (i >= 2)
            {
                ll val2 = (b[i] == a[i - 1] ? 2 : 1);
                pre2[i] += val2;
            }
        }
        suf[n + 1] = 0;
        for (ll i = n; i >= 1; i--)
        {
            if (i == n)
            {
                ll val1 = (a[i] == b[i] ? 2 : 1);
               suf[i]=val1;
            }
            else{
                ll val1 = (a[i] == b[i+1] ? 2 : 1);
                ll val2 = (a[i+1] == b[i] ? 2 : 1);
                suf[i]=suf[i+1]+val1+val2;

            }
        }
        ll ans=0;
        
        
       
        for(ll i=1;i<=n;i++){
            ans=max(ans,pre1[i]);
        
            ll val1 = (a[i] == b[i] ? 2 : 1);
            ans=max(ans,pre1[i]+suf[i]-val1);
          
        }
       cout<<ans<<endl;
    }
}