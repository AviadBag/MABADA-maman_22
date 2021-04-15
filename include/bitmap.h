#ifndef BITMAP_H
#define BITMAP_H

#include "set.h"

/* Sets the given bit in the given bitmap */
void set_bit(set *, char);

/* Clears the given bit in the given bitmap */
void clear_bit(set *, char);

/* Returns the given bit from the given bitmap */
char get_bit(set, char);

#endif