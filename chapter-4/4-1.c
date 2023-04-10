
/*
Write the function strrindex
(s, t), which returns the position
of the rightmost occurrence of t in s, or - 1 if there is none
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LIMIT 100

int getLine(char s[], int max);
int strrindex(char source[], char searchfor[]);

int main()
{
    char pattern[] = "ould";
    int len, max, index, limit, found;
    found = 0;
    char line[LIMIT];
    while (((len = getLine(line, LIMIT)) > 0))
    {
        if ((index = strrindex(line, pattern)) != -1)
        {
            printf("line=%s  index=%d\n", line, index);
            found++;
        }
    }

    return found;
}

int getLine(char s[], int max)
{
    int c, i;
    for (i = 0; i < max && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}

int strrindex(char source[], char searchfor[])
{

    int i, j, k, index;
    index = -1;
    for (i = 0; source[i] != '\0'; i++)
    {
        for (j = i, k = 0; searchfor[k] != '\0' && source[j] == searchfor[k]; j++, k++)
        {
            ;
        }

        if (k > 0 && searchfor[k] == '\0')
        {
            index = i;
        }
    }
    return index;
}

/*
we can do this two ways
    1- continue to do the  strrindex  and every time update index  then return it's final value
    2- start from the end of source  only change line 50  to this `for (i = strlen(source); i >= 0; i--)`
*/