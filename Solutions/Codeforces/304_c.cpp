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
    vector<int> c(n), b(n), a(n);

    iota(all(c), 0);
    iota(rall(b), 0);

    if (n % 2 == 0) {
        cout << -1 << '\n';
        return;
    }

    for (int i = 1; i >= 0; i--) {
        for (int j = i; j < n; j += 2) {
            cout << j << ' ';
        }
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << b[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << c[i] << ' ';
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