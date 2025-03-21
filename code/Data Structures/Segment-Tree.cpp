// 1-Based Segment Tree - Range Queries
const int MAXN = 2e5 + 5;

int n; // numero de nodes
vector<int> a(MAXN); // vetor de input 1-based

struct SegmentTree {
    vector<int> tree;
    SegmentTree() {
        tree.resize(4 * (n + 1));
    }

    // Join - Funcao a rodar nos nos da arvore, min, max, etc.
    int join(int a, int b) {
    }

    // O(n)
    void build(int l = 1, int r = n, int v = 1) {
        if (l == r) {
            tree[v] = a[l];
            return;
        } else {
            int mid = l + (r - l) / 2;
            build(l, mid, v * 2);
            build(mid + 1, r, v * 2 + 1);
            tree[v] = join(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    // O(log(n))
    void update(int pos, int val, int l = 1, int r = n, int v = 1) {
        if (l == r) {
            tree[v] = val;
            return;
        } else {
            int mid = l + (r - l) / 2;
            if (pos <= mid) {
                update(pos, val, l, mid, v * 2);
            } else {
                update(pos, val, mid + 1, r, v * 2 + 1);
            }
            tree[v] = join(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    // O(log(n))
    ll query(int a, int b, int l = 1, int r = n, int v = 1) {
        if (b < l || a > r) return (1e9 + 9);
        if (a <= l && r <= b) return tree[v];
        int mid = l + (r - l) / 2;
        ll left = query(a, b, l, mid, v * 2);
        ll right = query(a, b, mid + 1, r, v * 2 + 1);
        return join(left, right);
    }
};
