/*
* ------------ АЛГОРИТМ ФОРДА_БЕЛЛМАНА ------------
& алгоритм форда-беллмана
~ форд_беллман
? реализация алгоритма форда-беллмана
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
    int n, m;
    cin >> n >> m;

    vector <edge> d(m);
    for (auto& i : d) {
        int a, b, w;
        cin >> a >> b >> w;

        i = { a-1, b-1, w };
    }

    line dist(n, INF);
    dist[0] = 0;

    for (int i(0); i < n - 1; i++) {
        for (const auto& e : d) {
            auto [a, b, w] = e;

            if (dist[a] < INF)
                dist[b] = min(dist[b], dist[a] + w);
        }
    }

    for (auto i : dist) 
        cout << (i == INF ? 30000 : i) << " ";

    return 0;
}