#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

void solve() {
    int n; cin >> n;
    i64 soma_p = 0, soma_s = 0;
    string s1, s2;
    bool p1_ultimo = false;
    while(n--) {
        int a; cin >> a;
        p1_ultimo = (a > 0);
        if (a > 0) {
            soma_p += a;
            s1 += to_string(a);
        } else {
            soma_s -= a;
            s2 += to_string(-a);
        }
    }

    if (soma_p > soma_s) {
        cout << "first"; return;
    } else if (soma_p < soma_s) {
        cout << "second"; return;
    }

    for (int i = 0; i < min(s1.size(), s2.size()); i++) {
        if ((s1[i] - '0') > (s2[i] - '0')) {
            cout << "first"; return;
        } else if ((s1[i] - '0') < (s2[i] - '0')) {
            cout << "second"; return;
        }
    }
    
    if (s1.size() > s2.size()) {
        cout << "first"; return;
    } else if (s1.size() < s2.size()){
        cout << "second"; return;
    }

    if (p1_ultimo) {
        cout << "first";
    } else {
        cout << "second";
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