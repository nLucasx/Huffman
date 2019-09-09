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

