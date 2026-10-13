
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll mn=n%10;
        while(n>0){
            ll last=n%10;
            n/=10;
            mn=min(mn,last);

        }
        cout<<mn<<endl;
    }
}
