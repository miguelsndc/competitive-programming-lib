#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define vi vector<int>
#define fi first
#define se second
#define sz(x) int(x.size())
#define all(a) (a).begin(), (a).end()
#define INF 1000000009
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
int power(int b, int p, int m) {
    long long x = 1;
    int power = b % m;
    int k = log2(p);
    for (int i = 0; i <= k; i++) {
       int a = (p >> i) & 1;
       if (a == 1)
           x = (x * power) % m;
       power = (power * power) % m;
   }
    return x;
}

void solve() {
    int n, m; cin >> n >> m;
    const int maxn = 1e5 + 1;
    vi prev(maxn, -1);
    vi g[maxn];
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi visited(maxn, false);
    queue<int> q;
    visited[1] = true;
    q.push(1);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: g[u]) {
            if (!visited[v]) {
                visited[v] = true;
                prev[v] = u;
                q.push(v);
            }
        }
    }
    bool can = true;
    for (int i = 2; i<= n;i++) {
        if (prev[i] == -1) {
            can = false;
            break;
        }
    }

    if (can) {
        cout << "Yes\n";
        for (int i = 2; i<= n;i++) {
            cout << prev[i] << '\n';
        }
    } else {
        cout << "No";
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}