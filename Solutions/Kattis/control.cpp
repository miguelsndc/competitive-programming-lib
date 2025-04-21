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

using i64 = long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7;

#ifdef CARNEDESOOOL
#define maxn 200
#else
#define maxn 500005
#endif

vector<int> par(maxn), sz(maxn, 1);

void solve() {
    iota(all(par), 0);
    int n;
    cin >> n;

    function<int(int)> find = [&](int x) {
        return par[x] == x ? x : par[x] = find(par[x]);
    };

    function<int(int, int)> join = [&](int a, int b) -> int {
        int ar = find(a), br = find(b);
        if (ar == br) return false;
        if (sz[ar] < sz[br]) swap(ar, br);
        sz[ar] += sz[br];
        par[br] = ar;
        return true;
    };

    int ans = 0;
    map<int, int> cnt;
    set<int> roots;
    for (int i = 0; i < n; i++) {
        int m, ok = true;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            cnt[find(x)]++;
            roots.insert(find(x));
        }

        for (auto r : roots) {
            if (cnt[r] != sz[r]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            int repr = *roots.begin();
            for (auto r : roots) {
                if (r != repr) {
                    join(repr, r);
                }
            }
            ans++;
        }

        cnt.clear();
        roots.clear();
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}