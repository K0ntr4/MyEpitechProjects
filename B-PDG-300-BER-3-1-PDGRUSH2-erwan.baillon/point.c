/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    /* Fill this function for exercice 02 */
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static char *get_point_str(PointClass *this)
{
    char *str;

    if (!(str = malloc(sizeof(char) * 100)))
        raise("Error malloc");
    snprintf(str, 100, "<%s (%d, %d)>", this->base.__name__, this->x, this->y);
    return str;
}

static void Point_dtor(PointClass *this)
{
    /* Fill this function for exercice 02 */    
}

// Create additional functions here

static Object *sub(const Object *this, const Object *other)
{
    Object *new_pt = new(Point,
        ((PointClass *)this)->x - ((PointClass *)other)->x,
        ((PointClass *)this)->y - ((PointClass *)other)->y);

    return new_pt;
}

static Object *add(const Object *this, const Object *other)
{
    Object *new_pt = new(Point,
        ((PointClass *)this)->x + ((PointClass *)other)->x,
        ((PointClass *)this)->y + ((PointClass *)other)->y);

    return new_pt;
}

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&get_point_str,    /* Implement this method for exercice 02 */
        .__add__ = &add,    /* Implement this method for exercice 03 */
        .__sub__ = &sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
