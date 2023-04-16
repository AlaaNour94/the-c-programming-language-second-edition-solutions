/*
Exercise 4-13. Write a recursive version of the function reverse
reverses the string s in place.
*/

#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main()
{
    char s[] = "!dlroW olleH";
    printf("%s\n", s);
    reverse(s);
    printf("%s\n", s);
}

void reverse(char s[])
{

    static int i = 0;
    static int j = 0;

    if (j == 0 && i==0){
        j = strlen(s)-1;
    }

    if (j <= i)
    {
        return;
    }
    char temp = s[i];
    s[i++] = s[j];
    s[j--] = temp;
    return reverse(s);
}