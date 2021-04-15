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
    while (*members != -1)
    {
        set_bit(s, *members);
        members++;
    }
}

void print_set(set s)
{
    int counter = 0; /* How many members do we have in the set? */
    int i;

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