#include <stdio.h>
#include <string.h>

#include "cut.h"

int add(int a, int b)
{
    return a + b;
}

CUT_CASE(add_001)
{
    int rel = add(3, 4);
    CUT_EXPECT_INT_EQ(7, rel);
}

// a wrong test case on purpose
CUT_CASE(add_002)
{
    int rel = add(4, 5);
    CUT_EXPECT_INT_EQ(8, rel);
}

char *str_str(char *s, char *wanted)
{
    return strstr(s, wanted);
}

CUT_CASE(str_str_001)
{
    char *rel = str_str("1234567", "456");
    CUT_EXPECT_STR_EQ("4567", rel);
}

// another wrong test case on purpose
CUT_CASE(str_str_002)
{
    char *rel = str_str("1234567", "123");
    CUT_EXPECT_PTR_NULL(rel);
}

CUT_CASE(str_str_003)
{
    char *rel = str_str("1234567", "789");
    CUT_EXPECT_PTR_NULL(rel);
}


CUT_SUITE(suite_001)
{
    CUT_SUITE_ADD_TC(add_001);
    CUT_SUITE_ADD_TC(add_002);
    CUT_SUITE_ADD_TC(str_str_001);
    CUT_SUITE_ADD_TC(str_str_002);
    CUT_SUITE_ADD_TC(str_str_003);
}

int main()
{
    CUT_RUN_SUITE(suite_001);
    CUT_REPORT();
    
    return 0;
}
