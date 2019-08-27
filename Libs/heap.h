TREE *dequeue(HEAP *heap);
HEAP *create_heap();
void build_min_heap(HEAP *heap, long long int *frequency);
void min_heapify(HEAP *heap, int i);
void swapNode(HEAP *heap, int i, int j);
void enqueue(HEAP *heap, TREE *item);
int get_parent_index(int i);
int get_left_index(int i);
int get_right_index(int i);
long long int *return_frequency(FILE *input);//tirar

