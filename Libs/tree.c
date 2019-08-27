#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "tree.h"
#include "heap.h"
#include "hash.h"

TREE *create_node(unsigned char symbol, long long int freq, TREE *leftchild, TREE *rightchild)
{
	unsigned char *symbol_aux = malloc(sizeof(unsigned char));
	*symbol_aux = symbol;

	TREE *new_tree = malloc(sizeof(TREE));
	new_tree->c = symbol_aux;
	new_tree->frequency = freq;
	new_tree->left = leftchild;
	new_tree->right = rightchild;

	return new_tree;
}


TREE *return_root(HEAP *heap)
{
	TREE *first, *second;
	while (heap->size > 1)
	{
		first = dequeue(heap);
		second = dequeue(heap);
		enqueue(heap, create_node('*', first->frequency + second->frequency, first, second));
	}
	first = dequeue(heap);
	free(heap);
	return first;
}

void create_way(HASH* hash, TREE *node)
{
	unsigned char current_way[20];
	current_way[0] = '\0';
	find_way(hash, node, current_way); 
}

void find_way(HASH *hash, TREE *node, unsigned char current_way[])
{
	if(*((unsigned char*)node->c) == '*' && (node->left != NULL || node->right != NULL))
	{
		int size = strlen(current_way);
		current_way[size] = '0';
		current_way[size+1] = '\0';
		find_way(hash, node->left, current_way);
		current_way[size] = '1';
		current_way[size+1] = '\0';
		find_way(hash, node->right, current_way);
		current_way[size] = '\0';
	}
	else
	{
		unsigned char *new_string = malloc(sizeof(unsigned char)*20);
		strcpy(new_string, current_way);
		put(hash, *((int*)node->c), new_string);
	}
}

void print_pre_order_file(TREE *bt, FILE* output)
{
	if (bt != NULL)
	{
		if (bt->right == NULL && bt->left == NULL)
		{
			if (*(unsigned char*)bt->c == '*' || *(unsigned char*)bt->c == '\\') fprintf(output,"\\%c",*(unsigned char*) bt->c);
			else fprintf(output, "%c", *(unsigned char*)bt->c);
		}
		else
		{
			fprintf(output, "%c", *(unsigned char*)bt->c);
		}
		print_pre_order_file(bt->left, output);
		print_pre_order_file(bt->right, output);
	}
}

int size_of_tree(TREE* root)
{
	if(root->left == NULL && root->right == NULL){
		if(*(unsigned char*) root->c == '\\')return 2;
		if(*(unsigned char*) root->c == '*')return 2;
		return 1;
	}
	else if (root != NULL)return 1 + size_of_tree(root->left) + size_of_tree(root->right);
	return 0;
}

TREE* generate_tree(unsigned char tree[] ,int  tree_size, int* current_size)
{
	if(*current_size >= tree_size) return NULL;
	TREE* new_tree;
	if(tree[*current_size] == '*')
	{
		new_tree = create_node(tree[*current_size], 0, NULL, NULL);
		++(*current_size);
		new_tree->left = generate_tree(tree, tree_size, current_size);
		++(*current_size);
		new_tree->right = generate_tree(tree, tree_size, current_size);
	}
	else
	{
		if(tree[*current_size] == '\\') ++(*current_size);
		new_tree = create_node(tree[*current_size], 0, NULL, NULL);
	}
	return new_tree;
}