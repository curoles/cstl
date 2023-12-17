
#define T int
#include "std/iterator.h"
#include "std/array.h"
#undef T

#define T float
#include "std/iterator.h"
#include "std/array.h"
#undef T

void test_at(void)
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

void test_push_back(void)
{
    int data[10] = {0, 1, 2, 3};
    std_array(int) a = {.data=data, .capacity=10, .size=4};

    assert(a.size == 4);
    std_array_fn(int,push_back)(&a, 44);
    assert(a.size == 5);
    assert(std_array_int_at(&a, 4) == 44);

    assert(*std_array_int_front(&a) == 0);
    assert(*std_array_int_back(&a) == 44);
}

void test_fill(void)
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

int main(void)
{
    test_at();
    test_push_back();
    test_fill();

    return 0;
}
