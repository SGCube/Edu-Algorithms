#include <vector>
#include <cstdlib>
#include <iterator>
#include <ctime>

#include "sort.hpp"
#include "cmp.hpp"

int main(int argc, char **argv)
{
    srand(time(NULL));

    std::vector<int> arr = { 5, 4, 0, 0, 0, 2, -1, 4 };
    std::vector<int> to_sort;

    to_sort = arr;
    sort_insert(to_sort);
    to_sort = arr;
    sort_insert_uni(arr.begin(), arr.end(), cmp<int>);
    to_sort.clear();

    /*to_sort = arr;
    sort_shell(to_sort);
    to_sort = arr;
    sort_shell_uni(arr.begin(), arr.end(), cmp<int>);
    to_sort.clear();*/

    return 0;
}