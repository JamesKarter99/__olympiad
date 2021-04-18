/*
* ------------ ЗАДАНИЕ 1 ------------
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <stack>
#include <map>

#define all(s) s.begin(), s.end()

using namespace std;

using T = long double;
using line = vector <int>;
using matrix = vector <line>;

int main() {
    // ...
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    matrix d(n, line(m));
    for (int i(0); i < n; i++) {
        for (int j(0); j < m; j++) {
            char c;
            cin >> c;

            d[i][j] = (c == '1');
        }
    }

    // решение
    int r(0);
    line c(n + 1); // длинна полосок, состоящих из непрерывных единиц, в строках d

    // перебор номеров столбцов
    for (int j(0); j < m; j++) {
        
        // подсчет длинны полоски в i-й строке, заканчивающейся в j-м столбце
        for (int i(0); i < n; i++)
            c[i] = (d[i][j] ? c[i] + 1 : 0);

        // перебор строк
        for (int i(0); i < n; i++) {
            /// в клетке d[i][j] не модет оканчиваться прямоугольник, если в ней лежит 0
            if (d[i][j] == 0) continue;

            int t = c[i];
            int k = i;

            while (k >= 0 && t*(i + 1) > r) {
                /// увеличивая высоту прямоугольника (это разность между i и k) мы должны выбрать наименьшую длинну полосок из c[k ... i]
                t = min(t, c[k]); 
                r = max(r, t * (i - k + 1));

                k--;
            }

        }
    }

    cout << r;

    return 0;
}