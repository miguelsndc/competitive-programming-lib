#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
using ii = pair<int, int>;
const int maxn = 2e5 + 5;
const ll inf = 1e18;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
void solve() {
    int n;
    cin >> n;
    vc<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (v.size() < 28) {
            v.push_back(x);
        }
    }

    int m = v.size();
    gp_hash_table<int, int> d1;

    vc<int> av, bv;
    int a = 0, b = 0;
    auto f1 = [&](auto&& self, int i, int n) {
        if (i == n) {
            if (d1.find(a - b) == d1.end() and (av.size() > 0 or bv.size() > 0)) {
                d1[a - b] = true;
            }
            return;
        }
        a += v[i];
        av.push_back(i);
        self(self, i + 1, n);
        a -= v[i];
        if (av.size() > 0) av.pop_back();
        b += v[i];
        bv.push_back(i);
        self(self, i + 1, n);
        b -= v[i];
        if (bv.size() > 0) bv.pop_back();
        self(self, i + 1, n);
    };

    int found = -1;
    vc<int> ans_v1, ans_v2, ans_v3, ans_v4;
    auto f2 = [&](auto&& self, int i, int n) {
        if (found != -1) return;
        if (i == n) {
            if ((av.size() > 0 or bv.size() > 0) and found == -1) {
                if (d1.find(b - a) != d1.end()) {
                    ans_v1 = av;
                    ans_v2 = bv;
                    found = b - a;
                }
            }
            return;
        }
        if (found == -1) {
            a += v[i];
            av.push_back(i);
            self(self, i + 1, n);
            a -= v[i];
            if (av.size() > 0) av.pop_back();
            b += v[i];
            bv.push_back(i);
            self(self, i + 1, n);
            b -= v[i];
            if (bv.size() > 0) bv.pop_back();
            self(self, i + 1, n);
        }
    };

    int mid = (m) / 2;

    f1(f1, 0, mid);
    a = 0, b = 0;
    bv.clear();
    av.clear();
    f2(f2, mid, m);

    if (found == -1) {
        cout << -1 << '\n';
        return;
    }

    a = b = 0;
    av.clear();
    bv.clear();
    bool got = false;
    auto f3 = [&](auto&& self, int i, int n) {
        if (got) return;
        if (i == n) {
            int dif = a - b;
            if (!got and (found == dif) and (av.size() > 0 or bv.size() > 0)) {
                ans_v3 = av;
                ans_v4 = bv;
                got = true;
            }
            return;
        }
        if (!got) {
            a += v[i];
            av.push_back(i);
            self(self, i + 1, n);
            a -= v[i];
            if (av.size() > 0) av.pop_back();
            b += v[i];
            bv.push_back(i);
            self(self, i + 1, n);
            b -= v[i];
            if (bv.size() > 0) bv.pop_back();
            self(self, i + 1, n);
        }
    };
    f3(f3, 0, mid);

    vc<int> aa, bb;

    for (int x : ans_v1) aa.push_back(x + 1);
    for (int x : ans_v3) aa.push_back(x + 1);

    for (int x : ans_v2) bb.push_back(x + 1);
    for (int x : ans_v4) bb.push_back(x + 1);

    cout << aa.size() << ' ';
    for (int x : aa) cout << x << ' ';
    cout << '\n';

    cout << bb.size() << ' ';
    for (int x : bb) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}