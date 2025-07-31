#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; cin >> n;
    const int mxn = 1e6 + 6;
    vector<ll> a(n), dp(mxn);
    for (int i = 0; i < n; i++) {
        cin >> a[i];    
    }
    dp[0] = 1;
    ll s = accumulate(a.begin(), a.end(), 0LL); 
    for (auto x: a) {
        for (int sum = s; sum >= x; sum--) {
            dp[sum] |= dp[sum - x];
        }
    }
    vector<ll> ans;
    for (int i = 1; i <= s; i++) {
        if (dp[i]) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (auto x: ans) {
        cout << x << ' ';
    }
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; // cin >> T;
    while(T--) solve();
}
