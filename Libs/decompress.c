#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "tree.h"
#include "heap.h"
#include "hash.h"
#define RED "\033[1;91m"
#define RESET "\033[0;0m"
#define GREEN "\033[1;92m"

int is_bit_set(unsigned char c, int i)
{
	unsigned char mask = 1 << i;
	return mask & c;
}

void generate_decompressed_file(FILE *input, FILE* output)
{
	unsigned char byte;
	fscanf(input, "%c", &byte);
	int trash_size = byte >> 5;
	int tree_size = 0, i;
	byte = byte << 3;
	byte = byte >> 3;
	tree_size = byte<<8;
	fscanf(input, "%c", &byte);
	tree_size|= byte;
	
	unsigned char tree[tree_size+1];

	for(i=0; i<tree_size; i++)
	{
		fscanf(input, "%c", &byte);
		tree[i] = byte;
	}
	tree[i] = '\0';
	int current_size = 0;
	TREE* new_tree = generate_tree(tree, tree_size, &current_size);
	
	TREE *aux_tree;
	aux_tree = new_tree;
	unsigned char byte1, byte2;
	fscanf(input, "%c", &byte1);
	while (fscanf(input, "%c", &byte2) != EOF)
	{
		for (i = 7; i >= 0; i--)
		{
			if (aux_tree->left == NULL && aux_tree->right == NULL)
			{
				fprintf(output, "%c", *((unsigned char *)aux_tree->c));
				aux_tree = new_tree;
			}
			if (is_bit_set(byte1, i))
			{
				aux_tree = aux_tree->right;
			}
			else
			{
				aux_tree = aux_tree->left;
			}
		}
		byte1 = byte2;
	}

	for (i = 7; i >= trash_size; i--)
	{
		if (aux_tree->left == NULL && aux_tree->right == NULL)
		{
			fprintf(output, "%c", *((unsigned char *)aux_tree->c));
			aux_tree = new_tree;
		}
		if (is_bit_set(byte1, i))
		{
			aux_tree = aux_tree->right;
		}
		else
		{
			aux_tree = aux_tree->left;
		}
	}
	if (aux_tree->left == NULL && aux_tree->right == NULL)
	{
		fprintf(output, "%c", *((unsigned char *)aux_tree->c));
		aux_tree = new_tree;
	}

}

void decompress()
{
	FILE* input;
	char input_name[100];
	begin:
	printf("Insert the file's name to decompress >> ");
	scanf("%s", input_name);
	getchar();
	input = fopen(input_name, "rb");

	if(input == NULL)
	{
		printf("The file wasn't found, insert another one name!\n");
		goto begin;
	}

	FILE *output;
	char output_name[100];
	strcpy(output_name, input_name);
	output_name[strlen(output_name) - 5] = '\0';
	output = fopen(output_name, "wb");

	generate_decompressed_file(input, output);
	fclose(input);
	fclose(output);
	printf(GREEN"Sucess! Your file has been decompacted!\n"RESET);
}