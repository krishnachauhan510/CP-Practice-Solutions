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
        
        //time display HH MM
        ll n;
        cin>>n;
        string s;
        cin>>s;
        sort(s.begin(), s.end());
        
        vector<ll>mark(n,0);
        ll l=0,r=n-1;
        ll hr=0;
        ll doub=0;
        while(l<r){
            ll val=(s[l]-'0')*10+(s[r]-'0');
            if(val<=11){
                hr++;
                if(val==0||val==10||val==11){
                    doub++;
                }
              
                mark[l]=1;
                mark[r]=1;
            }
            l++;
            r--;
        }
        ll cnt1=0;
        for(ll i=0;i<n;i++){
            if(s[i]=='1'&&mark[i]==0){
                cnt1++;
            }
        }
         hr+=(cnt1/2);
         doub+=(cnt1/2);
        cnt1=cnt1%2;
        vector<ll>left;
        if(cnt1){
            left.push_back(1);
        }
        for(ll i=0;i<n;i++){
            if(mark[i]==0&&s[i]!='0'&&s[i]!='1'){
                left.push_back(s[i]-'0');
            }
        }
        l=0;
        r=left.size()-1;
        ll mm=0;
        vector<ll>lef;
        while(l<r){
             ll val=left[l]*10+left[r];
             if(val<=59){
                mm++;
             }
             else{
                lef.push_back(left[l]);
                lef.push_back(left[r]);

             }
             l++;
             r--;
        }
        //cout<<mm<<" "<<hr<<endl;
        if(mm>=hr){
            cout<<hr<<endl;

        }
        else{
            //hame kuch minute badhana
            ll k=0;
            bool e=true;
            ll cnt=0;
            while(doub>0&&hr>mm&&k<(lef.size())){
                
                if(e==true){
                    doub--;
                    hr--;
                    e=false;

                }
                else{
                    e=true;
                }
                 mm++;
                 k++;

               

            }
            ll ans=min(hr,mm);
            if(hr-mm>0){
                ans+=((hr-mm)/2);
            }
            cout<<ans<<endl;
           

        }

       




       
    }
}