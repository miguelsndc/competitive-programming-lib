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

void solve() {
    int n;
    cin >> n;
    const int maxn = 1e7;
    vc<int> primes, is_prime(maxn, 1);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i < maxn; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            if (primes.size() == n) {
                break;
            }
            for (ll j = i * i; j < maxn; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int x : primes) cout << x % 100 << '\n';
    // cout << primes.back() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}