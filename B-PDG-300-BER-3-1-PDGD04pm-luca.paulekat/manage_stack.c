/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/
#include "include/stack.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void stack_clear(stack_t *stack_ptr)
{
    return list_clear(stack_ptr);
}

bool stack_pop(stack_t *stack_ptr)
{
    return list_del_elem_at_back(stack_ptr);
}

bool stack_push(stack_t *stack_ptr, void *elem)
{
    return list_add_elem_at_back(stack_ptr, elem);
}

void *stack_top(stack_t stack)
{
    return list_get_elem_at_back(stack);
}
