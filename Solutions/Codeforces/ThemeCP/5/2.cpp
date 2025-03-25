#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;

i64 lcm(i64 a, i64 b) {
    return a / __gcd(a, b) * b;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        i64 a, b, c, d; cin >> a >> b >> c >> d;
        i64 k1 = a * d, k2 = c * b;
       if (a * d == b * c) {
            cout << 0 << '\n';
       } else if (k2 != 0 and k1 % k2 == 0 || k1 != 0 and k2 % k1 == 0) {
            cout << 1 << '\n';
       } else {
            cout << 2 << '\n';
       }
    }
}