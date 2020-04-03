#ifndef __01_INSERT_HPP__
#define __01_INSERT_HPP__

#include <vector>
#include <cstdlib>

/// Сортировка вставками
void sort_insert(std::vector<int> &arr, bool desc=false)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        int tmp = arr[i];
        int j = i - 1;
        while (j >= 0 && (desc && tmp > arr[j] || !desc && tmp < arr[j]))
        {
            arr[j + 1] = arr[j];
            arr[j] = tmp;
            j--;
        }
    }
}

#endif // __01_INSERT_HPP__
