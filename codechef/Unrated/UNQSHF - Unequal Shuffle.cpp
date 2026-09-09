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
        ll n;
        cin >> n;

        string a, b;
        cin >> a >> b;
        ll caa = 0, cbb = 0, cba = 0, cab = 0;
        for (ll i = 0; i < n; i++)
        {
            if (a[i] == 'a')
            {
                caa++;
            }
            else if(a[i]=='b'){
                cba++;
            }
            if(b[i]=='a'){
                cab++;
            }
            else if(b[i]=='b'){
                cbb++;
            }
        }

        if(caa==cbb&&cba==cab){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}