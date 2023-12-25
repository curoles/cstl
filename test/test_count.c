
#define T int
#include "std/iterator.h"
#include "std/array.h"
#include "std/algorithm/count.h"

static int data[100] = {};
static std_array(int) a = {.data=data, .capacity=100, .size=50};

static void test_count_array(void)
{
    size_t count = std_algorithm_count(int)(
        std_array_fn(int,begin)(&a),
        std_array_fn(int,end)(&a));

    assert(count == a.size);
}

int main(void)
{
    test_count_array();

    return 0;
}
