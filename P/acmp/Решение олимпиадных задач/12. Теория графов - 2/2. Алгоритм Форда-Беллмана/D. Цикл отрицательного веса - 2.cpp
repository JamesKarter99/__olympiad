/*
* ------------ Цикл отрицательного веса - 2 ------------
& алгоритм форда-беллмана
~ форд_беллман_проверка_на_наличие_отриц_цикла_c_восстановлением
? форд-беллман для проверки графа на наличие отрицательного цикла + нужно помнить, что графм может быть не связным. Кроме того нужно вывести найденный отрицательный цикл. 
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <tuple>

using namespace std;

const int FREE = 0;
const int USED = 1;

using line   = vector <int>;
using matrix = vector <line>;
using edge   = tuple <int, int, int>;

const int INF = 0x3f3f3f3f;

int n;
vector <edge> d;
line dist, parent;

bool fordBellmanCycleWithPath(int start) {
    dist[start] = 0;

    int x;
    for (int i(0); i < n; i++) {
        x = -1;

        for (const auto& e : d) {
            auto [a, b, w] = e;

            if (dist[a] < INF && dist[a] + w < dist[b]) {
                dist[b] = max(-INF, dist[a] + w);
                parent[b] = a;
                x = b;
            }
        }
    }
    
    if (x != -1) {
        // цикл найден: вывод цикла

        // найдем вершину y такую, что она гарантированно лежит на цикле (см. теорию по ФОрду-Беллмана)
        int y = x; 
        for (int i(0); i < n; i++)
            y = parent[y];

        // обойдем массив предков и восстановим цикл
        int start = y;
        vector <int> path;

        do {
            path.push_back(y);
            y = parent[y];
        } while (y != start);

        path.push_back(start); // так нужно по условию, чтобы начальная вершина была и в конце

        // вывод пути в порядке обхода
        reverse(path.begin(), path.end());

        cout << "YES\n" << path.size() << "\n";
        for (auto i : path) {
            cout << i + 1 << " ";
        }

        return true;
    }

    return false; // циклв нет
}

int main() {
    // ...
    cin >> n;

    for (int i(0); i < n; i++) {
        for (int j(0); j < n; j++) {
            int w;
            cin >> w;

            if (w != 100000)
                d.push_back({ i, j, w });
        }
    }

    dist.resize(n, INF);
    parent.resize(n, -1);

    for (int i(0); i < n; i++) {
        if (dist[i] == INF && fordBellmanCycleWithPath(i)) {
            return 0;
        }
    }

    cout << "NO";

    return 0;
}