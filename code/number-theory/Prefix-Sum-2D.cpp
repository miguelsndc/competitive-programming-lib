/*
    PrefixSum2D (1-based)
    Calcula queries num subretângulo de um grid:
        - Build - O(n²)
        - Queries - O(1)
*/

vector<vector<ll>> pref(maxn, vector<ll>(maxm, 0));
void build(vector<vector<ll>> &grid, int n) {
    // Constrói a PS - O(n²)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pref[i][j] = grid[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }
}

ll query(int pr, int pc, int tr, int tc) {
    return pref[tr][tc] - pref[tr][pc - 1] - pref[pr - 1][tc] + pref[pr - 1][pc - 1];
}

