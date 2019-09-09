#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "PQlist.h"
#include "heap.h"

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