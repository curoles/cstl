#pragma once

#define UNUSED __attribute__((unused))

#define GNU_ATTR_PURE_FN __attribute__((pure))
#define GNU_ATTR_CONST_FN __attribute__((const))

#define GNU_ATTR_ALWAYS_INLINE __attribute__((always_inline))

#define GNU_ATTR_NODISCARD __attribute__((warn_unused_result))
#define GNU_ATTR_RETURNS_NONNULL __attribute__ ((returns_nonnull))

#define GNU_ATTR_ARG_NONNULL(pos_) __attribute__((nonnull(pos_)))
