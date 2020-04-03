#include "gtest/gtest.h"
#include "01_insert.hpp"

/// INT

TEST(InsertSort, OneElement)
{
    std::vector<int> source = { 1 };
    std::vector<int> sorted = { 1 };
    sort_insert(source);
    ASSERT_TRUE(source == sorted);
}

TEST(InsertSort, AlreadySorted)
{
    std::vector<int> source = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::vector<int> sorted = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    sort_insert(source);
    ASSERT_TRUE(source == sorted);
}

TEST(InsertSort, InverseSorted)
{
    std::vector<int> source = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    std::vector<int> sorted = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    sort_insert(source);
    ASSERT_TRUE(source == sorted);
}

TEST(InsertSort, AllSame)
{
    std::vector<int> source = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    std::vector<int> sorted = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    sort_insert(source);
    ASSERT_TRUE(source == sorted);
}

TEST(InsertSort, SomeSame)
{
    std::vector<int> source = { 5, 4, 0, 2, -1, 4 };
    std::vector<int> sorted = { -1, 0, 2, 4, 4, 5 };
    sort_insert(source);
    ASSERT_TRUE(source == sorted);
}

TEST(InsertSort, NoSame)
{
    std::vector<int> source = { 5, 4, 0, 2, -1, 3 };
    std::vector<int> sorted = { -1, 0, 2, 3, 4, 5 };
    sort_insert(source);
    ASSERT_TRUE(source == sorted);
}

/// UNIVERSAL

TEST(InsertSortUni, OneElement)
{
    std::vector<int> source = { 1 };
    std::vector<int> sorted = { 1 };
    sort_insert_uni(source.begin(), source.end(), cmp<int>);
    ASSERT_TRUE(source == sorted);
}

TEST(InsertSortUni, AlreadySorted)
{
    std::vector<int> source = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::vector<int> sorted = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    sort_insert_uni(source.begin(), source.end(), cmp<int>);
    ASSERT_TRUE(source == sorted);
}

TEST(InsertSortUni, InverseSorted)
{
    std::vector<int> source = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    std::vector<int> sorted = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    sort_insert_uni(source.begin(), source.end(), cmp<int>);
    ASSERT_TRUE(source == sorted);
}

TEST(InsertSortUni, AllSame)
{
    std::vector<int> source = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    std::vector<int> sorted = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    sort_insert_uni(source.begin(), source.end(), cmp<int>);
    ASSERT_TRUE(source == sorted);
}

TEST(InsertSortUni, SomeSame)
{
    std::vector<int> source = { 5, 4, 0, 2, -1, 4 };
    std::vector<int> sorted = { -1, 0, 2, 4, 4, 5 };
    sort_insert_uni(source.begin(), source.end(), cmp<int>);
    ASSERT_TRUE(source == sorted);
}

TEST(InsertSortUni, NoSame)
{
    std::vector<int> source = { 5, 4, 0, 2, -1, 3 };
    std::vector<int> sorted = { -1, 0, 2, 3, 4, 5 };
    sort_insert_uni(source.begin(), source.end(), cmp<int>);
    ASSERT_TRUE(source == sorted);
}

TEST(InsertSortUni, FloatType)
{
    std::vector<float> source = { 5.4, -4.2, 0.1, 0, 0.15, 3 };
    std::vector<float> sorted = { -4.2, 0, 0.1, 0.15, 3, 5.4 };
    sort_insert_uni(source.begin(), source.end(), cmp<int>);
    ASSERT_TRUE(source == sorted);
}

TEST(InsertSortUni, ArrayContainer)
{
    std::array<int> source = { 5, 4, 0, 2, -1, 3 };
    std::array<int> sorted = { -1, 0, 2, 3, 4, 5 };
    sort_insert_uni(source.begin(), source.end(), cmp<int>);
    ASSERT_TRUE(source == sorted);
}

TEST(InsertSortUni, ListContainer)
{
    std::list<int> source = { 5, 4, 0, 2, -1, 3 };
    std::list<int> sorted = { -1, 0, 2, 3, 4, 5 };
    sort_insert_uni(source.begin(), source.end(), cmp<int>);
    ASSERT_TRUE(source == sorted);
}
