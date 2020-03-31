#include <cstdlib>
#include "sort.hpp"

/// Сортировка вставками
void sort_insert(std::vector<int> &arr, bool (*cmp_func)(int, int))
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        int tmp = arr[i];
        int j = i - 1;
        while (j >= 0 && cmp_func(tmp, arr[j]))
        {
            arr[j + 1] = arr[j];
            arr[j] = tmp;
            j--;
        }
    }
}

/// Функции сравнения
bool cmp_int_larger(int a, int b)
{
    return a > b;
}

bool cmp_int_smaller(int a, int b)
{
    return a < b;
}
