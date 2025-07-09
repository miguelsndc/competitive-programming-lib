#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    int n;
    cin >> n;
    vector C(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> C[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (C[i][j] > C[i][k] + C[k][j]) {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool removable = false;
            for (int k = 0; k < n; k++) {
                if (k != i and k != j) {
                    if (C[i][j] == (C[i][k] + C[k][j])) {
                        removable = true;
                        break;
                    }
                }
            }
            if (removable) cnt++;
        }
    }

    cout << cnt << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}