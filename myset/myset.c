/**
 * 
 * חשוב!!! לבדוק בספר אם קיים המודול שמאפשר להגדיר גודל למשתנה
 * 
 */

#include <stdio.h>
#include "set.h"

int main()
{
    set_member arr[] = {127, 0, 34, -1};
    set s;
    empty_set(&s);
    read_set(&s, arr);
    printf("%u\n", s);

    return 0;
}