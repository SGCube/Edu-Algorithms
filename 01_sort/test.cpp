#include "gtest/gtest.h"
#include "sort.hpp"
#include "cmp.hpp"
#include "test.hpp"

SORT_TESTS(InsertSort, sort_insert, sort_insert_uni)

SORT_TESTS(ShellSort, sort_shell, sort_shell_uni)

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}