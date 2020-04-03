#include <vector>
#include <array>
#include <list>
#include "gtest/gtest.h"
#include "cmp.hpp"

#include "02_shell.hpp"

/// INT

TEST(ShellSort, OneElement)
{
    std::vector<int> source = { 1 };
    std::vector<int> sorted = { 1 };
    sort_shell(source);
    ASSERT_TRUE(source == sorted);
}

TEST(ShellSort, AlreadySorted)
{
    std::vector<int> source = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::vector<int> sorted = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    sort_shell(source);
    ASSERT_TRUE(source == sorted);
}

TEST(ShellSort, InverseSorted)
{
    std::vector<int> source = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    std::vector<int> sorted = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    sort_shell(source);
    ASSERT_TRUE(source == sorted);
}

TEST(ShellSort, AllSame)
{
    std::vector<int> source = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    std::vector<int> sorted = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    sort_shell(source);
    ASSERT_TRUE(source == sorted);
}

TEST(ShellSort, SomeSame)
{
    std::vector<int> source = { 5, 4, 0, 2, -1, 4 };
    std::vector<int> sorted = { -1, 0, 2, 4, 4, 5 };
    sort_shell(source);
    ASSERT_TRUE(source == sorted);
}

TEST(ShellSort, NoSame)
{
    std::vector<int> source = { 5, 4, 0, 2, -1, 3 };
    std::vector<int> sorted = { -1, 0, 2, 3, 4, 5 };
    sort_shell(source);
    ASSERT_TRUE(source == sorted);
}

/// UNIVERSAL

/*TEST(ShellSortUni, OneElement)
{
    std::vector<int> source = { 1 };
    std::vector<int> sorted = { 1 };
    sort_shell_uni(source.begin(), source.end(), cmp<int>);
    ASSERT_TRUE(source == sorted);
}

TEST(ShellSortUni, AlreadySorted)
{
    std::vector<int> source = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::vector<int> sorted = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    sort_shell_uni(source.begin(), source.end(), cmp<int>);
    ASSERT_TRUE(source == sorted);
}

TEST(ShellSortUni, InverseSorted)
{
    std::vector<int> source = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    std::vector<int> sorted = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    sort_shell_uni(source.begin(), source.end(), cmp<int>);
    ASSERT_TRUE(source == sorted);
}

TEST(ShellSortUni, AllSame)
{
    std::vector<int> source = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    std::vector<int> sorted = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    sort_shell_uni(source.begin(), source.end(), cmp<int>);
    ASSERT_TRUE(source == sorted);
}

TEST(ShellSortUni, SomeSame)
{
    std::vector<int> source = { 5, 4, 0, 2, -1, 4 };
    std::vector<int> sorted = { -1, 0, 2, 4, 4, 5 };
    sort_shell_uni(source.begin(), source.end(), cmp<int>);
    ASSERT_TRUE(source == sorted);
}

TEST(ShellSortUni, NoSame)
{
    std::vector<int> source = { 5, 4, 0, 2, -1, 3 };
    std::vector<int> sorted = { -1, 0, 2, 3, 4, 5 };
    sort_shell_uni(source.begin(), source.end(), cmp<int>);
    ASSERT_TRUE(source == sorted);
}

TEST(ShellSortUni, FloatType)
{
    std::vector<float> source = { 5.4, -4.2, 0.1, 0, 0.15, 3 };
    std::vector<float> sorted = { -4.2, 0, 0.1, 0.15, 3, 5.4 };
    sort_shell_uni(source.begin(), source.end(), cmp<int>);
    ASSERT_TRUE(source == sorted);
}

TEST(ShellSortUni, ArrayContainer)
{
    std::array<int, 6> source = { 5, 4, 0, 2, -1, 3 };
    std::array<int, 6> sorted = { -1, 0, 2, 3, 4, 5 };
    sort_shell_uni(source.begin(), source.end(), cmp<int>);
    ASSERT_TRUE(source == sorted);
}

TEST(ShellSortUni, Pointers)
{
    int source[] = { 5, 4, 0, 2, -1, 3 };
    int sorted[] = { -1, 0, 2, 3, 4, 5 };
    sort_shell_uni(source, source + 6, cmp<int>);
    bool result = true;
    for (size_t i = 0; i < 6 && result; i++)
    {
        if (source[i] != sorted[i])
            result = false;
    }
    ASSERT_TRUE(result);
}*/
