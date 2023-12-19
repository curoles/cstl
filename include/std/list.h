/**@file
 * @brief Double linked List container.
 * @author Igor Lesik 2023
 *
 */
#include <assert.h>
#include "std/defines.h"
#include "std/gnu_attributes.h"
#include "std/glue_macro.h"
#include "std/allocator.h"

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
    std_allocator* allocator;

} std_list(T);

static inline GNU_ATTR_ARG_NONNULL(1)
std_list_node(T)* std_list_fn(T,front)(std_list(T)* l) {
    return l->head;
}

static inline GNU_ATTR_ARG_NONNULL(1)
std_list_node(T)* std_list_fn(T,back)(std_list(T)* l) {
    std_list_node(T)* node = l->head;
    while (node != nullptr && node->next != nullptr) {
        node = node->next;
    }
    return node;
}

static inline GNU_ATTR_ARG_NONNULL(1)
size_t std_list_fn(T,empty)(std_list(T)* l) {
    return l->head == nullptr;
}

static inline GNU_ATTR_ARG_NONNULL(1)
size_t std_list_fn(T,size)(std_list(T)* l) {
    size_t size = 0;
    for (std_list_node(T)* node = l->head; node != nullptr ; node = node->next) {
        size++;
    }
    return size;
}

static inline GNU_ATTR_NODISCARD GNU_ATTR_ARG_NONNULL(1)
T* std_list_fn(T,ref_at)(std_list(T)* l, size_t pos) {
    size_t current_pos = 0;
    for (std_list_node(T)* node = l->head; node != nullptr; node = node->next) {
        if (current_pos == pos) {
            return &node->val;
        }
        current_pos++;
    }
    return nullptr;
}

static inline GNU_ATTR_ARG_NONNULL(1)
void std_list_fn(T,clear)(std_list(T)* l) {
    for (std_list_node(T)* node = l->head; node != nullptr; ) {
        if (node->next) {
            node->next->prev = nullptr;
        }
        std_list_node(T)* node_to_remove = node;
        node = node->next;
        l->head = node;
        l->allocator->free(node_to_remove);
    }
}

static inline GNU_ATTR_ARG_NONNULL(1)
std_list(T)* std_list_fn(T,push_front)(std_list(T)* l, T val) {
    std_list_node(T)* new_node = l->allocator->allocate(1, sizeof(std_list_node(T)));
    assert(new_node != nullptr);
    new_node->val = val;
    std_list_node(T)* old_head = l->head;
    assert(old_head == nullptr || old_head->prev == nullptr);
    l->head = new_node;
    new_node->prev = nullptr;
    new_node->next = old_head;
    if (old_head) old_head->prev = new_node;
    return l;
}

#if 0
static inline GNU_ATTR_ARG_NONNULL(1)
std_list(T)* std_list_fn(T,push_back)(std_list(T)* l, T val) {
    std_list_node(T)* new_node = l->allocator.allocate(1, sizeof(std_list_node(T)));
    new_node->val = val;
    std_list_node(T)* tail = std_list_fn(T,back)(l);
    assert(tail->next == nullptr);
    tail->next = new_node;
    new_node->prev = tail;
    new_node->next = nullptr;
}
#endif

#if 0
static inline GNU_ATTR_NODISCARD GNU_ATTR_ARG_NONNULL(1)
T std_array_fn(T,at)(std_array(T) const* a, size_t pos) {
    assert(pos < a->size && a->size <= a->capacity);
    return a->data[pos];
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
