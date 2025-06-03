#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vc = vector<T>;
using ll = long long;
using ii = pair<int, int>;
const ll inf = 1e18;
const int maxn = 1e6 + 5;
const int mod = 998244353;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int fact[maxn];

void sieve() {
    memset(fact, 0, sizeof fact);
    for (int i = 2; i < 1005; i++) {
        if (fact[i] == 0) {
            fact[i] = i;
            for (int j = i * i; j < maxn; j += i) {
                if (fact[j] == 0) fact[j] = i;
            }
        }
    }
    for (int i = 1005; i < maxn; i++) {
        if (fact[i] == 0) fact[i] = i;
    }
}

ll fexp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    map<int, vector<int>> pexp;

    for (int x : a) {
        map<int, int> factors;
        while (x > 1) {
            int p = fact[x];
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                cnt++;
            }
            factors[p] = cnt;
        }
        for (auto& [p, cnt] : factors) {
            pexp[p].push_back(cnt);
        }
    }

    vector<pair<int, vector<int>>> osprimola;
    for (auto& [p, e] : pexp) {
        while ((int)e.size() < n) {
            e.push_back(0);
        }
        sort(e.begin(), e.end());
        osprimola.emplace_back(p, move(e));
    }

    sort(osprimola.begin(), osprimola.end());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll term = 1;
        for (auto& [p, e] : osprimola) {
            term = (term * fexp(p, e[i])) % mod;
        }
        ans = (ans + term) % mod;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    sieve();

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
