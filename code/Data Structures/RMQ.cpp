/*
Sparse st RMQ Range Min/Max Query

Build O(n log n)
Query O(1)
*/

const int MAXN = 1e5 + 5;
const int MAXLG = 31 - __builtin_clz(MAXN) + 1;

template<typename T>
struct SparseTable {
	int value[MAXN], st[MAXLG][MAXN];

	// O(n log n)
	void build(int n) {
		for(int i=0; i<n; i++) st[0][i] = value[i];
		for(int p=1; p < MAXLG; p++)
			for(int i=0; i + (1 << p) <= N; i++)
				st[p][i] = min(st[p-1][i], st[p-1][i+(1 << (p-1))]); // ou max ou gcd
	}

	// O(1)
	int query(int l, int r){
		int p = 31 - __builtin_clz(r - l + 1);	//floor log
		return min(st[p][l], st[p][ r - ( 1 << p) + 1 ]);
	}
};