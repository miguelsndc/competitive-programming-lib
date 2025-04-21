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
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

vector<int> par(maxn), sz(maxn, 1), sum(maxn);

int find(int a) {
    return par[a] == a ? a : par[a] = find(par[a]);
}

int join(int a, int b) {
    int ar = find(a), br = find(b);
    if (ar == br) return false;
    if (sz[ar] < sz[br]) swap(ar, br);
    sz[ar] += sz[br];
    sum[ar] += sum[br];
    par[br] = ar;
    return true;
}

void solve() {
    int n, m;
    while ((cin >> n >> m)) {
        iota(all(par), 0);
        iota(all(sum), 0);
        int t;
        cin >> t;
        if (t == 1) {
        } else if (t == 2) {
        } else {
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while (tt--) {
        solve();
    }
}