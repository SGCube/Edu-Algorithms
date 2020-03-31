#include <vector>

/// Сортировка вставками
void sort_insert(std::vector<int> &arr, bool desc=false);

/// Функции сравнения
template <class T>
bool cmp_int_larger(const T &a, const T &b);

template <class T>
bool cmp_int_smaller(const T &a, const T &b);
