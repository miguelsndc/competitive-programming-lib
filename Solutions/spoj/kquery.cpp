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
constexpr int mod = 1e9 + 7, maxn = 3e4 + 5;

int n;
vector<int> tree[4 * maxn], a;

void build(int l = 0, int r = n - 1, int v = 0) {
    if (l == r) {
        tree[v].push_back(a[l]);
    } else {
        int m = (l + r) / 2;
        build(l, m, v * 2 + 1);
        build(m + 1, r, v * 2 + 2);
        int i = 0, j = 0;
        while (i < tree[v * 2 + 1].size() and j < tree[v * 2 + 2].size()) {
            if (tree[v * 2 + 1][i] < tree[v * 2 + 2][j])
                tree[v].push_back(tree[v * 2 + 1][i++]);
            else
                tree[v].push_back(tree[v * 2 + 2][j++]);
        }
        while (i < tree[v * 2 + 1].size())
            tree[v].push_back(tree[v * 2 + 1][i++]);
        while (j < tree[v * 2 + 2].size())
            tree[v].push_back(tree[v * 2 + 2][j++]);
    }
}

int query(int a, int b, int k, int l = 0, int r = n - 1, int v = 0) {
    if (b < l || a > r) return 0;
    if (l >= a and r <= b) {
        int lo = 0, hi = tree[v].size() - 1, ans = tree[v].size();
        while (lo <= hi) {
            int m = (lo + hi) / 2;
            if (tree[v][m] > k) {
                ans = m;
                hi = m - 1;
            } else {
                lo = m + 1;
            }
        }
        int x = tree[v].size() - ans;
        return x;
    }
    int m = (l + r) / 2;
    int half1 = query(a, b, k, l, m, v * 2 + 1);
    int half2 = query(a, b, k, m + 1, r, v * 2 + 2);
    return half1 + half2;
}

void solve() {
    int sz;
    cin >> sz;
    n = sz;
    a.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    build();
    int q;
    cin >> q;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        --l, --r;
        cout << query(l, r, k) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}