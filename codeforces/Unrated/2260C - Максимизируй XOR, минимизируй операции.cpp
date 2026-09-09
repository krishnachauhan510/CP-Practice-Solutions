#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll sroot(ll x)
{
	ll l = 0, r = x;
	while (l <= r)
	{
		ll m = (l + r) >> 1;
		m *m <= x ? l = m + 1 : r = m - 1;
	}
	return r;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll t;
	cin >> t;
	while (t--)
	{
		
		ll x,y;
		cin>>x>>y;
		ll sum=x+y;
		ll a=0;

		for(ll i=30;i>=0;i--){
			if((sum>>i)&1LL){
				ll c=a|(1LL<<i);
				if(c<=x){
					a=c;
				}
			}
		}
		cout<<sum<<" "<<(x-a)<<endl;
	}

	return 0;
}