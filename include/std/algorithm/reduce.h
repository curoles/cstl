/**@file
 * @brief Reduce.
 * @author Igor Lesik 2023
 *
 */
#include "std/glue_macro.h"

#ifndef std_algorithm_reduce
#define std_algorithm_reduce(t_) GLUE2(std_algorithm_reduce_, t_)
#endif

static inline
T std_algorithm_reduce(T)(
    std_iterator(T) begin,
    std_iterator(T) end,
    T (*BinaryOp)(T*,T*)
)
{
    T val = *begin.ptr;
    begin.next(&begin);
    while (begin.ptr != end.ptr) {
        val = BinaryOp(&val, begin.ptr);
        begin.next(&begin);
    }
    return val;
}
