/**@file
 * @brief Generic container interface.
 * @author Igor Lesik 2023
 *
 */
#pragma once

/** Array base class.
 *
 * Empty struct used to identify child's container type.
 */
typedef struct std_array_base_class {} std_array_base_class;

#define std_container_at(T_, c_, pos_) _Generic(((c_.parent_class_obj)+0), \
    std_array_base_class*: std_array_##T_##_at, \
    std_array_base_class const*: std_array_##T_##_at \
)(c_, pos_)

#define std_container_ref_at(T_, c_, pos_) _Generic(((c_.parent_class_obj)+0), \
    std_array_base_class*: std_array_##T_##_ref_at, \
    std_array_base_class const*: std_array_##T_##_const_ref_at \
)(c_, pos_)

#define std_container_push_back(T_, c_, val_) _Generic(((c_.parent_class_obj)+0), \
    std_array_base_class*: std_array_##T_##_push_back \
)(c_, val_)

#define std_container_front(T_, c_) _Generic(((c_.parent_class_obj)+0), \
    std_array_base_class*: std_array_##T_##_front \
)(c_)

#define std_container_back(T_, c_) _Generic(((c_.parent_class_obj)+0), \
    std_array_base_class*: std_array_##T_##_back \
)(c_)

#define std_container_begin(T_, c_) _Generic(((c_.parent_class_obj)+0), \
    std_array_base_class*: std_array_##T_##_begin \
)(c_)

#define std_container_end(T_, c_) _Generic(((c_.parent_class_obj)+0), \
    std_array_base_class*: std_array_##T_##_end \
)(c_)
