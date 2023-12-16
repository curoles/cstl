/**@file
 * @brief Fill container.
 * @author Igor Lesik 2023
 *
 */
#include "std/glue_macro.h"

#ifndef std_algorithm_fill
#define std_algorithm_fill(t_) GLUE2(std_algorithm_fill_, t_)
#endif

static inline
void std_algorithm_fill(T)(std_iterator(T) begin, std_iterator(T) end, T val)
{
    while (begin.ptr != end.ptr) {
        *begin.ptr = val;
        begin.next(&begin);
    }
}
