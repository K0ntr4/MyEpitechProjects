#ifndef MEMORY_MALLOC_H
#define MEMORY_MALLOC_H

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_memory_list {
    size_t size;
    void *ptr;
    struct s_memory_list *next;
    struct s_memory_list *prev;
} t_memory_list;

void hello(void);

#endif //MEMORY_MALLOC_H
