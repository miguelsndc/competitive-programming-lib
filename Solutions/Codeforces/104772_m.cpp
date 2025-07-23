#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
bool equal(char c, char d) {
    if (c >= 'A' and c <= 'Z') c -= 32;
    if (d >= 'A' and d <= 'Z') d -= 32;
    return c == d;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s, f; cin >> s >> f;
    int i = 0, j = 0;
    while (i < s.size() and j < s.size()) {
        if (equal(s[i], f[j])) i++, j++;
        else {
            while(!equal(s[i], f[j])) {
                j++;
            }
        }
    }
    cout << s.size() << ' ' << f.size() << '\n';
    cout << i << ' ' << j << '\n';
}