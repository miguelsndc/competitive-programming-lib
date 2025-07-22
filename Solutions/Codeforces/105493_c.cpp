#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define fi first
#define se second
#define All(x) x.begin(), x.end()

template<class Z> bool chmin(Z &x, Z y) { if (x > y) { x = y; return true; } return false; }
template<class Z> bool chmax(Z &x, Z y) { if (x < y) { x = y; return true; } return false; }

struct Point {
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    const Point operator-(const Point &other) {
        return Point(x - other.x, y - other.y);
    }

    const ld angle() { return atan2l(y, x); }
};

const ld PI = acosl(-1);
const ld EPS = 1e-9;

bool reflect = false;

int N;
vector<Point> P;

void answer(Point y_axis) {
    Point x_axis(y_axis.y, -y_axis.x);
    if (reflect) {
        x_axis.x = -x_axis.x;
        y_axis.y = -y_axis.y;
    }

    cout << "YES\n";
    cout << x_axis.x << " " << x_axis.y << "\n";
    cout << y_axis.x << " " << y_axis.y << "\n";
    exit(0);
}

void solve() {
    vector<Point> diff(N);
    vector<pair<ld, int>> by_angle;
    for (int i = 0; i < N - 1; i++) {
        diff[i] = P[i + 1] - P[i];
        by_angle.push_back({diff[i].angle(), i});
    }

    if (N == 1) answer(Point(0, 1));
    else if (N == 2) answer(diff[0]);

    sort(All(by_angle));
    by_angle.push_back({by_angle[0].fi + 2 * PI, by_angle[0].se});

    for (int i = 0; i < N - 1; i++) {
        if (by_angle[i + 1].fi - by_angle[i].fi > PI + EPS) {
            answer(diff[by_angle[i].se]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    P.assign(N, Point());
    for (auto &[x, y] : P) cin >> x >> y;

    set<pll> distinct;
    for (auto [x, y] : P) distinct.insert({x, y});
    if ((int)distinct.size() < N) {
        cout << "NO\n";
        exit(0);
    }

    solve();

    reflect = true;
    for (auto &[x, y] : P) x = -x;
    solve();

    cout << "NO\n";
}
