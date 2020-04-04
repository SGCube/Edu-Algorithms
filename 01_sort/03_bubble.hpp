#ifndef __03_BUBBLE_HPP__
#define __03_BUBBLE_HPP__

#include <vector>
#include <cstdlib>

/// Сортировка пузырьком

// Частный
void sort_bubble(std::vector<int> &arr)
{
    bool sorted = false;
    for (size_t i = 0; i < arr.size() && !sorted; i++)
    {
        sorted = true;
        for (size_t j = 1; j < arr.size() - i; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                std::swap(arr[j - 1], arr[j]);
                sorted = false;
            }
        }
    }
}

// Универсальный
template <class Iter, class Comp>
void sort_bubble_uni(Iter first, Iter last, Comp cmp)
{
    if (first == last)
        return;

    bool sorted = false;
    for (Iter _i = last; _i - first >= 0 && !sorted; _i--)
    {
        sorted = true;
        for (Iter _j = first + 1; _j < _i; _j++)
        {
            if (cmp(*(_j), *(_j - 1)))
            {
                auto tmp = *(_j);
                *(_j) = *(_j -1);
                *(_j - 1) = tmp;
                sorted = false;
            }
        }
    }
}

#endif // __03_BUBBLE_HPP__
