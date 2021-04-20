#include "set.h"
#include "bitmap.h"
#include <stdio.h>

#define MEMBER_EXISTS 1
#define PRINT__MEMBERS_PER_LINE 16

int is_empty(set s)
{
    /* Check all cells on the bitmap */
    int i;
    for (i = 0; i < BITMAP_CELLS_NUMBER; i++)
        if (s.bitmap[i] != 0)
            return 0;

    return 1;
}

set empty_set()
{
    set s; /* The new set to return */
    int i;

    for (i = 0; i < BITMAP_CELLS_NUMBER; i++)
        s.bitmap[i] = 0;

    return s;
}

void read_set(set *s, set_member *members)
{
    while (*members != SET_MEMBERS_ARRAY_TERMINATING_NUMBER)
    {
        set_bit(s, *members);
        members++;
    }
}

void print_set(set s)
{
    int counter = 0; /* How many members do we have in the set? */
    set_member i;

    for (i = 0; i < SET_MEMBER_RANGE; i++)
    {
        if (get_bit(s, i) == MEMBER_EXISTS)
        {
            printf("%d ", i);

            counter++;
            if (counter % PRINT__MEMBERS_PER_LINE == 0)
                printf("\n");
        }
    }

    if (counter % PRINT__MEMBERS_PER_LINE != 0)
        printf("\n");
}

/* Copy's source into destination */
static void copy_set(set source, set *destination)
{
    int i;
    for (i = 0; i < BITMAP_CELLS_NUMBER; i++)
    {
        destination->bitmap[i] = source.bitmap[i];
    }
}

void union_set(set set_a, set set_b, set *set_c)
{
    /* I can't just say set_c = set_a, because it contains an array, which is a pointer. */
    copy_set(set_a, set_c);
    binary_or(set_b, set_c);
}