/*
** EPITECH PROJECT, 2020
** projet
** File description:
** projet
*/

#include "object.h"
#include "int.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    /* Fill this function for exercice 02 */
    this->x = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    /* Fill this function for exercice 02 */    
}

// Create additional functions here

static Object *sub(const Object *this, const Object *other)
{
    Object *new_pt = new(Int,
        ((IntClass *)this)->x - ((IntClass *)other)->x);

    return new_pt;
}

static Object *add(const Object *this, const Object *other)
{
    Object *new_pt = new(Int,
        ((IntClass *)this)->x + ((IntClass *)other)->x);

    return new_pt;
}

static Object *mul(const Object *this, const Object *other)
{
    Object *new_pt = new(Int,
        ((IntClass *)this)->x * ((IntClass *)other)->x);

    return new_pt;
}

static Object *div_f(const Object *this, const Object *other)
{
    if (((IntClass *)other)->x == 0)
        raise("division by zero");
    Object *new_pt = new(Int,
        ((IntClass *)this)->x / ((IntClass *)other)->x);
    return new_pt;
}

static bool eq_f(const Object *this, const Object *other)
{
    return ((IntClass *)this)->x == ((IntClass *)other)->x;
}

static bool gt_f(const Object *this, const Object *other)
{
    return ((IntClass *)this)->x > ((IntClass *)other)->x;
}

static bool lt_f(const Object *this, const Object *other)
{
    return ((IntClass *)this)->x < ((IntClass *)other)->x;
}

char *itos(int nb)
{
    long modulo = 10000000000;
    long divider = 1000000000;
    int current_num = 0;
    char *num = malloc(sizeof(char) * 12);
    int i = 0;

    if (nb < 0) num[i++] = '-';
    for (short started = 0; divider && modulo && nb; modulo /= 10) {
        current_num = nb % modulo / divider;
        current_num = current_num < 0 ? -current_num : current_num;
        if (current_num > 0 || nb == 0 || started) {
            started = 1;
            num[i++] = current_num + 48;
        }
        divider /= 10;
    }
    if (nb == 0)
        num[i++] = '0';
    num[i] = '\0';
    return num;
}

static char *get_str(Object *this)
{
    char *buffer = malloc(sizeof(char) * 100);
    int x = ((IntClass *)this)->x;
    int i = 0;
    char *new_str;

    sprintf(buffer, "<Int (%d)>", x);
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

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
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

const Class   *Int = (const Class *)&_description;