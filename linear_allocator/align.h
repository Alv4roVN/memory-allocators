#ifndef ALIGN_H
#define ALIGN_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

bool is_power_of_two(size_t n);
uintptr_t align_forward(uintptr_t ptr, size_t alignment);

typedef struct {
	unsigned char *line_buffer;
	size_t line_buffer_length;
	size_t line_offset;
} TotalMem;

TotalMem *lalloc_init(TotalMem *memory_space, void *buffer, size_t buffer_length);
void *lalloc(TotalMem *memory_space, size_t size);
void lalloc_free(TotalMem *memory_space);

#endif
