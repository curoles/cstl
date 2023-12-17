/**@file
 * @brief     Common CSTL definitions..
 * @author    Igor Lesik 2023
 * @copyright Igor Lesik 2023
 *
 */
#pragma once

#define STDC17 201710L

//#if __STDC_VERSION__ <= STDC17
//    #pragma error "C23 is required!"
//#endif

#include <stddef.h>
#if __STDC_VERSION__ <= STDC17
#include <stdbool.h>
#endif

#if __STDC_VERSION__ <= STDC17
#define nullptr NULL
#endif
