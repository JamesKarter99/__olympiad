/*
! ---- Сохранить изменения после работы ------------------------------------------------
git add *
git commit -am "Изменения на [дата]."
git push origin insider

! ---- Разделы -------------------------------------------------------------------------
& A      - алгоритмы и стуктуры данных
& H      - хитрости языка C++ или другие хитрости
& L      - сложные и интересные моменты языка C++ или других
& O      - олимпиадные задачи (релаьные)
& P      - задачи с сайтов

! ---- Текстовые отметки ---------------------------------------------------------------
~ ссылки
         ? (__1__) - ссылка в тексте
         % 1       - то, на что ссылается текст, в коде


! ---- Цвета ---------------------------------------------------------------------------
&        - раздел, тема или то, как найти задачу в сборниках
!        - обратить особое вынимание
todo     - то, что нужно сделать. Это я еще не понял или не доделал
^        - O(n) скорость работы алгоритмы
code:    - что-то в коде, на что нужно обратить внимание, какой-то метод или что-то интересное
%        - ссылки в коде
warning: - что-то интересное
$        - понятия, которые объясняются в данном алгоритме/структуре данных (исп. только в разделе A)
#        - теги в алгоритмах и структурах данных (исп. только в разделе A)
>        - список
?        - описание
~        - теги в задачах (исп. только в разделе P)


! ---- Теги в задачах ------------------------------------------------------------------
& ---- ГЕОМЕТРИЯ -----------------------------------------------------------------------
    ~ вычислительная_геометрия                                                       (1)
    ~ ориентированная_площадь_треугольника                                           (0)
    ~ площадь_простого_многоугольника                                                (1)

& ---- ГРАФЫ --------------------------------------------------------------------------- 
    ~ ли                                                                             (1)

    ~ дейкстра                                                                       (2)
    ~ дейкстра_с_восстановлением_пути                                                (1)

    ~ флойд                                                                          (7) 
    ~ флойд_поиск_вершин_на_отрицательных_циклах                                     (1) 
    ~ флойд_проверка_на_наличие_цикла                                                (2)
    ~ флойд_проверка_на_наличие_отрицательного_цикла                                 (1)
    ~ флойд_транзитивное_замыкание                                                   (1)

    ~ форд_беллман                                                                   (2)
    ~ форд_беллман_проверка_на_наличие_отрицательного_цикла                          (1)
    ~ форд_беллман_проверка_на_наличие_отриц_цикла_c_восстановлением                 (1)

    ~ bfs_кратчайшее_расстояние                                                      (2)

    ~ dfs                                                                            (4)
    ~ dfs_планарный_граф                                                             (5)
    ~ dfs_проверка_на_ацикличность                                                   (2)
    ~ dfs_проверка_на_принадлежность_к_классу_деревьев                               (1)
    ~ dfs_с_расстояниями_от_начальной_вершины                                        (1)

& ---- ДА ------------------------------------------------------------------------------ 
    ~ динное_длинное_сложение                                                        (1)

& ---- ДП И РЕКУРСИЯ ------------------------------------------------------------------- 
    ~ двумерная_динамика                                                             (3)
    ~ одномерная_динамика                                                           (11)
    ~ рекуррентные_соотношения                                                       (1)
    ~ рекурсия                                                                       (3)
    ~ рекурсия_с_мемоизацией                                                         (1)

& ---- СОРТИРОВКА И ПОИСК --------------------------------------------------------------
    ~ бинарный_поиск_вещественный                                                    (1)
    ~ сортировка_выбором                                                             (1) 
    ~ сортировка_подсчетом                                                           (1)
    ~ сортировка_пузырьком                                                           (1)

& ---- СТРОКИ -------------------------------------------------------------------------- 
    ~ палиндром                                                                      (1)
    ~ полиномиальное_хеширование                                                     (1)
    ~ преффикс_функция                                                               (2)

& ---- СТУКТУРЫ ДАННЫХ------------------------------------------------------------------ 
    ~ dsu                                                                            (1)
    ~ sqrt_декомпозиция                                                              (1)

& ---- ТЕОРИЯ ЧИСЕЛ -------------------------------------------------------------------- 
    ~ gcd                                                                            (4)
    ~ lcm                                                                            (1)
    ~ простые_числа                                                                  (1)
    ~ факторизация                                                                   (2)

& ---- C++ STL ------------------------------------------------------------------------- 
    ~ binarysearch                                                                   (1)
    ~ bitset                                                                         (1)
    ~ distance                                                                       (1)
    ~ map                                                                            (2)
    ~ multiset                                                                       (1)
    ~ prioity_queue                                                                  (1)
    ~ STL                                                                            (5)
    ~ stoi                                                                           (1)
    ~ stringstream                                                                   (1)

& ---- ЭВРИСТИКА ----------------------------------------------------------------------- 
    ~ метод_двух_указателей                                                          (1)


? ---- Теги в алгоритмах и стуктурах данных ---------------------- (для поиска: $ - определение тега, # - использование)
> ---- Геометрия---- ------------------------------------------------------------------- 
    # ориентация_трех_точек 
    # ориентированная_площадь_треугольника
    # площадь_простого_многоугольника_по_вершинам    

> ---- Теория графов ------------------------------------------------------------------- 
    todo матрица_смежности
    todo планарный_граф
    todo список_смежности
    todo список_ребер

    todo ли

    # дейкстра
    # дейкстра_с_восстановлением_пути

    # флойд
    # флойд_поиск_вершин_на_отрицательных_циклах
    # флойд_проверка_на_наличие_цикла
    # флойд_проверка_на_наличие_отрицательного_цикла
    # флойд_транзитивное_замыкание

    # форд_беллман
    # форд_беллман_проверка_на_наличие_отрицательного_цикла
    # форд_беллман_проверка_на_наличие_отриц_цикла_c_восстановлением

    # bfs
    # bfs_кратчайшее_расстояние

    # dfs
    # dfs_планарный_граф
    # dfs_проверка_на_ацикличность
    # dfs_проверка_на_связность
    # dfs_проверка_на_принадлежность_к_классу_деревьев
    # dfs_с_расстояниями_от_начальной_вершины
    # dfs_с_цветами

> ---- Сортировки ---------------------------------------------------------------------- 
    # сортировка_вставками
    # сортировка_выбором
    # сортировка_пузырьком

> ---- Строки -------------------------------------------------------------------------- 
    # преффикс_функция

> ---- Структуры данных ---------------------------------------------------------------- 
    todo фибоначчиева_куча
    
    # dsu
    # sqrt_декомпозиция

*/


/*
* ------------ ШАБЛОН ------------
~ тег
? описание 
*/