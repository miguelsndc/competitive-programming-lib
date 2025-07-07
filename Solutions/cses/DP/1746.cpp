#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    int n, m;
    cin >> n >> m;
    vector f(n + 5, vector<ll>(m + 5));
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (a[1] == 0) {
        for (int i = 1; i <= m; i++) f[1][i] = 1;
    } else {
        f[1][a[1]] = 1;
    }

    const int mod = 1e9 + 7;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == 0) {
                f[i][j] = (f[i - 1][j] + f[i - 1][j - 1] + f[i - 1][j + 1]) % mod;
            } else if (j == a[i]) {
                f[i][j] = (f[i - 1][j] + f[i - 1][j - 1] + f[i - 1][j + 1]) % mod;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += (f[n][i]);
        ans %= mod;
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}