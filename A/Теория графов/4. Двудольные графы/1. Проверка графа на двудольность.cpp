/*
* ------------ ПРОВЕРКА ГРАФА НА ДВУДОЛЬНОСТЬ ------------
^ O(n + m)
# bfs # список_смежности
? Граф называется двудольным, если его вершины можно раскрасить двумя цветами, так что никакие две соседние вершины не будут окрашены одним цветом. Идея в том, чтобы выбрать два цвета X и Y,  окрасить начальную вершину цветом X, всех ее соседей – цветом Y, всех их соседей - цветом X и т.д. Если в какой-то момент получается так, что две соседние вершины окрашены одним цветом (__1__), то граф не является двудольным. В противном случае граф двудольный. 

? Для решения могут использоваться оба способа обхода. Граф представлен в виде списков смежностей d, массив color содержит информацию о раскраске графа.

warning: пока что на практике себя лучше показал обход в ширину (задача ACMP -> курсы -> олимпиадные задачи -> теория графов - 1 -> Поиск в глубину -> Банкет).

*/

const int WHITE = 0;
const int GRAY  = 1; 
const int BLACK = 2;

color[i] = GRAY;
q.push(i);

while (!q.empty()) {
    int curr = q.front();
    q.pop();

    for (auto next : d[curr]) {
        if (color[next] == WHITE) {
            q.push(next);
            color[next] = 3 - color[curr];
        }
        if (color[next] == color[curr]) { // % 1
            // ! граф не двудолен!!!
        }
    }
}