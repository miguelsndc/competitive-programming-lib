#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define f first
#define s second
#define sp << " " <<
#define spe << " "
#define vii vector<pii>

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q, t;
    cin >> n >> q;
    vector<vi> g(n);
    for (int i = 0; i < q; i++) {
        cin >> t;
        g[i].push_back(--t);
    }

    return 0;
}