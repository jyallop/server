#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "sys/types.h"

typedef struct linked_list list;

list *create_list(void *val, size_t data_size);

int free_list(list *);

int get_length(list *);

void add_item(list *, void *val, size_t data_size);

void *get(list *, int index);

#endif
