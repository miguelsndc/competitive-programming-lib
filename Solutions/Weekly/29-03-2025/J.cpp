#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<i64> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    i64 ans = 0;
    for (int i = n; i >= 2; i--) {
        i64 left = ((i - 1) * (n - 2)) % mod;
        ans += (left * (n - 3)) % mod;
        ans %= mod;
    }
    cout << ans;
}