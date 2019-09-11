#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "heap.h"
#include "tree.h"

HEAP *create_heap()
{
	HEAP *new_heap = malloc(sizeof(HEAP));
	new_heap->size = 0;
	int i;
	for (i = 1; i <= 257; i++)
	{
		new_heap->data[i] = NULL;
	}
	return new_heap;
}
int get_parent_index(int i)
{
	return i/2;
}
int get_left_index(int i)
{
	return 2*i;
}
int get_right_index(int i)
{
	return (2*i) + 1;
}
void swapNode(HEAP *heap, int i, int j)
{
	TREE *temp;
	temp = heap->data[i];
	heap->data[i] = heap->data[j];
	heap->data[j] = temp;	
}
void enqueue(HEAP *heap, TREE *item)
{
	if (heap->size < 256)
	{
		int i;
		heap->data[++heap->size] = item;
		int key_index = heap->size;
		int parent_index = get_parent_index(heap->size); 
		while (parent_index >= 1 && ((TREE *)heap->data[key_index])->frequency < ((TREE *)heap->data[parent_index])->frequency)
		{
			swapNode(heap, key_index, parent_index);
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

TREE *dequeue(HEAP *heap)
{
	if (heap->size) 
	{
		TREE *item = heap->data[1];
		heap->data[1] = heap->data[heap->size];
		heap->size--;
		min_heapify(heap, 1);
		return item;
	}
	else
	{
		printf("UNDERFLOW\n");
		return NULL;
	}
}
void build_min_heap(HEAP *heap, long long int *frequency)
{
	int i;
	for (i = 0; i < 256; i++)
	{
		if (frequency[i] != 0)
		{
			enqueue(heap, create_node((unsigned char)i, frequency[i], NULL, NULL));
		}
	}
}
void min_heapify(HEAP *heap, int i)
{
	int smallest;
	int left_index = get_left_index(i);
	int right_index = get_right_index(i);
	if (left_index <= heap->size && ((TREE *)heap->data[left_index])->frequency < ((TREE *)heap->data[i])->frequency)
	{
		smallest = left_index;
	} 
	else 
	{
		smallest = i;
	}
	if (right_index <= heap->size && ((TREE *)heap->data[right_index])->frequency < ((TREE *)heap->data[smallest])->frequency)
	{
		smallest = right_index;
	}
	if (((TREE *)heap->data[i])->c != ((TREE *)heap->data[smallest])->c)
	{
		swapNode(heap, i, smallest);
		min_heapify(heap, smallest);
	}
}
long long int *return_frequency(FILE *input)
{
	long long int *frequency = calloc(256, sizeof(long long int)), i;
	unsigned char c;
	// if (input == NULL) verificar
	while (fscanf(input, "%c", &c) != EOF)
	{
		frequency[(int)c]++;
	}
	return frequency;
}
