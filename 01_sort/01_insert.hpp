#ifndef __01_INSERT_HPP__
#define __01_INSERT_HPP__

#include <vector>
#include <cstdlib>

/// Сортировка вставками

// Частный
void sort_insert(std::vector<int> &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        int tmp = arr[i];
        int j = i - 1;
        while (j >= 0 && tmp < arr[j])
        {
            arr[j + 1] = arr[j];
            arr[j] = tmp;
            j--;
        }
    }
}

// Универсальный
template <class Iter, class Comp>
void sort_insert_uni(Iter first, Iter last, Comp cmp)
{
    if (first == last)
        return;

    for (Iter _i = first + 1; _i != last; _i++)
    {
        auto tmp = *_i;
        Iter _j = _i - 1;
        while (_j != first - 1 && cmp(tmp, *_j))
        {
            *(_j + 1) = *_j;
            *_j = tmp;
            _j--;
        }
    }
}

#endif // __01_INSERT_HPP__
