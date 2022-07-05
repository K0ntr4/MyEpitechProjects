/*
** EPITECH PROJECT, 2021
** my_include_macro_abs
** File description:
** replaces a parameter with an absolute value
*/

#ifndef my_macro_abs_h_
    #define my_macro_abs_h_
    #define ABS(value) (((value) < 0) ? ((value) * (-1)) : (value))
#endif
