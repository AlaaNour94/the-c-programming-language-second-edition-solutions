
/*
Exercise 4-8. Suppose that there will never be more than one character
pushback. Modify getch and ungetch accordingly.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int buff = -1;

int getch()
{

    if (buff != -1)
    {
        char temp = buff;
        buff = -1;
        return temp;
    }
    return getchar();
}

void ungetch(int c)
{
    if (buff != -1)
    {
        printf("ungetch: Too many characters\n");
    }
    else
    {
        buff = c;
    }
}