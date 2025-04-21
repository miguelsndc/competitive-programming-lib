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
constexpr int mod = 1e9 + 7, maxn = 3e5 + 5;

vector<int> par(maxn), sz(maxn);

int find(int a) {
    return par[a] == a ? a : par[a] = find(par[a]);
}

bool join(int a, int b) {
    int ar = find(a), br = find(b);
    if (ar == br) return false;
    if (sz[ar] < sz[br]) swap(ar, br);
    sz[ar] += sz[br];
    par[br] = ar;
    return true;
}

void solve() {
    iota(all(par), 0);
    fill(all(sz), 1);

    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        int ai, bi;
        cin >> ai >> bi;
        // each connected component of drawes ean that any drawer can reach any other in that
        // component, if there's free space there then we can put it, otherwise we try
        // with bi, if we can then we merge the two and decrement the capacity
        if (sz[find(ai)] > 0 || sz[find(bi)] > 0) {
            join(ai, bi);
            sz[find(ai)]--;
            cout << "LADICA\n";
        } else {
            cout << "SMECE\n";
        }
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