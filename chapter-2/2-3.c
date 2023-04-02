
/*
Write the function htoi(s), which converts a string of hexa-
decimal digits (including an optional Ox or ox) into its equivalent integer value.
The allowable digits are 0 through 9, a through f, and A through F.

*/

#include <stdio.h>
#include <ctype.h>
int htoi(char s[])
{
    int i, value, res = 0;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'x' || s[i] == 'X')
        {
            continue;
        }

        if (isdigit(s[i]))
        {
            value = s[i] - '0';
        }
        else
        {
            value = tolower(s[i]) - 'a' + 10;
        }

        res = (res * 16) + value;
    }

    return res;
}
int main(void)
{
    printf("%d\n", htoi("0x7DE"));
    printf("%d\n", htoi("7DE"));
    printf("%d\n", htoi("B4"));
    printf("%d\n", htoi("80"));
}
