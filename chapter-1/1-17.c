/*
Write a program to print all input lines that are longer than 80
characters. 0
*/

#include <stdio.h>

#define MAX_LINE_LENGTH 1000
#define PRINT_LINE_LENGTH 80

int getLineLength(char s[]);

int main(void)
{
    char line[MAX_LINE_LENGTH];
    int len;

    while ((len = getLineLength(line)) > 0)
    {
        if (len > PRINT_LINE_LENGTH)
        {
           printf("%s\n", line);
        }
    }

    return 0;
}

int getLineLength(char s[])
{
    int c, i;
    for (i = 0; i < MAX_LINE_LENGTH && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}

