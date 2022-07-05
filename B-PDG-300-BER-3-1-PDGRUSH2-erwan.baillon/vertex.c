/*
** EPITECH PROJECT, 2022
** B-PDG-300-BER-3-1-PDGRUSH2-erwan.baillon
** File description:
** vertex
*/

#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class   base;
    int x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static char *get_vertex_str(VertexClass *this)
{
    char *str;

    if (!(str = malloc(sizeof(char) * 100)))
        raise("Error malloc");
    snprintf(str, 100, "<%s (%d, %d, %d)>", this->base.__name__, 
    this->x, this->y, this->z);
    return str;
}

static void Vertex_dtor(VertexClass *this)
{

}

static Object *sub(const Object *this, const Object *other)
{
    Object *new_pt = new(Vertex,
        ((VertexClass *)this)->x - ((VertexClass *)other)->x,
        ((VertexClass *)this)->y - ((VertexClass *)other)->y,
        ((VertexClass *)this)->z - ((VertexClass *)other)->z);

    return new_pt;
}

static Object *add(const Object *this, const Object *other)
{
    Object *new_pt = new(Vertex,
        ((VertexClass *)this)->x + ((VertexClass *)other)->x,
        ((VertexClass *)this)->y + ((VertexClass *)other)->y,
        ((VertexClass *)this)->z + ((VertexClass *)other)->z);

    return new_pt;
}

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&get_vertex_str,    /* Implement this method for exercice 02 */
        .__add__ = &add,    /* Implement this method for exercice 03 */
        .__sub__ = &sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class   *Vertex = (const Class *)&_description;