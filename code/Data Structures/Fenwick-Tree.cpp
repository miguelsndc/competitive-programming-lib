/*
    Fenwick Tree - Range Queries
*/

vector<int> bit(maxn);
int n; // tamanho do array 0-based

// O(log(n))
void add(int pos, int val) {
	++pos; 
	while (pos <= n) {
		bit[pos] += val;
		pos += (pos & (-pos));
	}
}

// O(log(n))
int query(int pos) {
	++pos;
	int sum = 0;
	while(pos > 0) {
		sum += bit[pos];
		pos -= (pos & (-pos));
	}
	return sum;
}
