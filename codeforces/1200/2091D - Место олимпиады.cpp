
#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool check(ll n,ll m,ll k,ll mid){
    ll val=((m/(mid+1))*mid)+(m%(mid+1));
    val=val*n;
    if(val>=k){
        return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        ll lo=1,hi=m;
        ll ans=-1;
        while(lo<=hi){
            ll mid=(lo+hi)/2;
            if(check(n,m,k,mid)){
                hi=mid-1;
                ans=mid;
            }
            else{
                lo=mid+1;
            }
        }
        cout<<ans<<endl;
    }
}
