#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr i64 inf = 1E18;
const int maxn = 1e5 + 5;
int r[maxn], g[maxn];
vector<pair<int, int>> adj[maxn];

vector<i64> dijkstra() {
    vector<i64> dist(maxn, inf);
    dist[0] = 0;
    priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<pair<i64, i64>>> pq;
    pq.push({dist[0], 0});
    while(!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if (dist[u] != cost) continue;
        for (auto [v, w]: adj[u]) {
            // da um ejito de ver se ta verted eou vermhleoh
            /*
                w tamanho da estrada
                cost tempo pra chegar aqui
                se cost + w tempo acumulado pra cehgar la

                se ele chegar e osinal tiver verde ele tem q esperar, o custo aumenta
            */
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> r[i] >> g[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<i64> d = dijkstra();
    cout << d[n - 1];
}