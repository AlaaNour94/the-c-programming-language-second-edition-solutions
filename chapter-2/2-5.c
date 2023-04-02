
/*
Write the function any (s1, s2 ), which returns the first location
in the string s1 where any character from the string s2 occurs, or -1 if s1
contains no characters from s2

*/

#include <stdio.h>
#include <ctype.h>

int any(char s1[], char s2[])
{
    int i, j, k;

    for (i = j = 0; s1[i] != '\0'; i++)
    {
        for (k = 0; s2[k] != '\0'; k++)
        {
            if ((s1[i] == s2[k]))
            {
                return i;
            }
        }
    }

    return -1;
}

int main(void)
{

    printf("%d\n", any("est", "not"));
}
