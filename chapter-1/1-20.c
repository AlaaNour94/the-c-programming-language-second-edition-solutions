/*
    Exercise 1-20. Write a program detab that replaces tabs in the input with the
    proper number of blanks to space to the next tab stop. Assume a fixed set of
    tab stops, say every n columns. Should n be a variable or a symbolic parameter?
*/

#include <stdio.h>

#define TAB_LENGTH 8

int main()
{
    char c;
    int position, nr_of_spaces;
    position = nr_of_spaces = 0;
    while ((c = getchar()) != EOF)
    {

        if (c == '\t')
        {
            nr_of_spaces = TAB_LENGTH - (position % TAB_LENGTH);
            position += nr_of_spaces;
            while (nr_of_spaces--)
            {
                putchar('#');
            }
        }
        else
        {
            putchar(c);
            position++;
            if (c == '\n')
            {
                position = 0;
            }
        }
    }
    return 0;
}