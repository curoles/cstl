/**@file
 * @brief Allocator trait.
 * @author Igor Lesik 2023
 *
 */
#pragma once

#include "std/defines.h"
#include "std/gnu_attributes.h"

typedef struct std_allocator {
    void* (*allocate)(size_t count, size_t value_size) GNU_ATTR_NODISCARD;
    void* (*reallocate)(void* mem, size_t count, size_t value_size) GNU_ATTR_NODISCARD;
    void (*free)(void* mem);
} std_allocator;
