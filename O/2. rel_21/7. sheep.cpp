#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <stack>
#include <map>

#define all(s) s.begin(), s.end()

using namespace std;

using T = long long;
using line = vector <int>;
using matrix = vector <line>;

const int FREE = 0;
const int USED = 1;
const int LOCK = 3;

matrix p, d;

void lockCell(int i, int j) {
    d[i][j] = (d[i][j] != USED ? LOCK : USED);
}

void setCell(int i, int j) {
    d[i][j] = USED;

    lockCell(i + 1, j);
    lockCell(i + 1, j - 1);
    lockCell(i, j - 1);
    lockCell(i - 1, j - 1);
    lockCell(i - 1, j);
    lockCell(i - 1, j + 1);
    lockCell(i - 1, j + 1);
    lockCell(i, j + 1);
    lockCell(i + 1, j + 1);
}

bool isFree(int i, int j, int l) {
    for (int k(0); k < l; k++) {
        if (j + k > 10 || d[i][j + k] != FREE)
            return false;
    }

    return true;
}

int main() {
    // ...
    ios::sync_with_stdio(false);
    freopen("battleship.in", "rt", stdin);
    freopen("battleship.out", "wt", stdout);
    p.resize(12, line(12)), d = p;
  
    for (int i(1); i <= 10; i++) {
        for (int j(1); j <= 10; j++) {
            int v;
            cin >> v;

            if (v == 100) {
                setCell(i, j);
            }
        }
    }

    line leng{ 4, 3, 3, 2, 2, 2, 1, 1, 1 };

    for (auto l : leng) {
        for (int i(1); i <= 10; i++) {
            for (int j(1); j <= 10; j++) {
                if (isFree(i, j, l)) {
                    for (int k(0); k < l; k++) {
                        setCell(i, j + k);
                    }
                    i = j = 11;
                }
            }
        }
    }

    for (int i(1); i <= 10; i++) {
        for (int j(1); j <= 10; j++) {
            cout << (d[i][j] != USED ? "." : "#");
        }
        cout << endl;
    }

    return 0;
}