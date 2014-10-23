## CUT ##
cut is a simple **C** **U**nit **T**est framework, a single header file `cut.h` contained.

The cut is inspired by [MinUnit](http://www.eskimo.com/~scs/C-faq/q10.4.html). 

## How to use ? ##
Just `#include "cut.h"` in you project, and then you can write you `TC`s(test case) and `TS`s(test suite).

## Example ##
```
#include <stdio.h>
#include <string.h>
// include cut
#include "cut.h"

// your function add to be tested
int add(int a, int b)
{
    return a + b;
}

// create a test case named `add_001`
CUT_CASE(add_001)
{
    int rel = add(3, 4);
    CUT_EXPECT_INT_EQ(7, rel);
}

// create another test case named `add_002`
// a wrong test case on purpose
CUT_CASE(add_002)
{
    int rel = add(4, 5);
    CUT_EXPECT_INT_EQ(8, rel);
}

// create a test suite named `suite_001`
CUT_SUITE(suite_001)
{
    // add a test case
    CUT_SUITE_ADD_TC(add_001);
    CUT_SUITE_ADD_TC(add_002);
}

int main()
{
    // excute a test suite
    CUT_RUN_SUITE(suite_001);
    
    // show test report
    CUT_REPORT();
    
    return 0;
}

```
