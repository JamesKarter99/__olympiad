#include <iostream>
#include <algorithm>
#include <vector>

#define all(s) s.begin(), s.end()

using namespace std;

using line = vector <int>;

int main() {
    // ...
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    line d;

    for (int i(0); i < n; i++) {
        int mx = -0x3f3f3f3f;

        for (int j(0); j < n; j++) {
            int v;
            cin >> v;

            mx = max(mx, v);
        }

        d.push_back(mx);
    }

    sort(all(d));

    for (auto i : d)
        cout << i << " ";

    return 0;
}