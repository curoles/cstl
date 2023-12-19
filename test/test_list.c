#include "std/clib_allocator.h"

#include <stdio.h>

#define T int
#include "std/iterator.h"
#include "std/list.h"
#undef T

#define T float
#include "std/iterator.h"
#include "std/list.h"
#undef T

static std_clib_allocator allocator = STD_CLIB_ALLOCATOR_INIT;

static void test_push_front(void)
{
    std_list(int) list = {.head = nullptr, .allocator = (std_allocator*)&allocator};

    assert(std_list_fn(int,size)(&list) == 0);

    for (unsigned int i = 0; i < 10; i++)
    {
        std_list_fn(int,push_front)(&list, i);
        assert(std_list_fn(int,size)(&list) == (i + 1));
        //printf("%u: %d\n", i, *(std_list_fn(int,ref_at)(&list,0)));
        assert(*std_list_fn(int,ref_at)(&list, 0) == i);
    }

    std_list_fn(int,free)(&list);
    assert(std_list_fn(int,size)(&list) == 0);
}

#if 0
static void test_at(void)
{
    int data[10] = {0, 1, 2, 3};
    std_array(int) a = {.data=data, .capacity=10, .size=4};

    assert(a.capacity == 10);
    assert(std_array_int_at(&a, 3) == 3);

    assert(std_array_fn(int,at)(&a, 2) == 2);

    assert(*std_array_int_ref_at(&a, 1) == 1);
    *std_array_int_ref_at(&a, 1) = 11;
    assert(*std_array_int_ref_at(&a, 1) == 11);
}

static void test_fill(void)
{
    int data[100] = {};
    std_array(int) a = {.data=data, .capacity=100, .size=100};

    std_array_int_fill(&a, 123);
    assert(a.data[4] == 123);
    assert(std_array_int_at(&a, 20) == 123);
    std_array_for_all(it, &a) {
        assert(*it == 123);
    }

    std_array_int_fill(&a, 789);
    assert(a.data[3] == 789);
    assert(std_array_fn(int,at)(&a, 23) == 789);
    std_array_for_all(it, &a) {
        assert(*it == 789);
    }
}
#endif

int main(void)
{
    test_push_front();

    return 0;
}
