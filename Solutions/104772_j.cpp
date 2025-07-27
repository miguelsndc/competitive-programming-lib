#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int &x:a) cin >> x;
    for (int &x:b) cin >> x;
    int quantos = lower_bound(b.begin(), b.end(), a.back()) - b.begin();
    int qntsmenor = lower_bound(b.begin(), b.end(), a[0]) - b.begin();
    cout << quantos - qntsmenor + 1 << '\n';
    for (int i = qntsmenor; i <= quantos; i++) {
        cout << i << ' ';
    }
}
