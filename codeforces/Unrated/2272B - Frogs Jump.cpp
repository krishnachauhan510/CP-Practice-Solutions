#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        auto tot = ranges::count(s1, 'f') + ranges::count(s2, 'f');
        cout << tot % 2 << '\n';
    }
    return 0;
}