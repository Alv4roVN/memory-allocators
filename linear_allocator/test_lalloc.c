#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "align.h"

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main() {
	unsigned char buf[BUF_SIZE];
	TotalMem memory_space = {0};

	// Test 1: Memory space initialization
	lalloc_init(&memory_space, buf, BUF_SIZE);
	assert(memory_space.line_buffer_length == BUF_SIZE);
	printf("[+] Test 1 passed.\n");

	// Test 2: Memory allocation under max buffer size
	size_t test2_size = 128;
	void *ptr = lalloc(&memory_space, test2_size);
	assert(memory_space.line_offset == test2_size);
	assert(ptr != NULL);
	printf("[+] Test 2 passed.\n");

	// Test 3: Memory allocation over max buffer size
	size_t test3_size = BUF_SIZE;
	void *ptr_test3 = lalloc(&memory_space, test3_size);
	assert(ptr_test3 == NULL);
	assert(memory_space.line_offset == test2_size);
	printf("[+] Test 3 passed.\n");
}
