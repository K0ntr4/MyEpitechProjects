/*
** EPITECH PROJECT, 2025
** project
** File description:
** desc
*/
#include "string.h"

static void assign_s(string_t *this, const string_t *str)
{
    free (this->str);
    this->str = my_strdup((char *)str->str);
}

static void assign_c(string_t *this, const char *s)
{
    if (this->str != NULL)
        free(this->str);
    this->str = my_strdup((char *)s);
}

void assign_more_functions(string_t *this, const char *s)
{
    this->split_c = &split_c;
    this->split_s = &split_s;
    this->print = &print;
    this->join_c = &join_c;
    this->join_s = &join_s;
}

void string_init(string_t *this, const char *s)
{
    this->str = my_strdup((char *)s);
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->at = &get_string_at;
    this->clear = &clear;
    this->length = &length;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    this->find_s = &find_s;
    this->find_c = &find_c;
    this->insert_c = &insert_c;
    this->insert_s = &insert_s;
    this->to_int = &to_int;
    assign_more_functions(this, s);
}

string_t *string_create(char *s)
{
    string_t * str = malloc(sizeof(string_t));
    string_init(str, s);
    return str;
}
