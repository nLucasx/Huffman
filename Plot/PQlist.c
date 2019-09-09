#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "PQlist.h"

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