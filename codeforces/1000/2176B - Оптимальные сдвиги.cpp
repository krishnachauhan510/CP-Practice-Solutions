#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 2e5 + 5;
ll pre[N];

ll cnt3(ll n)
{
    ll cnt = 0;

    while (n > 0)
    {
        n /= 3;
        cnt++;
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (ll i = 1; i < N; i++)
    {
        pre[i] = pre[i - 1] + cnt3(i);
    }

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll pref = 0, suff = 0, ans = 0, cnt = 0;

        for (char c : s)
        {
            if (c == '0')
                cnt++;
            else
                cnt = 0;
            ans = max(ans, cnt);
        }

        while (pref < n && s[pref] == '0')
            pref++;
        while (suff < n && s[n - 1 - suff] == '0')
            suff++;

        ans = max(ans, pref + suff);
        ll anss=0;
        /*

        for(ll i=0;i<=63;i++){
            ll val=1<<i;
            if(ans>0){
                ans-=val;
                anss=i+1;
            }
            else{
                break;
            }

        }
        */
        cout<<ans<<endl;
    }

    return 0;
}