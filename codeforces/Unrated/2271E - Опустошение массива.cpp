
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 200020

ll T,n,k,a[N];

bool check(ll m)
{
    priority_queue<ll> q;

    for(ll i=1;i<=n;i++) q.push(a[i]);

    ll tot=k+n+2*m,cnt=0;

    while(!q.empty())
    {
        ll sz=q.size();

        if(tot-sz<k) return false;

        cnt++;
        if(cnt>n+2*m) return false;

        tot--;

        ll x=q.top();
        q.pop();

        if(x<=tot) continue;

        ll y=(x+1)/2;
        q.push(y);
        q.push(y);
        tot++;
    }

    return tot>=k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>T;

    while(T--)
    {
        cin>>n>>k;

        for(ll i=1;i<=n;i++) cin>>a[i];

        ll l=0,r=n+1,mid;

        while(l<r)
        {
            mid=(l+r)/2;

            if(check(mid)) r=mid;
            else l=mid+1;
        }

        cout<<n+2*l<<'\n';
    }

    return 0;
}
