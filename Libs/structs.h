/*
 
 * This file will declare all structures used in the program. 

*/

typedef struct TREE
{
	void *c;
	int frequency;
	struct TREE *left;
	struct TREE *right;
}TREE;

typedef struct HEAP
{
	int size;
	TREE *data[257];
}HEAP;

typedef struct HASH
{
	void *table[256];
}HASH;
