#ifndef SET_H
#define SET_H

#define SET_MEMBER_RANGE 128 /* How many different numbers can we insert? */
#define BITMAP_CELLS_NUMBER (SET_MEMBER_RANGE / 8) /* Every bit is one possible member */
#define BITMAP_MEMBERS_PER_CELL (SET_MEMBER_RANGE / BITMAP_CELLS_NUMBER)

#define SET_MEMBERS_ARRAY_TERMINATING_NUMBER SET_MEMBER_RANGE

typedef unsigned char cell;
typedef struct set { cell bitmap[BITMAP_CELLS_NUMBER]; } set;
typedef unsigned char set_member;

/* Checks if a set is empty */
int is_empty(set);

/* Returns an empty set */
set empty_set();

/*
 Replaces the given set with the given values.
 The values should be given in an array, with SET_MEMBERS_ARRAY_TERMINATING_NUMBER at the end of the array.
*/
void read_set(set*, set_member*);

/* Prints the given set */
void print_set(set);

/* Puts the union of set_a and set_b in set_c */
void union_set(set set_a, set set_b, set* set_c);

/* Puts the intersection of set_a and set_b in set_c */
void intersect_set(set set_a, set set_b, set* set_c);

/* Puts the subtraction of set_a and set_b in set_c (set_a - set_b) */
void sub_set(set set_a, set set_b, set* set_c);

/* Puts the symetric diff of set_a and set_b in set_c */
void symdiff_set(set set_a, set set_b, set* set_c);

#endif