#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

int pega(int x) {
    int ar[] = {0, 0, 0, 0, 0, 0};
    int k = x;
    for (int i = 0; i < 6; i++) {
        ar[i] = k % 10;
        k /= 10;
    }
    return abs((ar[3] + ar[4] + ar[5]) - (ar[0] + ar[1] + ar[2]));
}

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first; v[i].second = i;
    }
    sort(all(v));
    i64 cur = 0; vector<int> cnt(30);
    for (int i = 0; i < n; i++) {
        int x = 0;
        for (;cur < v[i].first; cur++) {
            x = pega(cur);
            cnt[x]++;
        }
        int k = pega(v[i].first), val = 0;
        for (int j = 0; j < k; j++) {
            val += cnt[j];
        }
        ans[v[i].second] = val;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
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