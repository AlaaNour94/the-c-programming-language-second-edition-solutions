
/*
Exercise 3-5. Write the function i tob (n, s ,b) that converts the integer n
into a base b character representation in the string s. In particular,
itob ( n, s, 16) formats n as a hexadecimal integer in s.
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

void itob(int n, char s[], int b)
{
    int i, j, sign;
    i = 0;
    sign = n;
    if (n < 0){
        n = -n;
    }

    do {
        j = n % b;
        if (j>9){
            s[i++] = j - 10 + 'A';
        } else{
            s[i++] = j + '0';

        }
    }
    while ((n = n /b) >0);

    if (sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main(void)
{
    char s[LIMIT];
    itob(-151243, s, 2);
   printf("%s\n", s);
   itob(-151243, s, 16);
   printf("%s\n", s);
}
