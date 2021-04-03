/*
* ------------ Цикл отрицательного веса ------------
& алгоритм форда-беллмана
~ форд_беллман_проверка_на_наличие_отрицательного_цикла
? форд-беллман для проверки графа на наличие отрицательного цикла + нужно помнить, что графм может быть не связным
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
line dist;

bool fordBellmanCycle(int start) {
    dist[start] = 0;

    int x;
    for (int i(0); i < n; i++) {
        x = -1;

        for (const auto& e : d) {
            auto [a, b, w] = e;

            if (dist[a] < INF && dist[a] + w < dist[b]) {
                dist[b] = max(-INF, dist[a] + w);
                x = b;
            }
        }
    }

    return x != -1;
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

    for (int i(0); i < n; i++) {
        if (dist[i] == INF && fordBellmanCycle(i)) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}