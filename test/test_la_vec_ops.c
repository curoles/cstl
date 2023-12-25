
#define T int
#include "std/iterator.h"
#include "std/array.h"
#include "std/la/vector_op.h"
#undef T

#define T float
#include "std/iterator.h"
#include "std/array.h"
#include "std/la/vector_op.h"
#undef T

static void test_la_vec_scale(void)
{
    int data[4] = {0, 1, 2, 3};
    std_array(int) a = {.data=data, .capacity=4, .size=4};

    std_array_fn(int,la_vec_scale)(&a, 2);

    std_array_for_all_index(i, &a) {
        assert(std_array_fn(int,at)(&a, i) == (i * 2));
        assert(a.data[i] == (i * 2));
    }
}

static void test_la_vec_add(void)
{
    int data1[4] = {0, 1, 2, 3};
    std_array(int) a = {.data=data1, .capacity=4, .size=4};

    int data2[4] = {0, 1, 2, 3};
    std_array(int) b = {.data=data2, .capacity=4, .size=4};

    std_array_fn(int,la_vec_add)(&a, &b);

    std_array_for_all_index(i, &a) {
        assert(std_array_fn(int,at)(&a, i) == (i * 2));
        assert(a.data[i] == (i * 2));
    }
}

int main(void)
{
    test_la_vec_scale();
    test_la_vec_add();

    return 0;
}
