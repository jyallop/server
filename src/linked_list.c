#include "linked_list.h"
#include "sys/types.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

typedef struct linked_list {
	void *val;
	size_t size;

	int length;

	struct linked_list *next;
} list;

list *create_list(void *val, size_t data_size) {
	list *new_list = malloc(sizeof(list));
	new_list->val = malloc(data_size);
	memcpy(new_list->val, val, data_size);
	new_list->size = data_size;

	new_list->length = 1;

	new_list->next = NULL;
	return new_list;	
}

void add_item(list *l, void *val, size_t size) {
	while(l->next != NULL) {
		l->length++;
		l = l->next;
	}

	l->length++;
	list *new_node = create_list(val, size);
	l->next = new_node;
}

int get_length(list *l) {
	return l->length;
}

void *get(list *l, int index) {
	while(l->next != NULL) {
		if(index == 0) {
			return l->val;
		}
		l = l->next;
		index--;
	}
	printf("Index out of bounds error, program exiting\n");
	exit(EXIT_FAILURE);
}

int free_list(list *l) {
	free(l->val);
	if(l->next != NULL) {
		free_list(l->next);
	}
	free(l);
	return 0;
}
