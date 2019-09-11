/*
 Function: is_bit_set:
 
 * Receives as parameters the character and the position of the bit that we will verify if it is set.

 * This function aims to verify if a bit of one character is set.

*/
int is_bit_set(unsigned char c, int i);

/*
 Function: generate_decompressed_file:

 * Receives as parameters the input's and output's file pointers that will be manipulated
   for generate the decompressed file.

 * This function aims to generate the decompressed file.

 * It will read the first two bytes of the file and will save the trash size and tree size information.
   After that, will read the preorder tree and construct it. With a tree in hand, it will read byte by byte 
   from the input file and will translate the new binary representation to the conventional ASCII representation.

 * Attempt to the last one loop that will make the operation up to 7 until the size of the garbage, because if there 
   is garbage, the byte will not be 100% filled.

*/

void generate_decompressed_file(FILE *input, FILE* output);
/*
 Function: decompress:

 * This function aims to be the user interaction menu to decompress your files.

*/
void decompress(); 