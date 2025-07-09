#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rdvec(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define vc vector

void solve() {
    ll n, S;
    cin >> n >> S;
    struct Job {
        int l, r, c;
    };

    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].l >> jobs[i].r >> jobs[i].c;
    }

    vector<array<ll, 3>> events;
    for (int i = 0; i < n; i++) {
        events.push_back({jobs[i].l, i, 0});
        events.push_back({jobs[i].r + 1, i, 1});
    }
    sort(all(events));
    multiset<ll> active;
    vector<ll> jobprofit(n);
    ll free_max = 0, lazy = 0, last_time = 0;
    for (auto [time, idx, ends] : events) {
        // qnt tempo passou
        ll delta = time - last_time;
        // lucro
        lazy += delta * S;
        last_time = time;
        const auto& job = jobs[idx];
        if (ends) {
            // se um intervalo terminou pega o lucro daquele trabalho
            ll profit = jobprofit[idx];
            // tira dos ativos
            active.erase(active.find(profit));
            // pega o lucro + lazy
            ll total = profit + lazy;
            // pega o maior lucro q ele tem enqnt ta livre
            free_max = max(free_max, total);
        } else {
            // novo trampo começa
            ll best = free_max;
            // maximo de (max de dinheiro desempregado, maximo de dinheiro trabalhando)
            if (!active.empty()) {
                // lucro real de estar trabalhando
                best = max(best, *active.rbegin() + lazy);
            }
            // se eu considerar esse trabalho eu pago c e tiro o lazy pra acumular direito
            ll profit = best - job.c - lazy;
            jobprofit[idx] = profit;
            // jogo na lista de possveis trabalhos
            active.insert(profit);
        }
    }
    cout << free_max << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;  // cin >> T;
    while (T--) solve();
}