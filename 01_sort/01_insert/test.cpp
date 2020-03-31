#include "gtest/gtest.h"
#include "sort.hpp"

TEST(OneElement, InsertSort)
{
    std::vector<int> source = { 1 };
    std::vector<int> sorted = { 1 };
    sort_insert(source, cmp_int_smaller);
    ASSERT_TRUE(source == sorted);
}

TEST(AlreadySorted, InsertSort)
{
    std::vector<int> source = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::vector<int> sorted = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    sort_insert(source, cmp_int_smaller);
    ASSERT_TRUE(source == sorted);
}

TEST(InverseSorted, InsertSort)
{
    std::vector<int> source = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    std::vector<int> sorted = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    sort_insert(source, cmp_int_smaller);
    ASSERT_TRUE(source == sorted);
}

TEST(AllSame, InsertSort)
{
    std::vector<int> source = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    std::vector<int> sorted = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    sort_insert(source, cmp_int_smaller);
    ASSERT_TRUE(source == sorted);
}

TEST(SomeSame, InsertSort)
{
    std::vector<int> source = { 5, 4, 0, 2, -1, 4 };
    std::vector<int> sorted = { -1, 0, 2, 4, 4, 5 };
    sort_insert(source, cmp_int_smaller);
    ASSERT_TRUE(source == sorted);
}

TEST(NoSame, InsertSort)
{
    std::vector<int> source = { 5, 4, 0, 2, -1, 3 };
    std::vector<int> sorted = { -1, 0, 2, 3, 4, 5 };
    sort_insert(source, cmp_int_smaller);
    ASSERT_TRUE(source == sorted);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}