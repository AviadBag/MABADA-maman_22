#ifndef SET_H
#define SET_H

#include <stdint.h>

typedef uint32_t set;
typedef int8_t   set_member;

/* Checks if a set is empty */
int is_empty(set);

/* Returns an empty set */
set empty_set();

/*
 Replaces the given set with the given values.
 The values should be given in an array, with -1 at the end of the array.
*/
void read_set(set*, set_member*);

/* Prints the given set */
void print_set(set);

/* Puts the union of set_a and set_b in set_c */
void union_set(set set_a, set set_b, set* set_c);

/* Puts the intersection of set_a and set_b in set_c */
void intersect_set(set set_a, set set_b, set* set_c);

/* Puts the subtraction of set_a and set_b in set_c */
void sub_set(set set_a, set set_b, set* set_c);

/* Puts the symetric diff of set_a and set_b in set_c */
void symdiff_set(set set_a, set set_b, set* set_c);

#endif