#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll inv2 = 500000004;
void solve() {
    ll n; cin >> n;
    ll sum = n * (n + 1) / 2;
    if (sum % 2) {
        cout << 0 << '\n';
        return;
    }
    vector<ll> dp(sum + 1);
    dp[0] = 1;
    for (ll x = 1; x <= n; x++) {
        for (ll s = sum; s >= x; s--) {
            (dp[s] += dp[s - x]) %= mod;
        }
    }
    cout << dp[sum / 2] * inv2 % mod << '\n';
}
int main() {
    int T = 1; // cin >> t;
    while(T--) solve();
}