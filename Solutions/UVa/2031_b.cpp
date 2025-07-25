#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (abs(a[i] - i) > 1) {
            ok = false;
        }
    }
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}