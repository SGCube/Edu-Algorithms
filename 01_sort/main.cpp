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

#define SORT(s, sort, sort_uni) \
    std::cout << "== "#s" ==" << std::endl; \
    to_sort = arr; \
    (sort)(to_sort); \
    std::cout << "vec: "; \
    output(to_sort.begin(), to_sort.end()); \
    to_sort = arr; \
    (sort_uni)(to_sort.begin(), to_sort.end(), cmp<int>); \
    std::cout << "uni: "; \
    output(to_sort.begin(), to_sort.end());

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

    SORT(Insert, sort_insert, sort_insert_uni)
    SORT(Shell, sort_shell, sort_shell_uni)
    SORT(Bubble, sort_bubble, sort_bubble_uni)
    SORT(Shaker, sort_shaker, sort_shaker_uni)

    return 0;
}