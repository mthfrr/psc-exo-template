#include <criterion/criterion.h>

#define EQ_INT(x, y)                                                           \
    {                                                                          \
        int a = x;                                                             \
        int b = y;                                                             \
        cr_assert_eq(a, b, "%d != %d", a, b);                                  \
    }

#define EQ_FLOAT(x, y)                                                         \
    {                                                                          \
        double a = x;                                                          \
        double b = y;                                                          \
        cr_assert_float_eq(a, b, 0.000001, "%f != %f", a, b);                  \
    }

#define EQ_STR(x, y)                                                           \
    {                                                                          \
        char *a = x;                                                           \
        char *b = y;                                                           \
        cr_assert_str_eq(a, b, "%s != %s", a, b);                              \
    }

#define EQ_INT_ARR(x, y, len)                                                  \
    {                                                                          \
        int *a = x;                                                            \
        int *b = y;                                                            \
        char a_str[256];                                                       \
        char *ap = a_str;                                                      \
        char b_str[256];                                                       \
        char *bp = b_str;                                                      \
        for (unsigned long i = 0; i < len; i++)                                \
        {                                                                      \
            ap += sprintf(ap, "%d, ", a[i]);                                   \
            bp += sprintf(bp, "%d, ", b[i]);                                   \
        }                                                                      \
        for (unsigned long i = 0; i < len; i++)                                \
        {                                                                      \
            cr_assert_eq(a[i], b[i], "%s != %s", a_str, b_str);                \
        }                                                                      \
    }

#define EQ_PTR(x, y)                                                           \
    {                                                                          \
        int *a = x;                                                            \
        int *b = y;                                                            \
        cr_assert_eq(a, b, "%p != %p", (void *)a, (void *)b);                  \
    }
