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

    line d(n);
    for (int i(0); i < n; i++)
        d[i] = i + 1;

    while (m--) {
        rotate(d.rbegin(), d.rbegin() + 1, d.rend());
    }

    for (auto i : d)
        cout << i << " ";

    return 0;
}s