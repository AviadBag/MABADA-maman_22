#include "set.h"
#include "bitmap.h"
#include <stdio.h>

#define MEMBER_NOT_EXISTS 0
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

void intersect_set(set set_a, set set_b, set *set_c)
{
    /* I can't just say set_c = set_a, because it contains an array, which is a pointer. */
    copy_set(set_a, set_c);
    binary_and(set_b, set_c);
}

void sub_set(set set_a, set set_b, set *set_c)
{
    int i;
    set_member set_a_member; /* The current set_a member */
    set_member set_b_member; /* The current set_b member */

    *set_c = empty_set();

    for (i = 0; i < BITMAP_CELLS_NUMBER * BITMAP_MEMBERS_PER_CELL; i++)
    {
        set_a_member = get_bit(set_a, i);
        set_b_member = get_bit(set_b, i);
        if (set_a_member == MEMBER_EXISTS && set_b_member == MEMBER_NOT_EXISTS)
            set_bit(set_c, i);
    }
}

void symdiff_set(set set_a, set set_b, set *set_c)
{
}