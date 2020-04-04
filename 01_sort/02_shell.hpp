#ifndef __02_SHELL_HPP__
#define __01_SHELL_HPP__

#include <vector>
#include <cstdlib>

/// Сортировка Шелла

// Частный
void sort_shell(std::vector<int> &arr)
{
    for (auto d = arr.size(); d > 0; d >>= 1)
    {
        for (size_t i = d; i < arr.size(); i += d)
        {
            int tmp = arr[i];
            for (int j = i - d; j >= 0 && tmp < arr[j]; j -= d)
            {
                arr[j + d] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

// Универсальный
template <class Iter, class Comp>
void sort_shell_uni(Iter first, Iter last, Comp cmp)
{
    if (first == last)
        return;

    for (auto d = last - first; d > 0; d >>= 1)
    {
        for (Iter _i = first + d; _i != last; _i += d)
        {
            auto tmp = *_i;
            for(Iter _j = _i - d; _j - first >= 0 && cmp(tmp, *_j); _j -= d)
            {
                *(_j + d) = *_j;
                *_j = tmp;
            }
        }
    }
}

#endif // __02_SHELL_HPP__
