#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map <char, int> rel {
    { 'I', 1 },
    { 'V', 5 },
    { 'X', 10 },
    { 'L', 50 },
    { 'C', 100 },
    { 'D', 500 },
    { 'M', 1000 }
};

int main() {
    // ...
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> s;

    n = s.size();

    int dec(0);

    for (int i(0); i < n; ) {

        int a = rel[s[i]];
        int b = (i + 1 < n ? rel[s[i + 1]] : 0);

        if (a >= b) {
            dec += a;
            i++;
        }
        else {
            dec += b - a;
            i += 2;
        }

    }

    cout << dec;

    return 0;
}