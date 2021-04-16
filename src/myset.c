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
    set s = empty_set();
    read_set(&s, arr);
    print_set(s);

    return 0;
}