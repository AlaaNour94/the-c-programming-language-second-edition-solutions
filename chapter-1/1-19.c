
/*
Write a function reverse (s) that reverses the character
string s. Use it to write a program that reverses its input a line at a time.
*/

#include <stdio.h>

#define MAX_LINE_LENGTH 1000

int getLineLength(char s[]);
void reverse(char s[], int lenght);

int main(void)
{
    char line[MAX_LINE_LENGTH];
    int len;

    while ((len = getLineLength(line)) > 0)
    {
        reverse(line, len);
        printf("%s\n", line);
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

void reverse(char s[], int length)
{
    int start = 0;
    int end = length - 1;
    char temp;
    while (end > start)
    {
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}
