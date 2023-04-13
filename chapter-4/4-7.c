
/*
Exercise 4-7. Write a routine ungets (s) that will push back an entire string
onto the input. Should ungets know about buf and bufp, or should it just
use ungetch?
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LIMIT 100

int getch();
int getstr(char line[], int limit);
void ungetch(int c);
void ungets(char s[]);

int main()
{
    char s[] = "Hello World!\n";
    char temp[LIMIT];
    ungets(s);

    getstr(temp, LIMIT);

    printf("%s\n", temp);
    return 0;
}

#define BUFF_LIMIT 100
int buffp = 0;
char buffer[BUFF_LIMIT];

int getch()
{
    return (buffp > 0) ? buffer[--buffp] : getchar();
}
int getstr(char line[], int limit)
{
    int i = 0, c;

    while (limit - 1 > 0 && (c = getch()) != EOF && c != '\n')
    {
        line[i++] = c;
    }

    if (c == '\n')
    {
        line[i++] = c;
    }

    line[i] = '\0';

    return i;
}

void ungetch(int c)
{
    if (buffp > BUFF_LIMIT)
    {
        printf("ungetch: Too many characters\n");
    }
    buffer[buffp++] = c;
}

void ungets(char s[])
{
    for (int i = strlen(s); i >= 0; i--)
    {
        ungetch(s[i]);
    }
    s[0] = '\0';
}