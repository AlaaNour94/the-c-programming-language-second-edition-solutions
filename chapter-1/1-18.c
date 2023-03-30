/*
Write a program to remove trailing blanks and tabs from each
line of input, and to delete entirely blank lines
*/

#include <stdio.h>

#define MAX_LINE_LENGTH 200

int getLineLength(char s[]);
void removeTrailing(char s[], int length);

int main(void)
{
    char line[MAX_LINE_LENGTH];
    int len;
    while ((len = getLineLength(line)) != 0)
    {
        removeTrailing(line, len);
        printf("%s\n", line);
    }
    return 0;
}

int getLineLength(char s[])
{
    int i, c;
    for (i = 0; i < MAX_LINE_LENGTH && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}

void removeTrailing(char s[], int length)
{
    int i;
    for (i = length - 1; i >= 0 && (s[i] != ' ' || s[i] != '\t'); i--)
    {
        ;
    }
    s[i+1] = '\0';
}