/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include "my.h"
#include "lemin.h"

#ifndef B_CPE_300_BER_3_1_BSLEMIN_NICOLAS_LATTEMANN_QUEUE_H
    #define B_CPE_300_BER_3_1_BSLEMIN_NICOLAS_LATTEMANN_QUEUE_H

void enqueue(room_t *room, room_t *queue[], int queue_len);

room_t *dequeue(room_t *queue[], int queue_len);

int queue_is_empty(room_t *queue[]);

void init_queue(room_t *queue[], int queue_len);

#endif //B_CPE_300_BER_3_1_BSLEMIN_NICOLAS_LATTEMANN_QUEUE_H
