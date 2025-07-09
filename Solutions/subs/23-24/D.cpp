#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

const ll inf = 1e18;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    vector<array<int, 3>> edges;
    vector dist(n, vector<ll>(n, inf));
    vector mark(n, vector<int>(n));
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        --u, --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    for (int i = 0; i < n; i++) {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        vector<ll>& d = dist[i];
        d[i] = 0;
        pq.push({0, i});
        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (d[u] != cost) continue;
            for (auto [v, w] : g[u]) {
                if (d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    pq.push({d[v], v});
                }
            }
        }
    }

    auto faz = [&](int src, int dest) {
        vector<ll> dist(n, inf);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (dist[u] != cost) continue;
            for (auto [v, w] : g[u]) {
                if (mark[u][v]) continue;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return (dist[dest] == inf ? -1 : dist[dest]);
    };

    for (auto [u, v, w] : edges) {
        if (dist[u][v] != w) {
            cout << dist[u][v] << '\n';
        } else {
            mark[u][v] = mark[v][u] = true;
            cout << faz(u, v) << '\n';
            mark[u][v] = mark[v][u] = false;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}