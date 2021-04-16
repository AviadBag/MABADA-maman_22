#include "bitmap.h"

static unsigned char bit_to_index(char bit)
{
    return bit / BITMAP_MEMBERS_PER_CELL;
}

static unsigned char bit_to_offset(char bit)
{
    return bit % BITMAP_MEMBERS_PER_CELL;
}

void set_bit(set *s, char bit)
{
    s->bitmap[bit_to_index(bit)] |= (1 << (bit_to_offset(bit)));
}

void clear_bit(set *s, char bit)
{
    s->bitmap[bit_to_index(bit)] &= ~(1 << bit);
}

char get_bit(set s, char bit)
{
    return (s.bitmap[bit_to_index(bit)] & (1 << bit)) >> bit;
}
