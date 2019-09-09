#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "heap.h"

HEAP *create_heap()
{
	HEAP *new_heap = malloc(sizeof(HEAP));
	new_heap->size = 0;

	return new_heap;
}
int get_parent_index(int i)
{
	return i/2;
}
void enqueueHeap(HEAP *heap, int priority, int *cont)
{
	if (heap->size < MAX)
	{
		(*cont)++;
		int temp;
		heap->data[++heap->size] = priority;
		int key_index = heap->size;
		int parent_index = get_parent_index(heap->size); 
		while (parent_index >= 1 && heap->data[key_index] < heap->data[parent_index])
		{
			temp = heap->data[key_index];
            heap->data[key_index] = heap->data[parent_index];
            heap->data[parent_index] = temp;
            (*cont)++;

			key_index = parent_index;
			parent_index = get_parent_index(key_index);
		}
	}
	else
	{
		printf("OVERFLOW\n");
		return;
	}
}