#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>

#ifdef CARNEDESOOOL
#define debug(...) dbg(#__VA_ARGS__, __VA_ARGS__)
template <typename... T>
void dbg(const char* names, T... args) {
    const char* p = names;
    ((cout << string(p, strchr(p, ',') ? strchr(p, ',') : p + strlen(p)) << " = " << args << '\n',
      p = strchr(p, ',') ? strchr(p, ',') + 1 : p + strlen(p)),
     ...);
}
#else
#define debug(...)
#endif

using ll = long long;

constexpr ll inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    int len = sqrt(n + .0) + 1;
    vector<vector<int>> b(len);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i / len].push_back(a[i]);
    }
    // sqrt(n) * sqrt(n) log(sqrt(n)) ~ n log (n)
    for (int i = 0; i < len; i++) {
        sort(all(b[i]));
    }
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;

        if (t) {
            int k, u;
            cin >> k >> u;
            --k;
            int block = k / len;
            b[block].erase(find(all(b[block]), a[k]));
            b[block].push_back(u);
            sort(all(b[block]));
            a[k] = u;
        } else {
            int l, r, c;
            cin >> l >> r >> c;
            --l, --r;

            int bl = l / len, br = r / len;

            int ans = 0;
            if (bl == br) {
                for (int i = l; i <= r; i++) {
                    if (a[i] >= c) ans++;
                }
            } else {
                for (int i = l, end = (bl + 1) * len - 1; i <= end; i++) {
                    if (a[i] >= c) ans++;
                }
                for (int i = bl + 1; i <= br - 1; i++) {
                    ans += len - (lower_bound(all(b[i]), c) - begin(b[i]));
                }
                for (int i = br * len; i <= r; i++) {
                    if (a[i] >= c) ans++;
                }
            }
            cout << ans << '\n';
        }
    }
}
// sqrt (n) + sqrt(n) log sqrt(n)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}