#include <stddef.h>
#include <string.h>

static unsigned char *line_buffer;
static size_t line_buffer_length;
static size_t line_offset;

void *lalloc(size_t size) {
	/* First we have to check that we are not allocating memory outside of the 
	 * maximum allowed */

	if (line_offset + size <= line_buffer_length) {
		void *ptr = &line_buffer[line_offset];
		line_offset += size;
		memset(ptr, 0, size);
		return ptr;
	}

	return NULL
}

void lfree(); 
/* Does nothing, it is not possible to free a specific chunk of memory set with 
 * linear allocation, it's here for completeness sake */


