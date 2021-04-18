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
    //freopen("final.in", "rt", stdin);
    //freopen("final.out", "wt", stdout);

    // n - всего участников, p - сумма баллов, k - кол-во лидеров, d - кол-во разных оценок у лидеров 
    int n, p, d, k, e;
    cin >> n >> p >> k >> d;

    e = n - k; // кол-во обычных

    line a;

    if (d == 1) {
        int t = p / k; // баллы каждому лидеру

        for (int i(0); i < k; i++) {
            a.push_back(t);
            p -= t;
        }

        int y = (p >= e && e? p / e : p); // баллы каждому обычному (ну или почти, может на всех не хватить)

        if (y > t) {
            cout << "Wrong information";
            return 0;
        }

        for (int i(0); i < e; i++) {
            if (p) {
                a.push_back(y);
                p -= y;
            }
            else {
                a.push_back(0);
            }        
        }

        if (p) {
            cout << "Wrong information";
            return 0;
        }
    }
    else {
        int i(0);
        while (i < d - 1) {
            a.push_back(i);
            p -= i;
            i++;
        }

        if (a.back() < p) {
            a.push_back(p);
            p = 0;
        }
        else {
            cout << "Wrong information";
            return 0;
        }

        for (int i(0); i < e + (k - d); i++) {
            if (p == 0) {
                a.push_back(0);
            }
            else {
                a.push_back(p);
                p = 0;
            }
        }
    }

    // вывод
    sort(all(a), [](int a, int b) {return a > b; });
    for (auto i : a)
        cout << i << endl;

    return 0;
}

/*
-------------- d = 1 --------------
10 10 5 1
+ можно распределить (у пяти лидеров по 2, у остальных пятерых 0)

10 11 5 1
+ можно распределить (у пяти лидеров по 2, у одного 1, а у остальных четверых 0)

10 10 7 1
- можно распределить (у семи лидеров по 1, остается три очка, поэтому оставшимся трем тоже по 1)

10 10 8 3
- нельзя 


-------------- d > 1 --------------
3 4 2 2
+ мсжно распределить (лидерам: 0 4, обычному 0)

5 5 3 3
+ можно (лидерам 0 1 4, обычным 0 0)

*/