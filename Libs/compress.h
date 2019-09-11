/*
 Function: count_trash:

 * Receives as parameters the array of characters frequencies in the text and the hash table with the new
   binary representations.

 * This function aims to count how many characters are in the file
   and to check if in the new representation there will be garbage in the last byte.

*/

long long count_trash(long long int* frequency, HASH* current_hash);

/* 
 Function: create_header:

 * Receives as parameters the output's file pointer, the trash size and the tree size.

 * This function aims to write the first two bytes of the file that will be the output's header.

*/
void create_header(FILE* output, int trash_size, int tree_size);

/*
 Function: create_compressed_file:

 * Receives as parameters the input's and output's file pointers, the frequency array of the characters in text and the 
   hash table with the new binary representations.

 * This function aims to write the output file that will be the compressed file.

 * In it we create the file header and print the tree in pre order.
   Next we will format the new characters representations in the output file.  

*/

void create_compressed_file(FILE* output, FILE* input, long long int* frequency, HASH* current_hash);

/* 
 Function: compress:

 * This function aims to be the user interaction menu to compress your files.

*/
void compress();