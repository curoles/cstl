/**@file
 * @brief LA vector operations.
 * @author Igor Lesik 2023
 *
 */

static inline GNU_ATTR_ARG_NONNULL(1)
void std_array_fn(T,la_vec_scale)(std_array(T)* a, T factor) {
    std_array_for_all_index(i, a) {
        a->data[i] *= factor;
    }
}

static inline
void std_array_fn(T,la_vec_add)(std_array(T)* a, std_array(T)* b) {
    T* ad = a->data;
    T* bd = b->data;
    std_array_for_all_index(i, a) {
        ad[i] += bd[i];
    }
}
