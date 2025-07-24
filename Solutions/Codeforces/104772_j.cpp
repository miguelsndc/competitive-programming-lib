#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int lb = (lower_bound(b.begin(), b.end(), x) - b.begin());
        s.insert(lb);
    }
    cout << s.size() << '\n';
    for (int x: s) {
        cout << x << ' ';
    }
}