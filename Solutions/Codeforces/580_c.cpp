#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 1e5 + 5;

vector<int> is_cat(maxn), g[maxn];
int n, m;
ll cnt = 0;

void dfs(int u, int p, int curr) {
    if (curr > m) return;
    int ok = 1;
    for (int v : g[u]) {
        if (v != p) {
            ok = 0;
            dfs(v, u, curr * is_cat[u] + is_cat[v]);
        }
    }
    cnt += ok;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> is_cat[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }
    dfs(0, -1, is_cat[0]);
    cout << cnt;
}