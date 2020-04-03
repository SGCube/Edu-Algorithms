#include <iostream>
#include <vector>
#include <cstdlib>
#include <iterator>

#include "sort.hpp"
#include "cmp.hpp"

template <class Iter>
void input(Iter b, Iter e)
{
    for (Iter _i = b; _i != e; _i++)
        std::cin >> *_i;
}

template <class Iter>
void output(Iter b, Iter e)
{
    for (Iter _i = b; _i != e; _i++)
        std::cout << *_i << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    int n = 0;
    std::cout << "Enter size of array: " << std::endl;
    std::cin >> n;
    if (n < 1)
    {
        std::cout << "Invalid size value!\n" << std::endl;
        return 0;
    }

    std::vector<int> arr(n), to_sort(n);
    std::cout << "Enter array: " << std::endl;
    input(arr.begin(), arr.end());
    
    std::cout << std::endl << "Source:\t";
    output(arr.begin(), arr.end());

    std::cout << "Insert:\t";
    to_sort = arr;
    sort_insert_uni(to_sort.begin(), to_sort.end(), cmp<int>);
    output(to_sort.begin(), to_sort.end());

    std::cout << "Shell:\t";
    to_sort = arr;
    sort_shell(to_sort);
    output(to_sort.begin(), to_sort.end());

    return 0;
}