#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    int n, m; cin >> n >> m;
    int k = (m + 1) / 2;
    int i = k - 1, j = k + 1;
    vector<int> v;
    v.push_back(k);
    for (int x = 0; x < n; x++) {
        if (i >= 1) v.push_back(i--);
        if (j <= n) v.push_back(j++);
    }
    for (int x: v) {
        cout << x << "\n";
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) {
        solve();
    }
}