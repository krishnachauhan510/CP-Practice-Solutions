#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>a(n);
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        vector<ll>pre(n,0);//positive
        vector<ll>suf(n,0);//negative
        if(a[0]>0){
            pre[0]=a[0];
        }
        if(a[n-1]<0){
            suf[n-1]=abs(a[n-1]);
        }
        for(ll i=1;i<n;i++){
            if(a[i]>0){
                pre[i]=pre[i-1]+a[i];
            }
            else{
                pre[i]=pre[i-1];
            }
        }
        for(ll i=n-2;i>=0;i--){
            if(a[i]<0){
                suf[i]=suf[i+1]+abs(a[i]);
            }
            else{
                suf[i]=suf[i+1];
            }
        }
        ll ans=0;
        for(ll i=0;i<n;i++){
            ans=max(ans,suf[i]+pre[i]);
        }
        cout<<ans<<endl;
    }

   
    return 0;
}