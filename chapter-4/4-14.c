
/*
Exercise 4-14. Define a macro swap(t,x,y)
of type t. (Block structure will help.)
*/

#include <stdio.h>


#define swap(t, x, y) \
    {\
        t temp; \
        temp = x;\
        x = y;\
        y = temp;\
    }\

int main(void)
{
    int x, y;
    x = 5;
    y = 3;
    swap(int, x, y);
    
    printf("%d - %d\n", x, y);
}


/*  we use  { }  in swap  to create a block so if other locations in code use a variable called temp we don't conflict with it
as variables are limited by their block.
*/