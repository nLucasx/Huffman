/*
Function: create_node:

* This function allows you to allocate memory for a tree,
  where each tree of the tree will have character information and the frequency of the character.
*/
TREE *create_node(unsigned char symbol, long long int freq, TREE *leftchild, TREE *rightchild);

/*
Function: return_root:

* This function receives the heap.
* This function aims to always dequeue the first two nodes of the heap, until the end of the heap,
after that we create a new node, with the symbol '*' and the sum of the frequencies, then row the new node in the heap again,
returned from the function, the root of the tree.
*/
TREE *return_root(HEAP *heap);

/*
Function: generate_tree:

* This function takes as parameters the tree string, the size of the tree, and an integer value that will be the size.
which will initially have the value zero.
* In this function we will generate the tree as long as the current size is smaller than the size of the tree,
if it is an asterisk, create a node, and create the tree first with the left children and then with the children
on the right.
*/
TREE* generate_tree(unsigned char tree[],int  tree_size,int *current_size);

/*
Function: print_pre_order_file:

* This function takes as a parameter the tree and the output file that will be saved in the compressed input file.
* This function checks whether the leaf node is an asterisk character or a slash character, if it is saved in the two-slash output file plus the character,
if not, only the character is saved.
*/
void print_pre_order_file(TREE *bt, FILE* output);

/*
Function: create_way:

* This function takes the hash and tree as parameters.
* This function creates a string that will be the binary representation of the character in the tree.
*/
void create_way(HASH* hash, TREE *node);

/*
Function: find_way:

* This function takes as its parameter the hash, tree and string created in the creat_way function.
* In this function it will save in the string current_way the value 0 or 1, 0 if it is left and 1 if it is right, when the node is a leaf.
hash the string representing the character.
*/
void find_way(HASH *hash, TREE *node, unsigned char current_way[]);

/*
Function: size_of_tree:

* This function takes as a parameter the tree.
* In function it will check if the node is a leaf: if it is it will do another check to see if it is an asterisk or a slash, to differentiate the character or if it is just a representation for the tree, otherwise it will add 1 and will check your left and your right.
*/
int size_of_tree(TREE* root);
