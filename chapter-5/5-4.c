#include <stdio.h>
#include <string.h>

int strend(char *, char *);

int main(void)
{
    char s[] = "AlaaNourAlaa";
    char t1[] = "Alaa";
    char t2[] = "Hero";
    printf("%d\n",  strend(s, t1));
    printf("%d\n",  strend(s, t2));
}

int strend(char *s, char *t)
{
    size_t length = strlen(s) - strlen(t);
    // Move the s pointer until it has the same character length as t.
    s += length;
   
    while (*s && (*s++ == *t++))
        ;
    return *s == '\0' ? 1 : 0;
}
