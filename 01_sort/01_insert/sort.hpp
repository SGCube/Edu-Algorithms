#include <vector>

/// Сортировка вставками
void sort_insert(std::vector<int> &arr, bool (*cmp_func)(int, int));

/// Функции сравнения
bool cmp_int_larger(int a, int b);

bool cmp_int_smaller(int a, int b);
