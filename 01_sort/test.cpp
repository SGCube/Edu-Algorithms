#include "gtest/gtest.h"
#include "sort.hpp"
#include "cmp.hpp"

class SortTest : public ::testing::Test
{
protected:
	void SetUp() {}
	void TearDown() {}
    
	std::vector<std::vector<int>> source = {
        { 1 },
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 },
        { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 5, 4, 0, 2, -1, 4 },
        { 5, 4, 0, 2, -1, 3 }
    };
    std::vector<std::vector<int>> sorted = {
        { 1 },
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 },
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { -1, 0, 2, 4, 4, 5 },
        { -1, 0, 2, 3, 4, 5 }
    };
    std::vector<float> source_f = { 5.4, -4.2, 0.1, 0, 0.15, 3 };
    std::vector<float> sorted_f = { -4.2, 0, 0.1, 0.15, 3, 5.4 };

    std::array<int, 6> source_a{ { 5, 4, 0, 2, -1, 4 } };
    std::array<int, 6> sorted_a{ { -1, 0, 2, 4, 4, 5 } };

    int source_ptr[6] = { 5, 4, 0, 2, -1, 4 };
    int sorted_ptr[6] = { -1, 0, 2, 4, 4, 5 };
    
};

#define SORT_TESTING(sort) \
    for (size_t i = 0; i < source.size(); i++) \
    { \
        std::vector<int> to_sort = source[i]; \
        (sort)(to_sort); \
        ASSERT_TRUE(to_sort == sorted[i]); \
    }

#define SORT_TESTING_UNI(sort_uni) \
    for (size_t i = 0; i < source.size(); i++) \
    { \
        std::vector<int> to_sort = source[i]; \
        (sort_uni)(to_sort.begin(), to_sort.end(), cmp<int>); \
        ASSERT_TRUE(to_sort == sorted[i]); \
    } \
    std::vector<float> to_sort_f = source_f; \
    (sort_uni)(to_sort_f.begin(), to_sort_f.end(), cmp<float>); \
    ASSERT_TRUE(to_sort_f == sorted_f); \
    \
    std::array<int, 6> to_sort_a = source_a; \
    (sort_uni)(to_sort_a.begin(), to_sort_a.end(), cmp<int>); \
    ASSERT_TRUE(to_sort_a == sorted_a); \
    \
    int to_sort_ptr[6]; \
    for (size_t i = 0; i < 6; i++) \
        to_sort_ptr[i] = source_ptr[i]; \
    (sort_uni)(to_sort_ptr, to_sort_ptr + 6, cmp<int>); \
    for (size_t i = 0; i < 6; i++) \
        ASSERT_TRUE(to_sort_ptr[i] == sorted_ptr[i]);

TEST_F(SortTest, InsertSort)
{
    SORT_TESTING(sort_insert);
}

TEST_F(SortTest, InsertSortUni)
{
    SORT_TESTING_UNI(sort_insert_uni);
}

TEST_F(SortTest, ShellSort)
{
    SORT_TESTING(sort_shell);
}

TEST_F(SortTest, ShellSortUni)
{
    SORT_TESTING_UNI(sort_shell_uni);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}