#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--)
    {
        ll x,y,r;
        cin>>x>>y>>r;
        cout<<x+r<<" "<<y<<endl;
    }

    return 0;
}