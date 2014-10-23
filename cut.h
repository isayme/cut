#ifndef _CUT_H
#define _CUT_H

static int cut_passed = 0;
static int cut_failed = 0;

#define CUT_PRINTF(fmt, ...)  do {                              \
    fprintf(stderr, fmt, ##__VA_ARGS__);                        \
} while (0)

#define CUT_CASE(func) static char *func()
#define CUT_SUITE(func) static void func(char *_cut_rel)

#define CUT_SUITE_ADD_TC(tc) do {                               \
    _cut_rel = tc();                                            \
    if (NULL == _cut_rel) {                                     \
        cut_passed++;                                           \
        CUT_PRINTF("TC [%s] \033[32mpassed\033[0m\n", #tc);     \
    } else {                                                    \
        cut_failed++;                                           \
        CUT_PRINTF("TC [%s] \033[31mfailed, "                   \
                "%s\033[0m\n", #tc, _cut_rel);                  \
    }                                                           \
} while(0)

#define CUT_RUN_SUITE(ts) do {                                  \
    ts(NULL);                                                   \
} while(0)

#define CUT_RESET() do {                                        \
    cut_passed = 0;                                             \
    cut_failed = 0;                                             \
} while(0)

#define CUT_REPORT() do {                                       \
    CUT_PRINTF("\n #\n");                                       \
    CUT_PRINTF(" # Report: \033[36mTotal TC [%d]\033[0m, "      \
            "\033[32mPassed [%d]\033[0m, "                      \
            "\033[31mFailed [%d]\033[0m.\n",                    \
            cut_passed + cut_failed, cut_passed, cut_failed);   \
    CUT_PRINTF(" #\n\n");                                       \
} while(0)

#define CUT_EXPECT_STR_EQ(expect, real) do {                    \
    return 0 == strcmp(expect, real) ? NULL :                   \
                "expect [" #expect "]";                         \
} while(0);

#define CUT_EXPECT_PTR_NULL(real) do {                          \
    return NULL == real ? NULL : "expect NULL pointer";         \
} while(0);

#define CUT_EXPECT_INT_EQ(expect, real) do {                    \
    return expect == real ? NULL : "expect [" #expect "]";      \
} while(0);

#endif
