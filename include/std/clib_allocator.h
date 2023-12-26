/**@file
 * @brief Allocator using malloc.
 * @author Igor Lesik 2023
 *
 */
#pragma once

#include <stdlib.h>
#include "std/defines.h"
#include "std/allocator.h"


#define STD_CLIB_ALLOCATOR_INIT { \
    .method.allocate = std_clib_allocate, \
    .method.reallocate = std_clib_reallocate, \
    .method.free = std_clib_free \
}

typedef struct std_clib_allocator {
    std_allocator method;
} std_clib_allocator;

static inline GNU_ATTR_NODISCARD
void* std_clib_allocate(size_t count, size_t value_size)
{
    return malloc(count * value_size);
}

static inline GNU_ATTR_NODISCARD
void* std_clib_reallocate(void* mem, size_t new_count, size_t value_size)
{
    return realloc(mem, new_count * value_size);
}

static inline
void std_clib_free(void* mem)
{
    free(mem);
}

static inline
void std_clib_allocator_init(std_clib_allocator* allocator)
{
    allocator->method.allocate = std_clib_allocate;
    allocator->method.reallocate = std_clib_reallocate;
    allocator->method.free = std_clib_free;
}

//FIXME TODO
typedef struct std_clib_aligned_allocator {
    std_allocator method;
} std_clib_aligned_allocator;

static inline GNU_ATTR_NODISCARD
void* std_clib_aligned_allocate(size_t count, size_t value_size)
{
    return aligned_alloc(128, count * value_size);
}
