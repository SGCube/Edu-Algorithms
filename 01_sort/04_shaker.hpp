#ifndef __04_SHAKER_HPP__
#define __04_SHAKER_HPP__

#include <vector>
#include <cstdlib>

/// Шейкерная сортировка

// Частный
void sort_shaker(std::vector<int> &arr)
{
    size_t first = 0, last = arr.size() - 1;
    bool sorted = false;
    while (!sorted && first < last)
    {
        sorted = true;
        for (size_t j = first + 1; j <= last; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                std::swap(arr[j - 1], arr[j]);
                sorted = false;
            }
        }
        last--;
        if (!sorted)
        {
            for (size_t j = last; j > first; j--)
            {
                if (arr[j - 1] > arr[j])
                {
                    std::swap(arr[j - 1], arr[j]);
                    sorted = false;
                }
            }
            first++;
        }
    }
}

// Универсальный
template <class Iter, class Comp>
void sort_shaker_uni(Iter first, Iter last, Comp cmp)
{
    if (first == last)
        return;

    Iter _first = first, _last = last;
    bool sorted = false;
    while (!sorted && _first < _last)
    {
        sorted = true;
        for (Iter _j = first + 1; _j < _last; _j++)
        {
            if (cmp(*(_j), *(_j - 1)))
            {
                auto tmp = *(_j);
                *(_j) = *(_j -1);
                *(_j - 1) = tmp;
                sorted = false;
            }
        }
        _last--;
        if (!sorted)
        {
            for (Iter _j = _last - 1; _j > _first; _j--)
            {
                if (cmp(*(_j), *(_j - 1)))
                {
                    auto tmp = *(_j);
                    *(_j) = *(_j -1);
                    *(_j - 1) = tmp;
                    sorted = false;
                }
            }
            _first++;
        }
    }
}

#endif // __04_SHAKER_HPP__
