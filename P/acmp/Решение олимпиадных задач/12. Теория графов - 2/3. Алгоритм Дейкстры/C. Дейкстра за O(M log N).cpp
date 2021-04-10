/*
* ------------ Дейкстра за O(M log N) ------------
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
    ios::sync_with_stdio(false);
    int n, m, s;
    cin >> n >> m >> s;

    vector <vector <tuple <int, int>>> d(n);
    for (int i(0); i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        d[a].push_back({ b, w });
        d[b].push_back({ a, w });
    }

    // Дейкстра
    line dist(n, INF);
    line used(n, 0);
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

    for (auto i : dist) {
        cout << (i == INF ? 2009000999 : i) << " ";
    }

    return 0;
}