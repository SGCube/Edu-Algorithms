#ifndef __02_SHELL_HPP__
#define __01_SHELL_HPP__

#include <vector>
#include <cstdlib>

/// Сортировка вставками

// Частный
void sort_shell(std::vector<int> &arr)
{
    for (auto d = arr.size(); d > 0; d >>= 1)
    {
        for (size_t i = d; i < arr.size(); i += d)
        {
            int tmp = arr[i];
            int j = i - d;
            while (j >= d && tmp < arr[j])
            {
                arr[j + d] = arr[j];
                arr[j] = tmp;
                j -= d;
            }
        }
    }
}

// Универсальный
/*template <class Iter, class Comp>
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
}*/

#endif // __02_SHELL_HPP__
