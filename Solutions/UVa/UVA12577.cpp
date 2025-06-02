#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 1e4 + 5;
vector<int> cycle_length(maxn);

void precalc() {
  for (int i = 1; i < maxn; i++) {
    int cnt = 0, n = i;
    while(1) {
      cnt++;
      if (n == 1) break;
      if (n & 1) n = 3 * n + 1;
      else n /= 2;
    }
    cycle_length[i] = cnt;
  }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    precalc();
    
    vector<vector<int>> st;
    
    int n = maxn;
    int k = 31 - __builtin_clz(n) + 1;
    st.resize(k); st[0] = cycle_length;
    for (int i = 1; i < k; i++) {
      st[i].resize(n - (1 << i) + 1);
      for (int j = 0; j + (1 << i) <= n; j++) {
        st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
    
    int x, y; 
    while((cin >> x >> y) and x and y) {
      int p = 31 - __builtin_clz(y - x + 1);
      cout << max(st[p][x], st[p][y - (1 << p) + 1]) << '\n';
    }

    return 0;
}
