TREE *create_node(unsigned char symbol, long long int freq, TREE *leftchild, TREE *rightchild);
TREE *return_root(HEAP *heap);
TREE* generate_tree(unsigned char tree[],int  tree_size,int *current_size);
void print_pre_order_file(TREE *bt, FILE* output);
void create_way(HASH* hash, TREE *node);
void find_way(HASH *hash, TREE *node, unsigned char current_way[]);
int size_of_tree(TREE* root);
