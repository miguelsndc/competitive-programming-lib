#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        vector<int> p(n);
        for (int &x:p) cin >> x;
        vector<int> lds(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (p[i] < p[j] and lds[i] < lds[j] + 1) {
                    lds[i] = lds[j] + 1;
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += abs(lds[i] - lds[j]);
            }
        }
        cout << ans + n<< '\n';
    }
}
