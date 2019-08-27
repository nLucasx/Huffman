#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include <CUnit/CUnit.h>
#include "CUnit/Basic.h"
#include "heap.h"
#include "tree.h"
#include "hash.h"

int init_suite(void) {
	return 0;
}

int clear_suite(void) {
	return 0;
}

void heap_test()
{
	HEAP* new_heap = create_heap();

	CU_ASSERT(0 == new_heap->size);

	CU_ASSERT(NULL != new_heap);

	TREE* test = create_node('z', 3, NULL, NULL);
	enqueue(new_heap, test);

	TREE* test_2 = create_node('b', 50, NULL, NULL);
	enqueue(new_heap, test_2);

	TREE* test_3 = create_node('f', 25, NULL, NULL);
	enqueue(new_heap, test_3);

	CU_ASSERT('b' == *(unsigned char*)new_heap->data[2]->c);
	CU_ASSERT(25 == new_heap->data[3]->frequency);

	TREE* test_4 = dequeue(new_heap);

	CU_ASSERT('z' == *(unsigned char*)test_4->c);
	test_4 = dequeue(new_heap);

	CU_ASSERT('f' == *(unsigned char*)test_4->c);
	test_4 = dequeue(new_heap);

	CU_ASSERT(50 == test_4->frequency);
}

void hash_test()
{

	HASH* test_hash = create_hash();

	CU_ASSERT(NULL == test_hash->table[time(NULL) % 256]);
	CU_ASSERT(NULL == test_hash->table[time(NULL) % 256]);
	CU_ASSERT(NULL == test_hash->table[time(NULL) % 256]);
	CU_ASSERT(NULL == test_hash->table[time(NULL) % 256]);

	unsigned char way1[] = "0101", way2[] = "11", way3[] = "01";
	put(test_hash, (int)'c', way1);
	put(test_hash, (int)'a', way2);
	put(test_hash, (int)'b', way3);
	CU_ASSERT_STRING_EQUAL(test_hash->table[(int)'c'], "0101");
	CU_ASSERT_STRING_EQUAL(test_hash->table[(int)'a'], "11");
	CU_ASSERT_STRING_EQUAL(test_hash->table[(int)'b'], "01");

}
void tree_test()
{
	FILE *input = fopen("cunit.txt", "rb");
	long long int *frequency = return_frequency(input);
	HEAP *new_heap = create_heap();
	build_min_heap(new_heap, frequency);

	TREE *root = return_root(new_heap);
	

}
 

int main(void) {
	
	CU_pSuite pSuite = NULL;

	if(CUE_SUCCESS != CU_initialize_registry()) {
		return CU_get_error();
	}

	pSuite = CU_add_suite("Basic_Test_Suite", init_suite, clear_suite);
	if(pSuite == NULL){
		return CU_get_error();
	}

    if(NULL == CU_add_test(pSuite, "heap_test", heap_test)) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/*if(NULL == CU_add_test(pSuite, "huff_test", huff_test)) {
		CU_cleanup_registry();
		return CU_get_error();
	}*/
	if(NULL == CU_add_test(pSuite, "hash_test", hash_test)) {
		CU_cleanup_registry();
		return CU_get_error();
	}
	

	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}