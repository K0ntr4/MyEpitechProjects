/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/
#include "include/stack.h"
#include <stddef.h>
#include <stdio.h>

unsigned int stack_get_size(stack_t stack)
{
    return list_get_size(stack);
}

bool stack_is_empty(stack_t stack)
{
    return list_is_empty(stack);
}
