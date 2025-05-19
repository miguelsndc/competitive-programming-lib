#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>

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

using ll = long long;

constexpr ll inf = 1E18;
constexpr int mod = 1e9 + 7, maxn = 2e5 + 5;

vector<int> a, ans;

int len;  // roughly sqrt n
struct Query {
    int l, r, idx;
    bool operator<(const Query& other) const {
        int block_a = l / len, block_b = other.l / len;
        if (block_a != block_b)
            return block_a < block_b;
        return (block_a & 1) ? (r > other.r) : (r < other.r);
    }
};

/*
    frequency zero never happens
*/

int maxfreq = 0;
vector<int> cnt(maxn), freq(maxn);

int get_ans() {
    return maxfreq;
}
void add(int idx) {
    int x = a[idx];
    // previous count is decreased
    freq[cnt[x]]--;
    // increase count by 1 and so is frequency increased
    freq[++cnt[x]]++;
    // maxfreq is maximum between this and new frequency of this added element
    maxfreq = max(maxfreq, cnt[x]);
}
// "determine the number of occurrences of the most frequent value"
void remove(int idx) {
    int x = a[idx];
    // decrease frequency of cnt[x] by 1
    freq[cnt[x]]--;
    if (cnt[x] == maxfreq and freq[cnt[x]] == 0) {
        --maxfreq;
    }
    // increase frequency of cnt[x] - 1 by 1
    freq[--cnt[x]]++;
}

void mo(vector<Query> queries) {
    sort(all(queries));
    ans.assign(queries.size(), 0);
    int cur_l = 0, cur_r = -1;
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        ans[q.idx] = get_ans();  // get answer
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    len = sqrt(n + .0);
    a.assign(n, 0);
    ans.assign(q, 0);
    vector<Query> queries(q);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries[i] = {l, r, i};
    }

    mo(queries);

    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) {
        solve();
    }
}