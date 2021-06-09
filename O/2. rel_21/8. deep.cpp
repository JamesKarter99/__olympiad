/*
~ бинарный_поиск_вещественный
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <stack>
#include <map>

#define all(s) s.begin(), s.end()
#define sqr(a) ((a)*(a))
#define srt(d) sort(all(d))

using namespace std;

using T = double;
using line = vector <int>;
using matrix = vector <line>;

const T prec = 1e-11;

T dist(T x1, T y1, T x2, T y2) {
    return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

int main() {
    // ...
    ios::sync_with_stdio(false);
    //freopen("deepest.in", "rt", stdin);
    //freopen("deepest.out", "wt", stdout);
    int x, y, d;
    cin >> x >> y >> d;

    T r = dist(0, 0, x, y);

    if (abs(r - d) < prec) {
        cout << "Single staircase";
    }
    else if (r > d) {
        cout << "Impossible";
    }
    else {
        T dx, dy, dd;

        dx = x;

        T mn(0), mx(d);
        while (abs(mn - mx) > prec) {
            dd = (mn + mx) / 2;

            dy = y + dd;

            // растояние между вестибюлем и станцией
            T a = d - dd;             /// через глубину вестибюля и станции
            T b = dist(0, 0, dx, dy); /// через координаты x и y вестибюля

            if (abs(a - b) < prec) {
                cout << fixed << setprecision(10) << dx << " ";
                cout << fixed << setprecision(10) << dy << " ";
                cout << fixed << setprecision(10) << dd << " ";
                return 0;
            }
            else if (a > b) {
                mn = dd;
            }
            else {
                mx = dd;
            }
        }
    }
}