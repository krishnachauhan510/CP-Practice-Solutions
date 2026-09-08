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
		ll n;
		cin>>n;
		vector<ll>a(n);
		for(ll i=0;i<n;i++){
			cin>>a[i];
		}
		ll cnt0=0;
		ll cnt=0;
		for(ll i=0;i<n;i++){
			if(a[i]==0){
				cnt++;
			}
			if(i==0||i==n-1){
				if(a[i]==0){
					cnt0++;
				}
			}
		}
		if(cnt<2){
			cout<<-1<<endl;
		}
		else{
			if(cnt0==2){
				cout<<0<<endl;
			}
			else if(cnt0==1){
				cout<<1<<endl;
			}
			else{
				cout<<2<<endl;
			}
		}
	}

	return 0;
}