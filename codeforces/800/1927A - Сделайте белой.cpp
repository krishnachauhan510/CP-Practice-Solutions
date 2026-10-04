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
        string s;
        cin>>s;
        ll fb=n,lb=-1;
        for(ll i=0;i<n;i++){
            if(s[i]=='B'){
                fb=min(fb,i);
                lb=max(lb,i);
            }
        }
        if(fb==-1){
            cout<<0<<endl;
        }
        else{
            cout<<lb-fb+1<<endl;
        }
    }

    
    return 0;
}