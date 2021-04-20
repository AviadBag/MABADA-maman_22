#ifndef BITMAP_H
#define BITMAP_H

#include "set.h"

/* Sets the given bit in the given bitmap */
void set_bit(set *, set_member);

/* Clears the given bit in the given bitmap */
void clear_bit(set *, set_member);

/* Returns the given bit from the given bitmap */
unsigned char get_bit(set, set_member);

/* Executes binary "or" on the second given set, using the first given set. */
void binary_or(set, set *);

/* Executes binary "and" on the second given set, using the first given set. */
void binary_and(set, set *);

/* Executes binary "xor" on the second given set, using the first given set. */
void binary_xor(set, set *);

#endif