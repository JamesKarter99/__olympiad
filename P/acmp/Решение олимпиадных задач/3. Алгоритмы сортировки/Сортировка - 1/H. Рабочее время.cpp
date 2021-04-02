/*
* ------------ РАБОЧЕЕ ВРЕМЯ ------------
& сортировка - 1
? введем все данные в массив структур, содержащих дату и время, отсортируем его.
todo доделать описание
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

line MONTH{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

struct DateTime {
    int D, M, h, m, minutes;

    void input() {
        string s;
        getline(cin, s);

        int i(0);
        D = GetNumber(s, i); Next(s, i);
        M = GetNumber(s, i); Next(s, i);
        h = GetNumber(s, i); Next(s, i);
        m = GetNumber(s, i);

        for (int i(1); i < M; i++) {
            minutes += 60 * 8 * MONTH[i];
        }

        minutes += (D - 1) * 8 * 60;

        // осталось посчитать сколько минут проработал чувак ровно в тот день, который указан во входных данных
        m = m + h * 60; // время из входных данных в минутах

        if (m > 10 * 60)
            minutes += min(18 * 60, m) - 10 * 60 + (m > 18 * 60);
    }

    bool AtEnd(const string& s, int& index) {
        return index >= s.size();
    }

    int GetNumber(const string& s, int& index) {
        int temp(0);

        while (!AtEnd(s, index) && isdigit(s[index])) {
            temp *= 10;
            temp += s[index] - 48;
            index++;
        }

        return temp;
    }

    // пропуск точек и нулей
    void Next(const string& s, int& index) {
        while (!AtEnd(s, index) && !isdigit(s[index])) {
            index++;
        }
    }
};

int main() {
    // ...
    int n;
    cin >> n;

    string s;
    getline(cin, s);

    vector <DateTime> d(n);
    for (auto& i : d) {
        i.input();
    }

    sort(d.begin(), d.end(), [](const DateTime& a, const DateTime& b) {
        return a.minutes < b.minutes;
    });


    int m(0);
    for (int i(1); i < n; i += 2) {
        m += d[i].minutes - d[i - 1].minutes + 1;
    }

    cout << m/60 << ":" << setw(2) << setfill('0') << m%60;

    return 0;
}