#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        if(n==k||k==1){
            if(n==k){
                for(int i=0;i<n;i++){
                    cout<<1<<" ";
                }
                cout<<endl;
            }
            else{
                for(int i=0;i<n;i++){
                    cout<<i+1<<" ";
                }
                cout<<endl;
            }

        }
        else{
            cout<<-1<<endl;
        }
    }
}