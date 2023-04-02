
/*
Write a loop equivalent to the for loop without using && or ||

for (i=0; i<lim-1 && (c=getchar()) != '\n' && c!= EOF; i++)
    s[i] = c;

*/

#include <stdio.h>
#define LIMIT 200
int main(void)
{
    int lim = LIMIT;
    char s[LIMIT];
    int i = 0;
    char c;
    while (i < lim - 1)
    {
        c = getchar();

        if (c == '\n')
        {
            break;
        }
        else if (c == EOF)
        {
            break;
        }
        else
        {

            s[i++] = c;
        }
    }
    s[i] = '\0';
    printf("%s\n", s);
    return 0;
}
