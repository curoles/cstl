/**@file
 * @brief Macro to glue parts.
 * @author Igor Lesik 2023
 *
 */
#pragma once

#define GLUE2(x_, y_) x_##y_
#define GLUE3(x_, y_, z_) x_##y_##z_
#define GLUE4(x_, y_, z_, w_) x_##y_##z_##w_
