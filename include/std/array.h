/**@file
 * @brief Array container.
 * @author Igor Lesik 2023
 *
 */
#include <stddef.h>
#include <assert.h>
#include <stdbool.h> // if !C23
#include "std/gnu_attributes.h"
#include "std/container.h"
#include "std/glue_macro.h"

#define std_array(t_) GLUE2(std_array_, t_)
#define std_array_fn(t_, fn_) GLUE4(std_array_, t_, _, fn_)

/** Array container non-resizable view.
 *
 */
typedef struct std_array(T)
{
    std_array_base_class parent_class_obj;

    size_t size;
    size_t capacity;
    T* data; //< raw data C array

} std_array(T);

static inline GNU_ATTR_NODISCARD
T std_array_fn(T,at)(std_array(T) const* a, size_t pos) {
    assert(pos < a->size && a->size <= a->capacity);
    return a->data[pos];
}

static inline GNU_ATTR_NODISCARD
T* std_array_fn(T,ref_at)(std_array(T) * a, size_t pos) {
    assert(pos < a->size && a->size <= a->capacity);
    return &a->data[pos];
}

static inline GNU_ATTR_NODISCARD
T const* std_array_fn(T,const_ref_at)(std_array(T) const* a, size_t pos) {
    assert(pos < a->size && a->size <= a->capacity);
    return &a->data[pos];
}

static inline
std_array(T)* std_array_fn(T,push_back)(std_array(T)* a, T val) {
    if (a->size == a->capacity) {
        return NULL;//nullptr;
    }
    a->data[a->size] = val;
    a->size++;
    return a;
}

static inline GNU_ATTR_NODISCARD
T* std_array_fn(T,front)(std_array(T)* a) {
    return &a->data[0];
}

static inline GNU_ATTR_NODISCARD
T* std_array_fn(T,back)(std_array(T)* a) {
    assert(a->size > 0);
    return &a->data[a->size - 1];
}

static inline GNU_ATTR_NODISCARD
bool std_array_fn(T,empty)(std_array(T)* a) {
    return a->size == 0;
}

static inline GNU_ATTR_NODISCARD
size_t std_array_fn(T,size)(std_array(T)* a) {
    return a->size;
}

#define std_array_for_each(p_, begin_, end_) \
    for (typeof(begin_) p_ = begin_; p_ != end_; p_++)

#define std_array_for_all(p_, a_) \
    std_array_for_each(p_, &(a_)->data[0], &(a_)->data[(a_)->size])

static inline
void std_array_fn(T,fill)(std_array(T)* a, T val) {
    std_array_for_all(it, a) {
        *it = val;
    }
}

static inline
T* std_array_fn(T,iterator_next)(std_iterator(T)* it) {
    it->ptr++;
    return it->ptr;
}

static inline
std_iterator(T) std_array_fn(T,begin)(std_array(T)* a) {
    return (std_iterator(T)) {
        .ptr = &a->data[0],
        .next = std_array_fn(T,iterator_next)
    };
}

static inline
std_iterator(T) std_array_fn(T,end)(std_array(T)* a) {
    return (std_iterator(T)) {
        .ptr = &a->data[a->size],
        .next = std_array_fn(T,iterator_next)
    };
}

