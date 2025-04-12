#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;

constexpr i64 inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 1e5 + 5;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int &x: v) cin >> x;

    min_heap<i64> pq{all(v)};

    int cnt = 0;
    int op = 10 * n;

    while(pq.size() > 1 and op > 0) {
        op--;
        i64 a = pq.top(); pq.pop();
        i64 b = pq.top();
        if (a == b) {
            pq.pop();
            pq.push(a + b);
        } else {
            cnt++;
            pq.push(a); pq.push(a);
        }
    }

    if (op == 0) {
        cout << -1 << '\n';
    } else {
        cout << cnt << '\n';
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