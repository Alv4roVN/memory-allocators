#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#include "align.h"

bool is_power_of_two(uintptr_t n) {
    // when substracting 1 from a power of 2 all its digits flip
    return (n & (n - 1)) == 0;
}

uintptr_t align_forward(uintptr_t ptr, size_t alignment) {
    assert(alignment > 0);
    assert(is_power_of_two(alignment));
    uintptr_t n, a, modulo;
    n = ptr;
    a = (uintptr_t) alignment;
    // faster than calculating the modulo, same result because `a` is a power of 2
    modulo = n & (a-1);
    if (modulo != 0) {
        n += a - modulo;
    }
    return n;
}
