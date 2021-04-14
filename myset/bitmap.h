#ifndef BITMAP_H
#define BITMAP_H

#include <stdint.h>

/* Sets the given bit in the given bitmap */
void set_bit(uint32_t*, int8_t);

/* Clears the given bit in the given bitmap */
void clear_bit(uint32_t*, int8_t);

/* Returns the given bit from the given bitmap */
int8_t get_bit(uint32_t, int8_t);

#endif