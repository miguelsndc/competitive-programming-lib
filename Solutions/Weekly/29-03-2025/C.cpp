#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
constexpr int maxn = 1e6;

vector<int> bit(maxn);

void add(int pos, int val) {
    ++pos;
    while(pos < maxn) {
        bit[pos] += val;
        pos += (pos & (-pos));
    }
}

int query(int pos) {
    ++pos;
    int sum = 0;
    while(pos > 0) {
        sum += bit[pos];
        pos -= (pos & (-pos));
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> v(n);
    vector<int> a, queries(q);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        a.push_back(v[i].first);
        a.push_back(v[i].second);
    }
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        a.push_back(t);
        queries[i] = t;
    }
    sort(begin(a), end(a));
    for (int i = 0; i < n; i++) {
        int left = lower_bound(begin(a), end(a), v[i].first) - begin(a);
        int right = lower_bound(begin(a), end(a), v[i].second) - begin(a);
        add(left, 1);
        add(right + 1, -1);
    }
    for (int qu: queries) {
        cout << query(lower_bound(begin(a), end(a), qu) - begin(a)) << '\n';
    }
}