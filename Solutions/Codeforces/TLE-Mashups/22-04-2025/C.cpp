#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

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

using i64 = long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

void solve() {
    string s, t, p;
    cin >> s >> t >> p;
    // remove from p, insert into s so it becomes t
    map<char, int> freq, freq2;
    for (char c : s) {
        freq[c]++;
    }
    for (char c : p) {
        freq[c]++;
    }
    for (char c : t) {
        freq2[c]++;
    }

    int i = 0, j = 0;
    while (i < s.size() and j < t.size()) {
        if (s[i] == t[j]) {
            i++, j++;
        } else {
            j++;
        }
    }

    if (i < s.size()) {
        cout << "NO\n";
        return;
    }

    for (auto [ch, fr] : freq2) {
        if (freq[ch] < fr) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}