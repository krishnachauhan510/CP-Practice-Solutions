#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
ll t;
cin>>t;
while(t--){
ll n;
cin>>n;
vector<ll>a(3);

for(ll i=0;i<3;i++){
cin>>a[i];}
ll mn=a[0];
for(ll i=0;i<3;i++){
mn=min(mn,a[i]);
}
cout<<n-mn<<endl;

}}