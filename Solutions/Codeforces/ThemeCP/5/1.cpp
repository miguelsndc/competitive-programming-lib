#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt-- ){
        string a, b; cin >> a >> b;
        swap(a[0], b[0]);
        cout << a << ' ' << b << '\n';
    }
}