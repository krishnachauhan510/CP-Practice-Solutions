#include <bits/stdc++.h>
using namespace std;

#define ll long long
// PGE
vector<ll> PGE(vector<ll> &a)
{
    ll n = a.size();
    vector<ll> ans(n, -1);
    stack<ll> st;

    for (ll i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] <= a[i])
            st.pop();

        if (!st.empty())
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

// PSE
vector<ll> PSE(vector<ll> &a)
{
    ll n = a.size();
    vector<ll> ans(n, -1);
    stack<ll> st;

    for (ll i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();

        if (!st.empty())
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
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
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<ll> pse = PSE(a), pge = PGE(a);
       
        ll q;
        cin >> q;
        while (q--)
        {
            ll l, r;
            cin >> l >> r;
            l--;r--;
            ll psee = pse[r];
            ll pgee = pge[r];
            //cout<<psee<<" "<<" "<<pgee<<" ";
            if (psee!=-1&&psee >= l)
            {
               // cout<<"pse";
                cout<<psee+1<<" "<<r+1<<endl;
            }
            else if (pgee!=-1&&pgee >= l)
            {
                //cout<<"pge";
                  cout<<pgee+1<<" "<<r+1<<endl;
            }
            else
            {
                //cout<<"none";
                cout<<-1<<" "<<-1<<endl;

            }
        }
        cout<<endl;
    }

    return 0;
}