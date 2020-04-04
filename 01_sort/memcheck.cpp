#include <vector>
#include <cstdlib>
#include <iterator>
#include <ctime>

#include "sort.hpp"
#include "cmp.hpp"

#define MEMCHECK(sort, sort_uni) \
    to_sort = arr; \
    (sort)(to_sort); \
    to_sort = arr; \
    (sort_uni)(arr.begin(), arr.end(), cmp<int>); \
    to_sort.clear();

int main(int argc, char **argv)
{
    srand(time(NULL));

    std::vector<int> arr = { 5, 4, 0, 0, 0, 2, -1, 4 };
    std::vector<int> to_sort;

    MEMCHECK(sort_insert, sort_insert_uni)

    MEMCHECK(sort_shell, sort_shell_uni)

    MEMCHECK(sort_bubble, sort_bubble_uni)

    to_sort.clear();

    return 0;
}