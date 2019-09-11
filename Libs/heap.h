/*
 Function: dequeue:
 
 * It only takes one heap as a parameter and will dequeue the node in the first heap position.

 * Attempt that after the first node is dequeued, the node from the last heap position will be
   placed in the first position and the heap properties will probably be broken.
   To maintain them we will need to call the min_heapify function to arrange the heap.

*/
TREE *dequeue(HEAP *heap);

/*
 Function: create_heap:

 * This function aims to allocate memory for a heap and fill all heap positions with null initially. After that,
   will return this new heap.

*/

HEAP *create_heap();

/*
 Function: build_min_heap:

 * Receive as parameters an empty heap and the array with the frequency of characters in the text.

 * This function aims to build a minimal heap. With the frequency of characters, will create nodes with characters of 
   any frequency in the text and will enqueue them in the heap priority queue. 

*/
void build_min_heap(HEAP *heap, long long int *frequency);

/*
 Function: min_heapify:

 * Receives as parameters the heap and the position of the node that you need to compare with your children.

 * This function aims to maintain the properties of a minimum heap, which parents must be smaller than their children.

 * It will compare a father and his children and check if there is a child less often than the father. 
   If so, these nodes will be swapped and the min_heapify function will be called recursively from the position where the swapped
   parent will be. 

*/

void min_heapify(HEAP *heap, int i);

/*
 Function: swapNode:

 * Receives as parameters the heap and position of the nodes that will be swapped.

 * This function aims to swap the position of two nodes.

*/
void swapNode(HEAP *heap, int i, int j);

/*
 Function: enqueue:

 * Receives as parameters the heap and the node that will be queued.

 * This function aims to enqueue a node in the heap priority queue.

 * First, the node will be added at the end of the heap without checking heap properties.
   After that it will loop to verify that this node has less frequency than its parent.
   If your frequency is lower than your parent's, nodes will be swapped and key_index will be updated to the new node position that will
   be compared with your new parent. This loop will rotate until the node's frequency is no less than its parent's. 

*/

void enqueue(HEAP *heap, TREE *item);

/* 
 Function: get_parent_index:

 * Receives as parameter the index of a node in heap.

 * This function aims to return the index of the father's node.
   This calculation is made as follows: i/2.

*/
int get_parent_index(int i);

/* 
 Function: get_left_index:

 * Receives as parameter the index of a node in heap.

 * This function aims to return the index of the left child.
   This calculation is made as follows: 2 * i.
   
*/
int get_left_index(int i);

/* 
 Function: get_right_index:

 * Receives as parameter the index of a node in heap.

 * This function aims to return the index of the right child.
   This calculation is made as follows: (2 * i) + 1.
   
*/
int get_right_index(int i);

/*
  Function: return_frequency:

  * Receive as parameter the input's file pointer.

  * This function aims to create an array of frequencies with 256 positions representing each character of the ASCII table. 
    To count the frequency of each in the file, just go to the array position of the ASCII numeric representation of the character 
    and increment it. After that, the function will return the array.
      
*/
long long int *return_frequency(FILE *input);

