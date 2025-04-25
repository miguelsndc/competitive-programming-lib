#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

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
constexpr int mod = 1e9 + 7, maxn = 3e5 + 5;
vector<pair<int, int>> v(maxn);

#define ff first
#define ss second

void solve() {
    int n;
    cin >> n;
    vector<int> colors(n + 1);
    set<pair<int, int>> s;
    for (int i = 1; i <= n; i++) {
        cin >> colors[i];
        v[colors[i]].ff = (v[colors[i]].ff == 0 ? i : min(i, v[colors[i]].ff));
        v[colors[i]].ss = max(i, v[colors[i]].ss);
    }
    for (int l = 1; l <= n; l++) {
        int r = l;
        while (r + 1 <= n and colors[l] == colors[r + 1]) r++;
        s.insert({l, r});
        l = r;
    }

    int m;
    cin >> m;
    while (m--) {
        int q;
        cin >> q;
        auto [first, last] = v[q];
        auto x = s.lower_bound({first, -1});
        auto y = s.lower_bound({1e9, last});
        pair<int, int> new_int = {first, last};
        auto it = x;
        while (it != y) {
            s.erase(it++);
        }
        s.insert({first, last});
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