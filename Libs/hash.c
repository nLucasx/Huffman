#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "heap.h"
#include "tree.h"

HASH *create_hash()
{
	HASH *new_hash = malloc(sizeof(HASH));
	int i;
	for (i = 0; i < 256; i++)
	{
		new_hash->table[i] = NULL;
	}
	return new_hash;
}
void put(HASH *hash, int position, char *string)
{
	hash->table[position] = string;
}
