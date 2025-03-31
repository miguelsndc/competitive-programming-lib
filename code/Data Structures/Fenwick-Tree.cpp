/*
    Fenwick Tree - Range Queries
*/

template<typename T = int>
struct FenwickTree {
    vector<T> bit, arr;

    FenwickTree(int size) {
        bit.assign(size + 1, 0);
        arr.assign(size + 1, 0);
    }
	// O(log(n))
    void set(int pos, int val) {
        add(pos, val - arr[pos]);
    }
    
	// O(log(n))
    void add(int pos, int val) {
        arr[pos] += val;
        ++pos;
        for (; pos <= n; pos += (pos & (-pos))) bit[pos] += val;
    }
	// O(log(n))
    T query(int pos) {
        ++pos;
        T sum = 0;
        for (; pos > 0; pos -= (pos & (-pos))) sum += bit[pos];
        return sum;
    }
};