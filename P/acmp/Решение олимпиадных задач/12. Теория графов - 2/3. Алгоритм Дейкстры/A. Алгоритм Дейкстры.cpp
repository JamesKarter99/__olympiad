/*
* ------------ АЛГОРИТМ ДЕЙКСТРЫ ------------
~ дейкстра
? реализация алгоритма дейкстры
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <tuple>
#include <queue>

using namespace std;

using line   = vector <int>;
using matrix = vector <line>;

const int INF = 0x3f3f3f3f;

int main() {
    // ...
    int n, s, f;
    cin >> n >> s >> f;
    s--, f--;

    vector <vector <tuple <int, int>>> d(n);
    for (int i(0); i < n; i++) {
        for (int j(0); j < n; j++) {
            int w;
            cin >> w;

            if (w != -1)
                d[i].push_back({ j, w });
        }
    }

    // Дейкстра
    line used(n, 0);
    line dist(n, INF);
    dist[s] = 0;

    priority_queue <pair <int, int>> q;
    q.push({ 0, s });

    while (!q.empty()) {
        int a = q.top().second; q.pop();

        if (used[a])
            continue;

        used[a] = true;

        for (auto i : d[a]) {
            auto [b, w] = i;

            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                q.push({ -dist[b], b });
            }
        }
    }

    cout << (dist[f] != INF ? dist[f] : -1);

    return 0;
}