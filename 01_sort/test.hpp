#ifndef __SORT_TEST_HPP__
#define __SORT_TEST_HPP__

#include "gtest/gtest.h"

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

#define SORT_TEST(name, sort, sort_uni) \
    TEST_F(SortTest, name##_OneElement) \
    { \
        std::vector<int> to_sort = source[0]; \
        (sort)(to_sort); \
        ASSERT_TRUE(to_sort == sorted[0]); \
    } \
    \
    TEST_F(SortTest, name##_AlreadySorted) \
    { \
        std::vector<int> to_sort = source[1]; \
        (sort)(to_sort); \
        ASSERT_TRUE(to_sort == sorted[1]); \
    } \
    \
    TEST_F(SortTest, name##_InverseSorted) \
    { \
        std::vector<int> to_sort = source[2]; \
        (sort)(to_sort); \
        ASSERT_TRUE(to_sort == sorted[2]); \
    } \
    \
    TEST_F(SortTest, name##_AllSame) \
    { \
        std::vector<int> to_sort = source[3]; \
        (sort)(to_sort); \
        ASSERT_TRUE(to_sort == sorted[3]); \
    } \
    \
    TEST_F(SortTest, name##_SomeSame) \
    { \
        std::vector<int> to_sort = source[4]; \
        (sort)(to_sort); \
        ASSERT_TRUE(to_sort == sorted[4]); \
    } \
    \
    TEST_F(SortTest, name##_NoSame) \
    { \
        std::vector<int> to_sort = source[5]; \
        (sort)(to_sort); \
        ASSERT_TRUE(to_sort == sorted[5]); \
    } \
    \
    TEST_F(SortTest, name##_OneElement_Uni) \
    { \
        std::vector<int> to_sort = source[0]; \
        (sort_uni)(to_sort.begin(), to_sort.end(), cmp<int>); \
        ASSERT_TRUE(to_sort == sorted[0]); \
    } \
    \
    TEST_F(SortTest, name##_AlreadySorted_Uni) \
    { \
        std::vector<int> to_sort = source[1]; \
        (sort_uni)(to_sort.begin(), to_sort.end(), cmp<int>); \
        ASSERT_TRUE(to_sort == sorted[1]); \
    } \
    \
    TEST_F(SortTest, name##_InverseSorted_Uni) \
    { \
        std::vector<int> to_sort = source[2]; \
        (sort_uni)(to_sort.begin(), to_sort.end(), cmp<int>); \
        ASSERT_TRUE(to_sort == sorted[2]); \
    } \
    \
    TEST_F(SortTest, name##_AllSame_Uni) \
    { \
        std::vector<int> to_sort = source[3]; \
        (sort_uni)(to_sort.begin(), to_sort.end(), cmp<int>); \
        ASSERT_TRUE(to_sort == sorted[3]); \
    } \
    \
    TEST_F(SortTest, name##_SomeSame_Uni) \
    { \
        std::vector<int> to_sort = source[4]; \
        (sort_uni)(to_sort.begin(), to_sort.end(), cmp<int>); \
        ASSERT_TRUE(to_sort == sorted[4]); \
    } \
    \
    TEST_F(SortTest, name##_NoSame_Uni) \
    { \
        std::vector<int> to_sort = source[5]; \
        (sort_uni)(to_sort.begin(), to_sort.end(), cmp<int>); \
        ASSERT_TRUE(to_sort == sorted[5]); \
    } \
    TEST_F(SortTest, name##_Float_Uni) \
    { \
        std::vector<float> to_sort_f = source_f; \
        (sort_uni)(to_sort_f.begin(), to_sort_f.end(), cmp<float>); \
        ASSERT_TRUE(to_sort_f == sorted_f); \
    } \
    TEST_F(SortTest, name##_StdArray_Uni) \
    { \
        std::array<int, 6> to_sort_a = source_a; \
        (sort_uni)(to_sort_a.begin(), to_sort_a.end(), cmp<int>); \
        ASSERT_TRUE(to_sort_a == sorted_a); \
    } \
    TEST_F(SortTest, name##_Array_Uni) \
    { \
        int to_sort_ptr[6]; \
        for (size_t i = 0; i < 6; i++) \
            to_sort_ptr[i] = source_ptr[i]; \
        (sort_uni)(to_sort_ptr, to_sort_ptr + 6, cmp<int>); \
        for (size_t i = 0; i < 6; i++) \
            ASSERT_TRUE(to_sort_ptr[i] == sorted_ptr[i]); \
    }

#endif // __SORT_TEST_HPP__