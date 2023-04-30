#include <stdio.h>

void strcat_ptr(char *, char *);

int main(void)
{
    char s[100] = "AlaaNour";
    char t[] = "Alaa";
    strcat_ptr(s, t);
    printf("%s\n", s);
}

void strcat_ptr(char *s, char *t)
{
    while (*s)
    {
        s++;
    }
    while (*s++ = *t++)
        ;
}
