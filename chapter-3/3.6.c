
/*
Write a version of i toa that accepts three arguments instead of
two. The third argument is a minimum field width; the converted number must
be padded with blanks on the left if necessary to make it wide enough
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LIMIT 100

void reverse(char s[])
{
    int start, end, temp;
    start = 0;
    end = strlen(s) - 1;

    while (start < end)
    {
        temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
    }
}
void itoa(int n, char s[], int padding)
{
    int i, j, sign;
    i = j = 0;

    if ((sign = n) < 0)
    {
        n = -n;
    }

    do
    {
        j = n % 10;
        s[i++] = j + '0';
    } while ((n = n / 10) > 0);

    if (sign < 0)
    {
        s[i++] = '-';
    }

    int p = padding - i;

    while (p>0){
        s[i++] = ' ';
        p--;
    }
    s[i] = '\0';
    reverse(s);
}

int main(void)
{
    int n = 6958;
    char s[LIMIT];
    int padding = 5;
    itoa(n, s, padding);
    printf("%s\n", s);

    int n2 = -6958;
    char s2[LIMIT];
    itoa(n2, s2, padding);
    printf("%s\n", s2);
}
