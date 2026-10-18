#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        ll ans1=0;
        for(ll i=1;i<=1e3;i++){
            if(a==b||b==c||a==c){
                break;
            }
            ans1=max(ans1,i);
            ll mx=max({a,b,c});
            ll mn=min({a,b,c});
            if(a==mx){
                //bc
                a-=1;
                if(b==mn){
                    b+=1;

                }else{
                    c+=1;

                }

            }
            else if(b==mx){
                //ac
                b-=1;
                if(a==mn){
                    a+=1;

                }else{
                    c+=1;
                    
                }

            }
            else{
                //ab
                c-=1;
                if(a==mn){
                    a+=1;

                }else{
                    b+=1;
                    
                }
            }
        }
        cout<<ans1<<endl;
    }
    return 0;
}