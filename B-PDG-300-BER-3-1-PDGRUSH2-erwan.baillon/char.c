/*
** EPITECH PROJECT, 2020
** projet
** File description:
** projet
*/

#include "object.h"
#include "char.h"
#include "new.h"

typedef struct
{
    Class   base;
    char     x;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    /* Fill this function for exercice 02 */
    this->x = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    /* Fill this function for exercice 02 */    
}

// Create additional functions here

static Object *sub(const Object *this, const Object *other)
{
    Object *new_pt = new(Char,
        ((CharClass *)this)->x - ((CharClass *)other)->x);

    return new_pt;
}

static Object *add(const Object *this, const Object *other)
{
    Object *new_pt = new(Char,
        ((CharClass *)this)->x + ((CharClass *)other)->x);

    return new_pt;
}

static Object *mul(const Object *this, const Object *other)
{
    Object *new_pt = new(Char,
        ((CharClass *)this)->x * ((CharClass *)other)->x);

    return new_pt;
}

static Object *div_f(const Object *this, const Object *other)
{
    if (((CharClass *)other)->x == 0)
        raise("division by zero");
    Object *new_pt = new(Char,
        ((CharClass *)this)->x / ((CharClass *)other)->x);
    return new_pt;
}

static bool eq_f(const Object *this, const Object *other)
{
    return ((CharClass *)this)->x == ((CharClass *)other)->x;
}

static bool gt_f(const Object *this, const Object *other)
{
    return ((CharClass *)this)->x > ((CharClass *)other)->x;
}

static bool lt_f(const Object *this, const Object *other)
{
    return ((CharClass *)this)->x < ((CharClass *)other)->x;
}

static char *get_str(Object *this)
{
    char *str = strdup("<Char (x)>");

    str[7] = ((CharClass *)this)->x;
    return (str);
}

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
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

const Class   *Char = (const Class *)&_description;