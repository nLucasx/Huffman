#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

typedef struct node 
{
	int priority;
	struct node *next;
}NODE;

typedef struct priority_queue
{
	NODE *head;
}PQ;
typedef struct heap
{
	int data[MAX], size;
}HEAP;


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

void enqueueList(PQ *pq, int p, int *cont)
{
	NODE *new_node = (NODE*) malloc(sizeof(NODE));
	new_node->priority = p;
	
	if (pq->head == NULL || (p > pq->head->priority)) {
		new_node->next = pq->head;
		pq->head = new_node;
		(*cont)++;

	} 
	else 
	{
		NODE *current = pq->head;
		while ((current->next != NULL) && (current->next->priority > p)) 
		{
			current = current->next;
			(*cont)++;
		}
	
	new_node->next = current->next;
	current->next = new_node;
	}
}
int main()
{
	int n, number, contHeap = 0, contList = 0, i;
	printf("Type the size of the structures >> ");
	scanf("%d", &n);
	PQ *new_pqueue = malloc(sizeof(PQ));
	new_pqueue->head = NULL;

	HEAP *new_heap = create_heap();

	FILE *output;
	output = fopen("output.txt", "w+");
	fprintf(output, "Index Heap List\n");
	for (i = 0; i < n; i++)
	{	
		number = rand();
		enqueueHeap(new_heap, number, &contHeap);
		enqueueList(new_pqueue, number, &contList);
		fprintf(output, "%d %d %d\n", i, contHeap, contList);
		contHeap = 0;
		contList = 0;
	}	
	fclose(output);

}