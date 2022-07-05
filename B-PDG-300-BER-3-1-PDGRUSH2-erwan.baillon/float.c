/*
** EPITECH PROJECT, 2020
** projet
** File description:
** projet
*/

#include <stdio.h>
#include "object.h"
#include "float.h"
#include "new.h"

typedef struct
{
    Class   base;
    double     x;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    /* Fill this function for exercice 02 */
    this->x = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    /* Fill this function for exercice 02 */    
}

// Create additional functions here

static Object *sub(const Object *this, const Object *other)
{
    Object *new_pt = new(Float,
        ((FloatClass *)this)->x - ((FloatClass *)other)->x);

    return new_pt;
}

static Object *add(const Object *this, const Object *other)
{
    Object *new_pt = new(Float,
        ((FloatClass *)this)->x + ((FloatClass *)other)->x);

    return new_pt;
}

static Object *mul(const Object *this, const Object *other)
{
    Object *new_pt = new(Float,
        ((FloatClass *)this)->x * ((FloatClass *)other)->x);

    return new_pt;
}

static Object *div_f(const Object *this, const Object *other)
{
    if (((FloatClass *)other)->x == 0)
        raise("division by zero");
    Object *new_pt = new(Float,
        ((FloatClass *)this)->x / ((FloatClass *)other)->x);
    return new_pt;
}

static bool eq_f(const Object *this, const Object *other)
{
    return ((FloatClass *)this)->x == ((FloatClass *)other)->x;
}

static bool gt_f(const Object *this, const Object *other)
{
    return ((FloatClass *)this)->x > ((FloatClass *)other)->x;
}

static bool lt_f(const Object *this, const Object *other)
{
    return ((FloatClass *)this)->x < ((FloatClass *)other)->x;
}

static char *get_str(Object *this)
{
    char *buffer = malloc(sizeof(char) * 100);
    float x = ((FloatClass *)this)->x;
    int i = 0;
    char *new_str;

    sprintf(buffer, "<Float (%g)>", x);
    while (buffer[i] != '\0')
        i++;
    if (!(new_str = malloc(sizeof(char) * (i + 1))))
        raise("memory allocation");
    i = 0;
    while (buffer[i] != '\0') {
        new_str[i] = buffer[i];
        i++;
    }
    new_str[i] = '\0';
    free(buffer);
    return (new_str);
}

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = &get_str,    /* Implement this method for exercice 02 */
        .__add__ = &add,    /* Implement this method for exercice 03 */
        .__sub__ = &sub,    /* Implement this method for exercice 03 */
        .__mul__ = &mul,
        .__div__ = &div_f,
        .__eq__ = &eq_f,
        .__gt__ = &gt_f,
        .__lt__ = &lt_f
    },
    .x = 0
};

const Class   *Float = (const Class *)&_description;