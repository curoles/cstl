
#define T int
#include "std/iterator.h"
#include "std/array.h"
#include "std/algorithm/fill.h"
#include "std/algorithm/reduce.h"

static int data[100] = {};
static std_array(int) a = {.data=data, .capacity=100, .size=50};

static inline GNU_ATTR_CONST_FN GNU_ATTR_ALWAYS_INLINE
int int_add(int* a, int* b) {
    return *a + *b;
}

static void test_add_reduce_array(void)
{
    std_algorithm_fill(int)(
        std_array_fn(int,begin)(&a),
        std_array_fn(int,end)(&a),
        123);

    std_array_for_all(it, &a) {
        assert(*it == 123);
    }

    int ra = std_algorithm_reduce(int)(
        std_array_fn(int,begin)(&a),
        std_array_fn(int,end)(&a),
        0,
        int_add);

    assert(ra == (123 * a.size));
}

int main(void)
{
    test_add_reduce_array();

    return 0;
}
