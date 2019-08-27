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

int count_trash(long long int* frequency, HASH* current_hash)
{ 
	long long int trash_bits=0;
	int i;
	for(i=0; i<256; i++)
	{	
		if(frequency[i] != 0)
		{
			trash_bits += frequency[i] * strlen((unsigned char*)current_hash->table[i]);
		}
	}
	//printf("%lld\n", trash_bits);
	return (int)(trash_bits%8 == 0 ? 0 : ((trash_bits/8) + 1)*8 - trash_bits);
}

void create_header(FILE* output, int trash_size, int tree_size)
{
	unsigned char byte;
	byte = trash_size << 5 | tree_size >> 8;
	fprintf(output, "%c", byte);
	byte = tree_size;
	fprintf(output, "%c", byte);
}
 
void create_compressed_file(FILE* output, FILE* input, long long int* frequency, HASH* current_hash, TREE* root)
{
	int trash_size = count_trash(frequency, current_hash);
	int tree_size = size_of_tree(root);

	create_header(output, trash_size, tree_size);
	print_pre_order_file(root, output);

	unsigned char byte, compressed_byte = 0;
	int shift_bit = 7, i;
	while(fscanf(input, "%c", &byte) != EOF)
	{
		unsigned char *binary_representation = (unsigned char *) current_hash->table[byte];
		for (i = 0; i < strlen(binary_representation); i++)
		{
			if(binary_representation[i] == '1') compressed_byte |= 1 << shift_bit;
			shift_bit--;
			if (shift_bit < 0)
			{
				fputc(compressed_byte, output);
				compressed_byte = 0;
				shift_bit = 7;
			}
		}
	}
	if (trash_size) fprintf(output, "%c", compressed_byte);
}

void compress()
{
	int i;
	char compressed_name[100], uncompressed_name[100];
	begin:
	printf("Insert the file's name to be compressed >> ");
	scanf("%s", uncompressed_name);
	getchar();
	FILE *input;
	input = fopen(uncompressed_name, "rb");

	if(input == NULL)
	{
		printf(RED"File wasn't found, insert another name!\n"RESET);
		goto begin;
	}

	long long int *frequency = return_frequency(input);
	rewind(input);

	HEAP *new_heap = create_heap();
	build_min_heap(new_heap, frequency);

	TREE *root = return_root(new_heap);

	HASH *new_hash = create_hash();
	create_way(new_hash, root);

	FILE *output;
	printf("Insert the name of compressed file >> ");
	scanf("%s", compressed_name);
	strcat(compressed_name, ".huff");
	getchar();
	output = fopen(compressed_name, "wb");

	create_compressed_file(output, input, frequency, new_hash, root);
	printf(GREEN"Sucess! Your file has been compacted!\n"RESET);
	fclose(output);
	fclose(input);

}
