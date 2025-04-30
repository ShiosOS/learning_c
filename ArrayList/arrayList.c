#include <stdlib.h>
#include "arrayList.h"

ArrayList *arraylist_new(int initial_capacity)
{
	ArrayList *list = malloc(sizeof(ArrayList));
	if (!list) return NULL;

	list->size = 0;
	list->capacity = initial_capacity;
	list->data = (int *)malloc(sizeof(int));

	if(!list->data) {
		free(list);
		return NULL;
	}
	return list;
}

void arraylist_destroy(ArrayList* list)
{
	if(list){
		free(list->data);
		free(list);
	}
}

bool arraylist_is_empty(ArrayList *list)
{
	return list ? list->size : 0;
}

int arraylist_item_at(ArrayList *list, int index)
{
	if (!list || index >= list->size)
	{
		return -1;
	}

	return list->data[index];
}

bool arraylist_resize(ArrayList *list, int new_capacity)
{
	if (!list) return 0;

	int *new_data = (int *)realloc(list->data, new_capacity * sizeof(int));
	if (!new_data) return 0;

	list->data = new_data;
	list->capacity = new_capacity;
	return 1;
};

bool arraylist_push(ArrayList *list, int item)
{
	if (!list) return 0;

	if (list->size >= list->capacity)
	{
		int new_capacity = list->capacity * 2;
		if (!arraylist_resize(list, new_capacity)) return 0;
	}

	list->data[list->size] = item;
	list->size++;
	return 1;
}
