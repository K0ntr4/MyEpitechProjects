/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 05
*/

#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "list.h"
#include "new.h"

typedef struct ListClass_s
{
    Container   base;
    Class       *_type;
    size_t      _size;
    struct ListClass_s *_next;
    struct ListClass_s *_prev;
    Object *_value;
}   ListClass_t;

typedef struct {
    Iterator    base;
    ListClass_t  *_List;
    int      _idx;
}   ListIteratorClass;

static void     ListIterator_ctor(ListIteratorClass *this, va_list *args)
{
    this->_List = va_arg(*args, ListClass_t *);
    this->_idx = va_arg(*args, int);
}

static bool     ListIterator_eq(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx == other->_idx);
}

static bool     ListIterator_gt(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx > other->_idx);
}

static bool     ListIterator_lt(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx < other->_idx);
}

static void     ListIterator_incr(ListIteratorClass *this)
{
    this->_idx += 1;
}

static Object   *ListIterator_getval(ListIteratorClass *this)
{
    if (this->_idx >= this->_List->_size)
        raise("Out of range");
    return (this->_List->_value);
}

static void     ListIterator_setval(ListIteratorClass *this, ...)
{
    /* Fill this function for exercice 05 */
    va_list args;

    if (this->_idx > this->_List->_size)
        raise("index out of bounds");
    va_start(args, this);
    delete(this->_List->_value);
    this->_List->_value = va_new(this->_List->_type, &args);
    va_end(args);
}

static const ListIteratorClass   ListIteratorDescr = {
    {   /* Iterator struct */
        {   /* Class struct */
            .__size__ = sizeof(ListIteratorClass),
            .__name__ = "ListIterator",
            .__ctor__ = (ctor_t)&ListIterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&ListIterator_eq,
            .__gt__ = (binary_comparator_t)&ListIterator_gt,
            .__lt__ = (binary_comparator_t)&ListIterator_lt,
        },
        .__incr__ = (incr_t)&ListIterator_incr,
        .__getval__ = (getval_t)&ListIterator_getval,
        .__setval__ = (setval_t)&ListIterator_setval,
    },
    ._List = NULL,
    ._idx = 0
};

static const Class    *ListIterator = (const Class *)&ListIteratorDescr;

static void     List_ctor(ListClass_t *this, va_list *args)
{
    /* Fill this function for exercice 05 */
    va_list cpy;
    ListClass_t **start = &this;
    ListClass_t *cpy_this = this;

    this->_size = va_arg(*args, size_t);
    this->_type = va_arg(*args, Class*);
    if (!(this->_value = malloc(sizeof(Object *))))
        raise("Error malloc");
    for (size_t i = 0; i < this->_size; i++) {
        va_copy(cpy, *args);
        this->_next = va_new(this->_type, &cpy);
    }
    this = *start;
    while (this->_next) {
        cpy_this = this;
        this = this->_next;
        this->_prev = cpy_this;
    }
}

static void     List_dtor(ListClass_t *this)
{
    ListClass_t *cpy = this;

    if (this == NULL)
        return;
    cpy = this;
    List_dtor (this = this->_next);
    free(cpy->_value);
    free(cpy);
}

static size_t   List_len(ListClass_t *this)
{
    return (this->_size);
}

static Iterator *List_begin(ListClass_t *this)
{
    while (this->_prev != NULL)
        this = this->_prev;
    return (new(ListIterator, this, 0));
}

static Iterator *List_end(ListClass_t *this)
{
    while (this->_next) {
        this = this->_next;
    }
    return (new(ListIterator, this, this->_size));
}

static Object   *List_getitem(ListClass_t *this, ...)
{
    /* Fill this function for exercice 05 */
    va_list args;
    size_t index;

    va_start(args, this);
    index = va_arg(args, size_t);
    va_end(args);
    if (index > this->_size)
        raise("index out of bounds");
    return this->_tab[index];
}

static void     List_setitem(ListClass *this, ...)
{
    /* Fill this function for exercice 05 */
    va_list args;
    size_t pos;

    va_start(args, this);
    pos = va_arg(args, size_t);
    if (pos > this->_size)
        raise("index out of bounds");
    delete(this->_tab[pos]);
    this->_tab[pos] = va_new(this->_type, &args);
    va_end(args);
}

static const ListClass   _descr = {
    {   /* Container struct */
        {   /* Class struct */
            .__size__ = sizeof(ListClass),
            .__name__ = "List",
            .__ctor__ = (ctor_t)&List_ctor,
            .__dtor__ = (dtor_t)&List_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&List_len,
        .__begin__ = (iter_t)&List_begin,
        .__end__ = (iter_t)&List_end,
        .__getitem__ = (getitem_t)&List_getitem,
        .__setitem__ = (setitem_t)&List_setitem,
    },
    ._type = NULL,
    ._size = 0,
    ._tab = NULL
};

const Class   *List = (const Class *)&_descr;
