#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int cnt = 0;
    for (int x : a) {
        if (h >= x) {
            cnt++;
        }
    }
    cout << cnt << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}