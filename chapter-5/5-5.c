#include <stdio.h>

void strncat_ptr(char *, char *, int);
void strncpy_ptr(char *, char *, int);
int strcmp_ptr(char *, char *, int);
int main(void)
{
    char s1[100] = "AlaaNour";
    char t1[] = "Alaa";
    strncat_ptr(s1, t1, 2);
    printf("%s\n", s1);

    char s2[10] = "";
    char t2[] = "Alaa";
    strncpy_ptr(s2, t2, 2);
    printf("%s\n", s2);

    char s3[] = "Alaa";
    char t3[] = "Alaa";
    printf("%d\n", strcmp_ptr(s3, t3, 3));
    char s4[] = "Al";
    char t4[] = "Alaa";
    printf("%d\n", strcmp_ptr(s4, t4, 3));
    char s5[] = "Alaa";
    char t5[] = "Al";
    printf("%d\n", strcmp_ptr(s5, t5, 3));
}

void strncat_ptr(char *s, char *t, int n)
{
    while (*s)
    {
        s++;
    }
    while (n-- && (*s++ = *t++))
        ;
}

void strncpy_ptr(char *s, char *t, int n)
{
    while (n-- && (*s++ = *t++))
        ;
}

int strcmp_ptr(char *s, char *t, int n)
{
    while (--n && *s && *s == *t)
    {
        s++;
        t++;
    }
    return *s - *t;
}
