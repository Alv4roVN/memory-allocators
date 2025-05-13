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

	// Test 4: lalloc_free resets the allocator
	lalloc_free(&memory_space);
	assert(memory_space.line_offset == 0);
	printf("[+] Test 4 passed.\n");

	// Test 5: Can allocate again after lalloc_free
	size_t test5_size = 64;
	void *ptr5 = lalloc(&memory_space, test5_size);
	assert(ptr5 != NULL);
	assert(memory_space.line_offset >= test5_size);
	for (size_t i = 0; i < test5_size; ++i) {
		assert(((unsigned char*)ptr5)[i] == 0); // ensure memory was zero-initialized
	}
	printf("[+] Test 5 passed.\n");
}
