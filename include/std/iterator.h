/**@file
 * @brief Iterator.
 * @author Igor Lesik 2023
 *
 */
#include "std/glue_macro.h"

#ifndef std_ierator
#define std_iterator(t_) GLUE2(std_iterator_, t_)
#endif

typedef struct std_iterator(T) std_iterator(T);

/** Iterator.
 *
 */
struct std_iterator(T)
{
    T* ptr;
    T* (*next)(std_iterator(T)*);

};

