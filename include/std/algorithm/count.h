/**@file
 * @brief Count elements in a container.
 * @author Igor Lesik 2023
 *
 */
#include "std/glue_macro.h"

#ifndef std_algorithm_count
#define std_algorithm_count(t_) GLUE2(std_algorithm_count_, t_)
#endif

static inline
size_t std_algorithm_count(T)(std_iterator(T) begin, std_iterator(T) end)
{
    size_t count = 0;
    while (begin.ptr != end.ptr) {
        count++;
        begin.next(&begin);
    }
    return count;
}
