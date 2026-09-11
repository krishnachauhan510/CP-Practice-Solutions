#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> divisors(ll n)
{
    vector<ll> v;

    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);

            if (i != n / i)
                v.push_back(n / i);
        }
    }

    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll w, h, d, n;
    cin >> w >> h >> d >> n;

    bool flag = false;
    ll answ, ansh, ansd;

    vector<ll> wd = divisors(w);
    vector<ll> hd = divisors(h);
    vector<ll> dd = divisors(d);

    for (ll i = 0; i < wd.size(); i++)
    {
        for (ll j = 0; j < hd.size(); j++)
        {
            for (ll k = 0; k < dd.size(); k++)
            {
                ll pieces = (w / wd[i]) * (h / hd[j]) * (d / dd[k]);
               

                if (pieces == n)
                {
                     //cout<<wd[i]<<" "<<hd[j]<<" "<<dd[k]<<" ";
                    flag = true;

                    answ = (w / wd[i]) - 1;
                    ansh = (h / hd[j]) - 1;
                    ansd = (d / dd[k]) - 1;

                    break;
                }
            }

            if (flag) break;
        }

        if (flag) break;
    }

    if (flag){
       cout << answ << " " << ansh << " " << ansd << '\n';
    }
    else{
        cout << -1 << '\n';}

    return 0;
}