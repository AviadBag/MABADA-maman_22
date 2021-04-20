#include "bitmap.h"

static unsigned char bit_to_index(set_member bit)
{
    return bit / BITMAP_MEMBERS_PER_CELL;
}

static unsigned char bit_to_offset(set_member bit)
{
    return bit % BITMAP_MEMBERS_PER_CELL;
}

void set_bit(set *s, set_member bit)
{
    s->bitmap[bit_to_index(bit)] |= (1 << (bit_to_offset(bit)));
}

void clear_bit(set *s, set_member bit)
{
    s->bitmap[bit_to_index(bit)] &= ~(1 << bit_to_offset(bit));
}

unsigned char get_bit(set s, set_member bit)
{
    return (s.bitmap[bit_to_index(bit)] & (1 << bit_to_offset(bit))) >> bit_to_offset(bit);
}

void binary_or(set src, set *dest)
{
    int i;
    for (i = 0; i < BITMAP_CELLS_NUMBER; i++)
        dest->bitmap[i] |= src.bitmap[i];
}

void binary_and(set src, set *dest)
{
    int i;
    for (i = 0; i < BITMAP_CELLS_NUMBER; i++)
        dest->bitmap[i] &= src.bitmap[i];
}

void binary_xor(set src, set *dest)
{
    int i;
    for (i = 0; i < BITMAP_CELLS_NUMBER; i++)
        dest->bitmap[i] ^= src.bitmap[i];
}