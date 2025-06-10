#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
using ii = pair<int, int>;
const int maxn = 2e5 + 5;
const ll inf = 1e18;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve() {
    int n, x;
    cin >> n >> x;

    auto print_b = [&](int x) {
        string s = "";
        for (int i = 0; i < 32 - __builtin_clz(x); i++) {
            if (x & (1 << i)) {
                s += '1';
            } else {
                s += '0';
            }
        }
        reverse(all(s));
        cout << n << ' ' << s << '\n';
    };
    print_b(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}