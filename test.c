#include <criterion/criterion.h>

#define eq_int(x, y)\
{\
    int a = x;\
    int b = y;\
    cr_assert_eq(a, b, "%d != %d", a, b);\
}

#define eq_float(x, y)\
{\
    double a = x;\
    double b = y;\
    cr_assert_float_eq(a, b, 0.000001, "%f != %f", a, b);\
}

#define eq_str(x, y)\
{\
    char *a = x;\
    char *b = y;\
    cr_assert_str_eq(a, b, "%s != %s", a, b);\
}

#define eq_ptr(x, y)\
{\
    int *a = x;\
    int *b = y;\
    cr_assert_eq(a, b, "%p != %p", (void*)a, (void*)b);\
}

