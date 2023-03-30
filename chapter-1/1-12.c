#include <stdio.h>

#define IN 0
#define OUT 1

int main()
{

    int c, state;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t')
        {
            state = OUT;
            continue;
        }

        if (state == OUT)
        {
            putchar('\n');
        }

        state = IN;
        putchar(c);
    }
}