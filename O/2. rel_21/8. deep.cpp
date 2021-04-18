/*
~ бинарный_поиск_вещественный
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <math.h>
#include <map>

#define sqr(a) ((a)*(a))

using namespace std;

using T = long double;

const T PI  = acos(-1.0);
const T COS = cos(PI / 4);

T dist(T x1, T y1, T x2, T y2) {
    return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

bool eq(T a, T b) {
    return abs(a - b) < 1e-10;
}

int main() {
    // ...
    ios::sync_with_stdio(false);
    freopen("deepest.in", "rt", stdin);
    freopen("deepest.out", "wt", stdout);
    T x, y, d;
    cin >> x >> y >> d;

    T rf = dist(0, 0, x, y); /// фактическое рассояние между смольным и входом в станцию

    if (eq(rf, d)) {
        cout << "Single staircase";
    }
    else if (rf > d) {
        cout << "Impossible";
    }
    else {
        T xp = x;
        T yp, zp = y;

        T mn(0), mx(d);

        while (abs(mn - mx) > 1e-11) {
            zp = (mn + mx) / 2; // это глубина промежуточной станции
            yp = y + zp;        // это ее y-координата

            T rfstp = dist(x, y, xp, yp); // это фактическое расстояние между входом в станцию и промежуточной станцией
            T rfpsm = dist(0, 0, xp, yp); // это фактическое расстояние между промежуточной станцией и смольным

            if (eq(d - zp, rfpsm)) {
                cout << fixed << setprecision(10) << xp << " ";
                cout << fixed << setprecision(10) << yp << " ";
                cout << fixed << setprecision(10) << zp << " ";
                return 0;
            }
            else if (d - zp > rfpsm) {
                mn = zp;
            }
            else {
                mx = zp;
            }
        }
    }

    return 0;
}