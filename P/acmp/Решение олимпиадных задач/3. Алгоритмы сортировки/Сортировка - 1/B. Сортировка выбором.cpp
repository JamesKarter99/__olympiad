/*
* ------------ СВАДЬБА ------------
& сортировка - 1
~ сортировка_выбором
? Ничего сложного. Просто сортировка и один цикл: замуж можно идти с тем, чье богатство больше текущего богатства Горогны.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

const int FREE = 0;
const int USED = 1;

using line = vector <int>;
using matrix = vector <line>;

int main() {
    // ...
    int n;
    cin >> n;

    line d(n);
    for (auto& i : d)
        cin >> i;
    
    // sort
    for (int i(n - 1); i >= 0; i--) {
        int iMax(0);

        for (int j(0); j <= i; j++) {
            if (d[iMax] < d[j]) 
                iMax = j;
        }

        

        cout << iMax << " ";

        if (i != iMax)
            swap(d[i], d[iMax]);
    }

    return 0;
}