#include <stdio.h>
#include "set.h"

int main()
{
    set s1, s2, s3;
    set_member arr1[] = {127, 0, 34, 43, 23, 34, SET_MEMBERS_ARRAY_TERMINATING_NUMBER};
    set_member arr2[] = {3, 4, 17, 34, SET_MEMBERS_ARRAY_TERMINATING_NUMBER};

    s1 = empty_set();
    read_set(&s1, arr1);
    printf("-----s1------\n");
    print_set(s1);

    s2 = empty_set();
    read_set(&s2, arr2);
    printf("-----s2------\n");
    print_set(s2);

    sub_set(s1, s2, &s3);
    printf("-----s1+s2------\n");
    print_set(s3);

    return 0;
}