#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5, LIM = 1e7 + 5;

vector<bool> prime(LIM, true); vector<int> factor(LIM);
void sieve() {
    iota(all(factor), 0);
    prime[0] = prime[1] = false;
    for (int i = 2; i < LIM; i++) {
        if (prime[i]) {
            factor[i] = i;
            for (int j = i * 2; j < LIM; j += i) prime[j] = false, factor[j] = i;
        }
    }
}
vector<int> cnt(LIM);
void solve() {
    sieve();
    int n;
    cin >> n;
    vector<int> v(n); 
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (prime[v[i]]) cnt[v[i]]++;
    }

    for (int i = 0; i < LIM; i++) {
        if (cnt[i] > 2) {
            cout << "NO\n";
            return;
        }
    }

    vector<pair<int, int>> ans;
    ans.reserve(n);
    set<pair<int, int>> seen;
    for (int x : v) {
        int a = 1, b = x;
        bool found = false;

        while (!found) {
            if (!seen.count({a, b})) {
                seen.insert({a, b});
                found = true;
                continue;
            }
            if (!seen.count({b, a})) {
                seen.insert({b, a});
                found = true;
                swap(a, b);
                continue;
            }

            if(b == 1) break;

            a *= factor[b];
            b /= factor[b];
        }

        ans.push_back({a, b});

        if (!found) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}