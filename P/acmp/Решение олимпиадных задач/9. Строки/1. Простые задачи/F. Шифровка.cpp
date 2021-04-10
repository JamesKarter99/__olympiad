/*
* ------------ IP-адрес ------------
? Насколько я понял, то нужно просто перебрать все 26 (потому что в английском языке 26 букв) знаменателей, а потом 27 - переход с A на Z, B на A (к примеру) и т.д.

*/

#include <iostream>
#include <string>
#include <algorithm>

#define all(s) s.begin(), s.end()

using namespace std;

using line   = vector <int>;
using matrix = vector <line>;

const int INF = 0x3f3f3f3f;

void shift(char& p) {
    if (p == 'Z')
        p = 'A';
    else 
        p++;
}

int main() {
    // ...
    string s, p;
    cin >> s >> p;

    string answer = "IMPOSSIBLE";
    for (int i(0); i < 27; i++) {
        
        for (int j(0); j < s.size() - p.size() + 1; j++) {
            if (s.substr(j, p.size()) == p) {
                answer = s;
                break;
            }
        }

        for_each(all(s), shift);
    }

    cout << answer;

    return 0;
}