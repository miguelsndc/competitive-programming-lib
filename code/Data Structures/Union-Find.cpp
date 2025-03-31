/*
    Disjoint Set Union with path compression
    Complexidade:
        - find(u) O(alpha(n))
        - unite(u) O(alpha(n))
*/

const int MAXN = 2e5 +5;
template<typename T>
struct UnionFind {
    int parents[MAXN];
    int sizes[MAXN];

    // O(n)
    void init(int n) {
        for (int i = 1; i <= n; i++) {
            parents[i] = i;
            sizes[i] = 1;
        }
    }
    
    // O(alpha(n)) ~ O(1)
    int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }
    
    // O(alpha(n)) ~ O(1)
    bool unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) { return false; }
        if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true; // (some condition met for component);
    }
};