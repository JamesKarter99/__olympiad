/*
* ------------ ФЕРМЕР ------------
& Дианмика - 2
~ двумерная_динамика
? Итак, нужно найти квадрат в двумерном массиве, состоящий из единиц. Очевидно, что минимальным квадратом будет единица. Что делаем? Зведем второй двумерный массив, в котором p[i][j] = k, если клетка d[i][j] является правым нижним углом квадратом из единиц со стороной длинной k. То есть, это один из возможных вариантов ответа. 

? Запишем в верхнюю строчку и левый столбец p единицы, если в d на соответсвующих позициях стоят единицы (__1__). Остается случай, когда нужно заполнить p[i][j] для положительных i и j. Все просто: в p[i][j] равно минимальному значению из верхней, левой и верхней левой клетки на одну позицию от текущей в p плюс 1 (__2__), если соответствующие клетки в массиве d заполнены единицами. Это условие означает, что четыре данные клетки образуют продолжение квадрата.

? В ответ выводим максимальное значение длинны в p[i][j] в квадрате, т.е. площадь наибольшего квадрата.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>

using namespace std;

using line = vector <int>;
using matrix = vector <line>;

int main() {
	// ...
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	matrix d(n, line(n)), p(d);
	for (int i(0); i < n; i++) {
		for (int j(0); j < n; j++) {
			char c;
			cin >> c;
			
			d[i][j] = c - 48;
		}
	}

	p[0][0] = (d[0][0] == 1); // % 1

	int mx(0);
	for (int i(0); i < n; i++) {
		for (int j(0); j < n; j++) {
			// возможно получится расширить текущий участок
			if (d[i][j]) {
				p[i][j] = 1;

				if (i && !j) {
					p[i][j] = 1; // % 1
				}
				else if (j && !i) {
					p[i][j] = 1; // % 1
				}
				else if (i && j) {
					int u = d[i - 1][j];
					int l = d[i][j - 1];
					int m = d[i - 1][j - 1];

					if (u && l && m) {
						p[i][j] = min(p[i - 1][j - 1], min(p[i - 1][j], p[i][j - 1])) + 1; // % 2
					}
				}
			}
			
			mx = max(mx, p[i][j]);

		}
	}

	cout << mx*mx;
	
	return 0;
}
