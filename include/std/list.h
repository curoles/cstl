/**@file
 * @brief Double linked List container.
 * @author Igor Lesik 2023
 *
 */
#include <assert.h>
#include "std/defines.h"
#include "std/gnu_attributes.h"
#include "std/glue_macro.h"

#ifndef std_list
#define std_list(t_) GLUE2(std_list_, t_)
#endif
#ifndef std_list_node
#define std_list_node(t_) GLUE2(std_list_node_, t_)
#endif
#ifndef std_list_fn
#define std_list_fn(t_, fn_) GLUE4(std_list_, t_, _, fn_)
#endif

typedef struct std_list_node(T) std_list_node(T);

struct std_list_node(T)
{
    std_list_node(T)* next;
    std_list_node(T)* prev;
    T val;
};

/** Double linked list container.
 *
 */
typedef struct std_list(T)
{
    std_list_node(T)* head;

} std_list(T);

static inline GNU_ATTR_ARG_NONNULL(1)
std_list(T)* std_list_fn(T,push_back)(std_list(T)* a, T val) {
    return a;
}

#if 0
static inline GNU_ATTR_NODISCARD GNU_ATTR_ARG_NONNULL(1)
T std_array_fn(T,at)(std_array(T) const* a, size_t pos) {
    assert(pos < a->size && a->size <= a->capacity);
    return a->data[pos];
}

static inline GNU_ATTR_NODISCARD GNU_ATTR_ARG_NONNULL(1)
T* std_array_fn(T,ref_at)(std_array(T) * a, size_t pos) {
    assert(pos < a->size && a->size <= a->capacity);
    return &a->data[pos];
}

static inline GNU_ATTR_NODISCARD GNU_ATTR_ARG_NONNULL(1)
T const* std_array_fn(T,const_ref_at)(std_array(T) const* a, size_t pos) {
    assert(pos < a->size && a->size <= a->capacity);
    return &a->data[pos];
}

static inline GNU_ATTR_ARG_NONNULL(1)
std_array(T)* std_array_fn(T,push_back)(std_array(T)* a, T val) {
    if (a->size == a->capacity) {
        return nullptr;
    }
    a->data[a->size] = val;
    a->size++;
    return a;
}

static inline GNU_ATTR_NODISCARD GNU_ATTR_ARG_NONNULL(1)
T* std_array_fn(T,front)(std_array(T)* a) {
    return &a->data[0];
}

static inline GNU_ATTR_NODISCARD GNU_ATTR_ARG_NONNULL(1)
T* std_array_fn(T,back)(std_array(T)* a) {
    assert(a->size > 0);
    return &a->data[a->size - 1];
}

static inline GNU_ATTR_NODISCARD GNU_ATTR_ARG_NONNULL(1)
bool std_array_fn(T,empty)(std_array(T)* a) {
    return a->size == 0;
}

static inline GNU_ATTR_NODISCARD GNU_ATTR_ARG_NONNULL(1)
size_t std_array_fn(T,size)(std_array(T)* a) {
    return a->size;
}

#define std_array_for_each(p_, begin_, end_) \
    for (typeof(begin_) p_ = begin_; p_ != end_; p_++)

#define std_array_for_all(p_, a_) \
    std_array_for_each(p_, &(a_)->data[0], &(a_)->data[(a_)->size])

static inline GNU_ATTR_ARG_NONNULL(1)
void std_array_fn(T,fill)(std_array(T)* a, T val) {
    std_array_for_all(it, a) {
        *it = val;
    }
}

static inline GNU_ATTR_ARG_NONNULL(1)
T* std_array_fn(T,iterator_next)(std_iterator(T)* it) {
    it->ptr++;
    return it->ptr;
}

static inline GNU_ATTR_ARG_NONNULL(1)
std_iterator(T) std_array_fn(T,begin)(std_array(T)* a) {
    return (std_iterator(T)) {
        .ptr = &a->data[0],
        .next = std_array_fn(T,iterator_next)
    };
}

static inline GNU_ATTR_ARG_NONNULL(1)
std_iterator(T) std_array_fn(T,end)(std_array(T)* a) {
    return (std_iterator(T)) {
        .ptr = &a->data[a->size],
        .next = std_array_fn(T,iterator_next)
    };
}
#endif
