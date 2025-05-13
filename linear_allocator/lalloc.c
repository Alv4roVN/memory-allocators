#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "align.h"

#ifndef DEFAULT_ALIGNMENT
#define DEFAULT_ALIGNMENT (2*sizeof(void *))
#endif

TotalMem *lalloc_init(TotalMem *memory_space, void *buffer, size_t buffer_length) {
	assert(buffer_length > 0);
	memory_space->line_buffer = (unsigned char *) buffer;
	memory_space->line_buffer_length = buffer_length;
	memory_space->line_offset = 0;
	return memory_space;
}

void *lalloc(TotalMem *memory_space, size_t size) {
	assert(size > 0);
	uintptr_t current_offset = (uintptr_t) memory_space->line_buffer + (uintptr_t) memory_space->line_offset;
	uintptr_t offset = align_forward(current_offset, DEFAULT_ALIGNMENT);
	offset -= (uintptr_t)memory_space->line_buffer;
	/* Check that we are not allocating memory over the maximum allowed */
	if (memory_space->line_offset + size <= memory_space->line_buffer_length) {
		void *ptr = &memory_space->line_buffer[offset];
		memory_space->line_offset = offset + size;
		memset(ptr, 0, size);
		return ptr;
	}
	return NULL;
}
