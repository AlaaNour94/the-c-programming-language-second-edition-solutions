/*
Write a program to print a histogram of the lengths of words in
its input. It is easy to draw the histogram with the bars horizontal; a vertical
orientation is more challenging
*/

#include <stdio.h>

#define OUT 0
#define IN 1

int main(void)
{
    int c, count, state;
    count = 0;
    state = IN;

    int length[100];

    for (int i = 0; i < 100; i++)
    {
        length[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c == '\n' || c == '\t' || c == ' ')
        {
            state = OUT;
            continue;
        }

        if (state == OUT && count > 0)
        {
            ++length[count];
            count = 0;
        }

        ++count;
        state = IN;
    }

    if (count > 0)
    {
        ++length[count];
    }
    for (int i = 0; i < 20; i++)
    {
        if (length[i] > 0)
        {
            printf("%d ", i);

            for (int j = 0; j < length[i]; j++)
            {
                printf(" | ");
            }
            printf("\n");
        }
    }
}