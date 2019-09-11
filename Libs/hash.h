/*
 Function: create_hash:

 * That function aims to allocate memory for a hash table, 
   which will store all new binary representations of ASCII characters in the file.

 * Attempt that all hash table positions will be initialized to NULL.

*/

HASH *create_hash();

/*
 Function: put:

 * Receives the hash table, the position that will save the representation and the representation.

 * That function aims to save the new binary representation of the characters in the file that will
   be compressed. 

*/
void put(HASH *hash, int position, char *string);