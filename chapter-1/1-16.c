/*
Revise the main routine of the longest-line program so it will
correctly print the length of arbitrarily long input lines, and as much as possible
of the text.
*/

#include <stdio.h>

#define MAX_LINE_LENGTH 100

int getLineLength(char s[]);
void copy(char from[], char to[]);

int main(void)
{
    char line[MAX_LINE_LENGTH];
    char longest_line[MAX_LINE_LENGTH];
    int max = 0;
    int len;

    while ((len = getLineLength(line)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(line, longest_line);
        }
    }
    if (max > 0)
    {
        printf("max line is %s with LENGTH of %d", longest_line, max);
    }
    return 0;
}

int getLineLength(char s[])
{
    char c;
    int i;
    for (i = 0; i < MAX_LINE_LENGTH && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}

void copy(char from[], char to[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        i++;
    }
}