#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <math.h>

#define all(s) s.begin(), s.end()

using namespace std;

using T = long long;
using line = vector <int>;
using matrix = vector <line>;

struct Point {
    int x, y;

    void input() {
        cin >> x >> y;
    }

    bool operator < (const Point& p) {
        return x < p.x || (x == p.x && y < p.y);
    }
};

int main() {
    // ...
    ios::sync_with_stdio(false);
    //freopen("grid.in", "rt", stdin);
    //freopen("grid.out", "wt", stdout);

    int n;
    cin >> n;

    vector <Point> d(n);
    for (auto& i : d)
        i.input();

    sort(all(d));

    int mx(-0x3f3f3f3f);
    int my(-0x3f3f3f3f);

    line dx(n - 1), dy(n - 1);
    for (int i(0); i < n - 1; i++) {
        dx[i] = d[i + 1].x - d[i].x;
        dy[i] = d[i + 1].y - d[i].y;

        mx = max(mx, dx[i]);
        my = max(my, dy[i]);
    }

    

    return 0;
}

