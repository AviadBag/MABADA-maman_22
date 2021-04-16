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
    s->bitmap[bit_to_index(bit)] &= ~(1 << bit);
}

unsigned char get_bit(set s, set_member bit)
{
    return (s.bitmap[bit_to_index(bit)] & (1 << bit)) >> bit;
}
