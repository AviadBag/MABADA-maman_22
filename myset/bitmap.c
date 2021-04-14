#include "bitmap.h"

void set_bit(uint32_t *bitmap, int8_t bit)
{
    *bitmap |= (1 << bit);
}

void clear_bit(uint32_t *bitmap, int8_t bit)
{
    *bitmap &= ~(1 << bit);
}

int8_t get_bit(uint32_t bitmap, int8_t bit)
{
    return (bitmap & (1 << bit)) >> bit;
}
