/*
* ------------ АЛГОРИТМ ФОРДА БЕЛЛМАНА - 2 ------------
& алгоритм форда-беллмана
~ форд_беллман
? реализация алгоритма форда-беллмана, но есть два момента:
> здесь нет списка ребер, ребра перебираются по i и j (i < j)
> нужно делать принудительный выход из алгоритма, если на текущем раунде не было релаксаций расстояний.
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

int main() {
    // ...
    int n;
    cin >> n;

    line dist(n + 1, INF);
    dist[1] = 0;
    
    for (int i(0); i < n - 1; i++) {
        bool end = true;

        for (int a(1); a <= n; a++) {
            for (int b(a + 1); b <= n; b++) {
                int w = (179 * a + 719 * b) % 1000 - 500;

                if (dist[a] < INF && dist[b] > dist[a] + w) {
                    dist[b] = dist[a] + w;
                    end = false;
                }
            }
        }

        if (end) break;
    }

    cout << dist[n];

    return 0;
}