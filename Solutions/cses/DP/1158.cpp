#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> h(n), s(n);
    for (int &x : h) cin >> x;
    for (int &x : s) cin >> x;
    vector<int> f(x + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int w = x; w >= 1; w--) {
            if (w - h[i] >= 0)
                f[w] = max(f[w], f[w - h[i]] + s[i]);
        }
    }
    cout << *max_element(all(f)) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}