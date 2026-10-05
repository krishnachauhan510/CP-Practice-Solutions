#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);

    for (auto &x : a)
        cin >> x;

    set<ll> st;
    st.insert(0);

    ll sum = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];

        if (st.count(sum))
        {
            ans++;

            st.clear();
            st.insert(0);

            sum = 0;
        }
        else
        {
            st.insert(sum);
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}