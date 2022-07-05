#include <string.h>
#include "malloc.h"

t_memory_list *list;

t_memory_list *get_last_elem (t_memory_list *l) {
    t_memory_list *tmp = l;
    while (tmp->next)
        tmp = tmp->next;
    return tmp;
}

void remove_elem (t_memory_list *l) {
    t_memory_list *tmp = l;

    while (tmp->next) {
        tmp->size = tmp->next->size;
        memmove(tmp->ptr, tmp->next->ptr, tmp->next->size);
        tmp = tmp->next;
        printf("test\n");
    }
    sbrk(0 - sizeof(*tmp));
}

void *my_malloc(size_t size) {
    t_memory_list *tmp;

    tmp = sbrk(sizeof(*tmp));
    if (tmp == (void *) -1)
        exit(84);
    tmp->ptr = sbrk(size);
    if (tmp->ptr == (void *) -1) {
        exit (84);
    }
    tmp->size = size;
    tmp->next = NULL;
    tmp->prev = NULL;
    if (list == NULL) {
        printf("list set.\n");
        list = tmp;
    } else {
        printf("inserted.\n");
        get_last_elem(list)->next = tmp;
    }
    return tmp->ptr;
}

void my_free(void *ptr) {
    t_memory_list *tmp = list;

    if (tmp == NULL) {
        printf("null.\n");
        return;
    }
    while (tmp->next && tmp->ptr != ptr)
        tmp = tmp->next;
    if (tmp->ptr == ptr)
        printf("removing.\n");
        remove_elem(tmp);
}

void *calloc (size_t nmemb, size_t size);
void *realloc (void *ptr, size_t size);
void *reallocarray (void *ptr, size_t nmemb, size_t size);

void main(void) {
    char *str = my_malloc(10);
    char *str2 = my_malloc(10);

    str[0] = 'H';
    str[1] = 'e';
    str[2] = 'l';
    str[3] = 'l';
    str[4] = 'o';
    str[5] = 'T';
    str[6] = 'e';
    str[7] = 's';
    str[8] = 't';
    str[9] = '\0';
    str2[0] = 'T';
    str2[1] = 'e';
    str2[2] = 's';
    str2[3] = 't';
    str2[4] = 'H';
    str2[5] = 'e';
    str2[6] = 'l';
    str2[7] = 'l';
    str2[8] = 'o';
    str2[9] = '\0';
    my_free(str);
    printf("%s\n", str);
    printf("%s\n", str2);
}