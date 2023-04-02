
/*
Write an alternate version of squeeze (s 1,s2) that deletes
each character in s 1 that matches any character in the string s2

*/

#include <stdio.h>
#include <ctype.h>
void squeez(char s1[], char s2[])
{
    int i, j, k, found;

    for (i = j = 0; s1[i] != '\0'; i++)
    {
        found = 0;
        for (k = 0; s2[k] != '\0' && !found; k++)
        {
            found = (s1[i] == s2[k]);
        }

        if (!found)
        {
            s1[j++] = s1[i];
        }
    }

    s1[j] = '\0';
}
int main(void)
{
    char s1[] = "test";
    char s2[] = "not";
    squeez(s1, s2);
    printf("%s\n", s1);
}
