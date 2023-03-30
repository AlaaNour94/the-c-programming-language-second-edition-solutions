/*
Write a program to print a histogram of the frequencies of different characters in its input.
*/

#include <stdio.h>

#define NUMBER_COUNT 10
#define ALPHA_COUNT 26

int main(void)
{
    int c;

    int map[NUMBER_COUNT + ALPHA_COUNT];
    int i;
    for ( i = 0; i < (NUMBER_COUNT + ALPHA_COUNT); i++)
    {
        map[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c == '\n' || c == '\t' || c == ' ')
        {
            continue;
        }

        if ('a' >= c && c <= 'z'){
            ++map[c - 'a'];
        }else if ('0' >= c && c <= '9'){
            ++map[c-'0' + ALPHA_COUNT];
        }

    }

    for ( i = 0; i < (NUMBER_COUNT + ALPHA_COUNT); i++)
    {
        if (map[i] > 0)
        {
            if (i < ALPHA_COUNT) {
                printf("%c ", i + 'a');
            } else {
                printf("%c ", i + '0' + ALPHA_COUNT);
            }
            for (int j = 0; j < map[i]; j++)
            {
                printf(" | ");
            }
            printf("\n");
        }
    }
}