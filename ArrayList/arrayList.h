#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdbool.h>

typedef struct {
	int size;
	int capacity;
	int *data;
} ArrayList;

ArrayList *arraylist_new(int capacity);
void arraylist_destroy(ArrayList *list);
bool arraylist_is_empty(ArrayList *list);
int arraylist_item_at(ArrayList *list, int index);
void arraylist_remove(ArrayList *list, int item);
bool arraylist_push(ArrayList *list, int item);
void arraylist_insert(ArrayList *list, int index, int item);
void arraylist_prepend(ArrayList *list, int item);
int arraylist_pop(ArrayList *list);
void arraylist_delete(ArrayList *list, int index);
int arraylist_find(ArrayList *list, int item);
bool arraylist_resize(ArrayList *list, int new_capacity);

#endif
