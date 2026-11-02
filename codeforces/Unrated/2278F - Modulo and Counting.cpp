#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998'244'353;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<ll> dp(m + 3, 0);
        dp[m + 2] = 1;

        ll ans = 0;

        for(int i = 1; i < n; i++){

            ll sum = (dp[2] + dp[3]) % mod;
            int left = 2, right = 3;

            for(int j = 2; j < m + 3; j++){

                ll temp = sum;

                sum += (mod - dp[left]);
                left++;

                right++;
                if(right < m + 3) sum += dp[right];

                right++;
                if(right < m + 3) sum += dp[right];

                sum %= mod;
                dp[j] = temp;
            }

            ans += dp[2];
            ans %= mod;
        }

        cout << ans << '\n';
    }

    return 0;
}