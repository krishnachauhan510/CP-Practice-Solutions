
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
        cin >> n;
        vector<vector<ll>> a(2, vector<ll>(n));
        a[0][0] = 2 * n - 1;
        a[1][n - 1] = 2 * n;
        ll k = 1;
        for (ll i = 0; i < n-1; i+=2)
        {
            a[1][i] = k;
            a[0][i+1]=k+1;
            k+=2;
        }
       
        for (ll i = 1; i < n - 1; i+=2)
        {
            
            a[1][i] = k;
            a[0][i+1]=k+1;
            k += 2;
        }
        for(ll i=0;i<2;i++){
            for(ll j=0;j<n;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
