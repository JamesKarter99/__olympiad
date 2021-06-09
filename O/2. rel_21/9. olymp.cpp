#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <stack>
#include <map>

#define all(s) s.begin(), s.end()

using namespace std;

using T = double;
using line = vector <int>;

int main() {
    // ...
    ios::sync_with_stdio(false);
    //freopen("electricity.in", "rt", stdin);
    //freopen("electricity.out", "wt", stdout);
    int n, m;
    cin >> n >> m;

    line b(n), a(m);
    for (auto& i : b) cin >> i;
    for (auto& i : a) cin >> i;

    // refr
    int na(1);
    int nb(0);

    sort(all(a), [](int p, int q) {return p > q; });
    sort(all(b), [](int p, int q) {return p > q; });

    int i(0), j(0);
    do {
        // добавить розетки типа A
        if (nb) {
            nb--;
            na += a[i];
            i++;
        }
        
        // добавить еще разъем B для розеток типа A
        if (!nb && j < n && i < m) {
            na--;
            nb += b[j];
            j++;
        }
    } 
    while (i < m && nb);

    cout << na;
}