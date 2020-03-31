#include <iostream>
#include <vector>
#include <cstdlib>

#include "sort.hpp"

template <typename  T>
void input_array(std::vector<T> &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
        std::cin >> arr[i];
}

template <typename T>
void print_array(std::vector<T> &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    if (argc > 1 && std::string(argv[1]) == "--memcheck")
    {
        std::vector<int> arr = { 5, 4, 0, 2, -1, 4 };
        sort_insert(arr, cmp_int_larger);
        return 0;
    }
    int n = 0;
    std::cout << "Enter size of array: " << std::endl;
    std::cin >> n;
    if (n < 1)
    {
        std::cout << "Invalid size value!\n" << std::endl;
        return 0;
    }

    std::vector<int> arr(n);
    std::cout << "Enter array: " << std::endl;
    input_array<int>(arr);
    
    std::cout << "Source array: " << std::endl;
    print_array<int>(arr);

    sort_insert(arr, cmp_int_larger);
    std::cout << "Sorted array: " << std::endl;
    print_array(arr);

    return 0;
}