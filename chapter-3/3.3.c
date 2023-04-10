
/*
Write a function expand (s 1, s2) that expands shorthand nota-
tions like a - z in the string s 1 into the equivalent complete list abc ... xyz in
s2. Allow for letters of either case and digits, and be prepared to handle cases
like a-b-c and a-zO-9 and -a-z. Arrange that a leading or trailing - is
taken literally.
*/


/* does not handle all cases */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LIMIT 100
void expand(char s1[], char s2[])
{
    
    int count = 0;
    for (int m = 0; s1[m] != '\0'; m++)
    {
        if (s1[m] != '-')
            count++;
    }

    int step = (count % 2) == 0 ? 3 : 2;

    int i, j ;
    // if (s1[i] =='-'){
    //     i++;
    //     s2[j++] = '-';
    // }

    for (i=j=0; (i + 2) <= strlen(s1); i = i + step)
    {
        for (int k = 0; k <= (s1[i + 2] - s1[i]); j++, k++)
        {

            if (j > 0) // handling not to dublicate b in a-b-c
            {
                if (s2[--j] == s1[i] + k)
                {

                    continue;
                }
                else
                {
                    ++j;
                }
            }

            s2[j] = s1[i] + k;
        }
    }
    printf("j=%d i=%d\n", j, i);

    s2[j] = '\0';
}

int main(void)
{
    char s1[LIMIT] = "a-gA-Z";
    char s2[LIMIT];
    expand(s1, s2);
    printf("%s\n", s2);
}
