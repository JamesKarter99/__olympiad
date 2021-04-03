/*
* ------------ ЭКСПЕРИМЕНТ ------------
~ dsu
? 
todo описание решения !
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <tuple>

using namespace std;

using line   = vector <int>;
using matrix = vector <line>;

struct flask {
    int volume;
    int current;
    int number;
};

struct DSU {
    vector <int> parent; // номер колбы для i-го газа
    vector <int> volume; // объем колбы, в которой лежит i-й газ

    DSU(int n) {
        parent.resize(n);
        volume.resize(n);
    }

    void make_set(int i, int v) {
        parent[i] = i;
        volume[i] = v;
    }

    int find_set(int p) {
        if (p == parent[p])
            return p;

        return parent[p] = find_set(parent[p]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if (a == b)
            return;

        if (a < b)
            swap(a, b);

        volume[a] += volume[b];
        volume[b] = 0;
        parent[b] = a;
    }
};

int main() {
    // ...
    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    for (int i(0); i < n; i++) {
        int v;
        cin >> v;

        dsu.make_set(i, v);
    }
        
    while (m--) {
        int a, b;
        cin >> a >> b;

        dsu.union_sets(a - 1, b - 1);
    }
    
    for (int i(0); i < n; i++) {
        if (dsu.volume[i]) {
            cout << i + 1 << " " << dsu.volume[i] << '\n';
        }
    }

    return 0;
}