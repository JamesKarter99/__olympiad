#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <math.h>
#include <map>

#define all(s) s.begin(), s.end()

using namespace std;

using T = long long;
using line = vector <int>;
using matrix = vector <line>;

int main() {
    // ...
    ios::sync_with_stdio(false);
    //freopen("electricity.in", "rt", stdin);
    //freopen("electricity.out", "wt", stdout);
    int n, m;
    cin >> n >> m;

    line a(m), b(n);

    for (auto& i : b) cin >> i; // удленители, которые подключаются к a, но имеют разъемы b
    for (auto& i : a) cin >> i; // удленители, которые подключаются к b, но имеют разъемы a

    int amount(0);
    sort(all(a));
    sort(all(b));
    reverse(all(a));
    reverse(all(b));

    int i(0), j(0);
    T na(1); // кол-во свободных розеток типа А
    T nb(0); // кол-во свободных розеток типа B

    do {
        if (nb) {
            nb--;
            na += a[i];
            i++;
        }

        if (!nb && i < m) {
            if (j < n) {
                na--;
                nb += b[j];
                j++;
            }
        }
    } while (i < m && nb);

    cout << na;

    return 0;
}