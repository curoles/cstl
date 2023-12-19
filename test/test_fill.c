
#define T int
#include "std/iterator.h"
#include "std/array.h"
#include "std/algorithm/fill.h"

static int data[100] = {};
static std_array(int) a = {.data=data, .capacity=100, .size=50};

static void test_fill_array(void)
{
    std_algorithm_fill(int)(
        std_array_fn(int,begin)(&a),
        std_array_fn(int,end)(&a),
        123);

    std_array_for_all(it, &a) {
        assert(*it == 123);
    }


    std_algorithm_fill(int)(
        std_array_fn(int,begin)(&a),
        std_array_fn(int,end)(&a),
        777);

    std_array_for_all(it, &a) {
        assert(*it == 777);
    }
}

int main(void)
{
    test_fill_array();

    return 0;
}
