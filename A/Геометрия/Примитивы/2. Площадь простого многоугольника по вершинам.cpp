/*
* ------------ ПЛОЩАДЬ ПРОСТОГО МНОГОУГОЛЬНИКА ПО ВЕРШИНАМ ------------
^ O(n)
$ площадь_простого_многоугольника_по_вершинам
# ориентированная_площадь_треугольника
? Пусть дан простой многоугольник (т.е. без самопересечений, но не обязательно выпуклый) - т.е. ПРОСТОЙ, заданный координатами своих вершин в порядке обхода по или против часовой стрелки. Требуется найти его площадь. Есть два способа.

& Первый способ:
? Будем перебирать все ребра по или против часовой стрелки. Допустим, будем обходить по часовой стрелке. Опустим из каждой вершины перпендикуляр на ось Ox. Например, из стороны AB опустим перпендикуляры AG и BH. Тогда ей можно сопоставить трапецию ABHG, где AG и BH - основания (они равны координатам A.y и B.y соответственно), а высота GH, равная разности x координат A и B (чтобы сохранить знак площади нужно из A.x вычитать B.y). Зная, что площадь трапеции равна полусумме оснований, умноенной на высоту, легко, перебрав все ребра, и просуммировав все площадт трапеций, полученных из каждого ребра, найти площадь искомого многоугольника.

? Чтобы оптимизировать вычисления, деление на два можно выполнить после перебора всех ребер (__1__).
! d - это уже готовый многоугольник со всеми ребрами, то есть последняя и первая точка также соединены ребром (d.front() равно d.back()).

& Второй способ:
? Можно поступить другим образом. Выберем произвольно точку O, переберём все рёбра, прибавляя к ответу ориентированную площадь треугольника, образованного ребром и точкой O Опять же, благодаря знаку, вся лишняя площадь сократится, и останется только ответ. Этот способ хорош тем, что его проще обобщить на более сложные случаи (например, когда некоторые стороны - не прямые, а дуги окружности).

*/

// первый способ
double SimplePolygonArea(vector <Point> d) {
    double area(0);

    for (int i(1); i < d.size(); i++) 
        area += (d[i].x - d[i - 1].x) * (d[i].y + d[i - 1].y);
    
    return abs(area/2); // % 1
}

// второй способ
double SimplePolygonArea(vector <Point> d) {
    Point o(0, 0);
    double area(0);

    for (int i(1); i < d.size(); i++)
        area += TriangleSignArea(d[i-1], d[i], o); //! опсиано в [Три точки.cpp] 

    return abs(area / 2);
}