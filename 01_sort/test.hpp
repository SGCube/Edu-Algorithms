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

#define SORT_TEST(sort, index) \
    { \
        std::vector<int> to_sort = source[(index)]; \
        (sort)(to_sort); \
        ASSERT_TRUE(to_sort == sorted[(index)]); \
    }

#define SORT_TEST_UNI(sort_uni, index) \
    { \
        std::vector<int> to_sort = source[i]; \
        (sort_uni)(to_sort.begin(), to_sort.end(), cmp<int>); \
        ASSERT_TRUE(to_sort == sorted[i]); \
    }

#define SORT_TEST_UNI_F(sort_uni) \
    { \
        std::vector<float> to_sort_f = source_f; \
        (sort_uni)(to_sort_f.begin(), to_sort_f.end(), cmp<float>); \
        ASSERT_TRUE(to_sort_f == sorted_f); \
    }

#define SORT_TEST_UNI_ARR(sort_uni) \
    { \
        std::array<int, 6> to_sort_a = source_a; \
        (sort_uni)(to_sort_a.begin(), to_sort_a.end(), cmp<int>); \
        ASSERT_TRUE(to_sort_a == sorted_a); \
    }

#define SORT_TEST_UNI_PTR(sort_uni) \
    { \
        int to_sort_ptr[6]; \
        for (size_t i = 0; i < 6; i++) \
            to_sort_ptr[i] = source_ptr[i]; \
        (sort_uni)(to_sort_ptr, to_sort_ptr + 6, cmp<int>); \
        for (size_t i = 0; i < 6; i++) \
            ASSERT_TRUE(to_sort_ptr[i] == sorted_ptr[i]); \
    }

#define SORT_TESTS(name, sort, sort_uni) \
    TEST_F(SortInsert, name##_OneElement) \
    { \
        SORT_TEST(sort_insert, 0); \
    } \
    \
    TEST_F(SortInsert, name##_AlreadySorted) \
    { \
        SORT_TEST(sort_insert, 1); \
    } \
    \
    TEST_F(SortInsert, name##_InverseSorted) \
    { \
        SORT_TEST(sort_insert, 2); \
    } \
    \
    TEST_F(SortInsert, name##_AllSame) \
    { \
        SORT_TEST(sort_insert, 3); \
    } \
    \
    TEST_F(SortInsert, name##_SomeSame) \
    { \
        SORT_TEST(sort_insert, 4); \
    } \
    \
    TEST_F(SortInsert, name##_NoSame) \
    { \
        SORT_TEST(sort_insert, 5); \
    } \
    \
    TEST_F(SortInsert, name##_OneElement_Uni) \
    { \
        SORT_TEST_UNI(sort_insert_uni, 0); \
    } \
    \
    TEST_F(SortInsert, name##_AlreadySorted_Uni) \
    { \
        SORT_TEST_UNI(sort_insert_uni, 1); \
    } \
    \
    TEST_F(SortInsert, name##_InverseSorted_Uni) \
    { \
        SORT_TEST_UNI(sort_insert_uni, 2); \
    } \
    \
    TEST_F(SortInsert, name##_AllSame_Uni) \
    { \
        SORT_TEST_UNI(sort_insert_uni, 3); \
    } \
    \
    TEST_F(SortInsert, name##_SomeSame_Uni) \
    { \
        SORT_TEST_UNI(sort_insert_uni, 4); \
    } \
    \
    TEST_F(SortInsert, name##_NoSame_Uni) \
    { \
        SORT_TEST_UNI(sort_insert_uni, 5); \
    } \
    TEST_F(SortInsert, name##_Float_Uni) \
    { \
        SORT_TEST_UNI_F(sort_insert_uni); \
    } \
    TEST_F(SortInsert, name##_StdArray_Uni) \
    { \
        SORT_TEST_UNI_ARR(sort_insert_uni); \
    } \
    TEST_F(SortInsert, name##_Array_Uni) \
    { \
        SORT_TEST_UNI_PTR(sort_insert_uni); \
    }

#endif // __SORT_TEST_HPP__