/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 01
*/

#include <stdarg.h>
#include "new.h"

Object  *new(const Class *class, ...)
{
    Object *new_obj;
    va_list list;

    va_start(list, class);
    new_obj = va_new(class, &list);
    va_end(list);
    return new_obj;
}

Object  *va_new(const Class *class, va_list* ap)
{
    Object *new_obj = malloc(class->__size__);

    memcpy(new_obj, class, class->__size__);
    if (((Class *)new_obj)->__ctor__ == NULL)
        return new_obj;
    ((Class *)new_obj)->__ctor__(new_obj, ap);
    return new_obj;
}

void delete(Object *ptr)
{
    Class *class = ptr;

    if (class == NULL)
        return;
    if (ptr == NULL)
        return;
    if (class->__dtor__ != NULL)
        class->__dtor__(ptr);
    free(ptr);
}