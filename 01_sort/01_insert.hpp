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
        for (int j = i - 1; j >= 0 && tmp < arr[j]; j--)
        {
            arr[j + 1] = arr[j];
            arr[j] = tmp;
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
        for(Iter _j = _i - 1; _j - first >= 0 && cmp(tmp, *_j); _j--)
        {
            *(_j + 1) = *_j;
            *_j = tmp;
        }
    }
}

#endif // __01_INSERT_HPP__
