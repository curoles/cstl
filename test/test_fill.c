#include "std/container.h"

#define T int
#include "std/iterator.h"
#include "std/array.h"
#include "std/algorithm/fill.h"

int data[100] = {};
std_array(int) a = {.data=data, .capacity=100, .size=50};

void test_fill_array(void)
{
    std_algorithm_fill(int)(
        std_array_fn(int,begin)(&a),
        std_array_fn(int,end)(&a),
        123);

    std_array_for_all(it, &a) {
        assert(*it == 123);
    }


    std_algorithm_fill(int)(
        std_container_begin(int,&a),
        std_container_end(int,&a),
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
