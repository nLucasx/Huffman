#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "tree.h"
#include "heap.h"
#include "hash.h"
#include "compress.h"
#include "decompress.h"
//cores em ANSI utilizadas 
#define RED "\033[1;91m"
#define RESET "\033[0;0m"
#define GREEN "\033[1;92m"
int main()
{
	
	int option, i;
	printf(RED"   	    __ __     ______  ____                 __\n");       
  	printf("  	   / // /_ __/ _/ _/ / __/__  _______  ___/ /__ ____\n");
 	printf(" 	  / _  / // / _/ _/ / _// _ \\/ __/ _ \\/ _  / -_) __/\n");
	printf("	 /_//_/\\_,_/_//_/  /___/_//_/\\__/\\___/\\_,_/\\__/_/\n\n\n"RESET); 
                                                   
	printf(GREEN"			[1] - Compress\n");
	printf("			[2] - Decompress\n");
	printf("			[3] - Exit\n\n"RESET);
	begin:
	printf("Huff >> ");
	scanf("%d", &option);
	getchar();

	if (option == 1)
	{
		compress();
	}
	else if (option == 2)
	{
		decompress();
	}
	else if (option == 3)
	{
		return 0;
	}
	else
	{
		printf("Invalid option! Try again.\n");
		goto begin;
	}
}
//AAAAAABBBBBCCCCDDDEEF