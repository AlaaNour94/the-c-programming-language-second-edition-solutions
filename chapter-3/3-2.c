
/*
Exercise 3-2. Write a function escape (s, t) that converts characters like
newline and tab into visible escape sequences like \n and \ t as it copies the
string t to s. Use a switch. Write a function for the other direction as well,
converting escape sequences into the real characters.
*/

#include <stdio.h>
#include <ctype.h>

void escape(char s[], char t[])
{
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;

        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        default:
            s[j++] = t[i];
            break;
        }
    }
    s[j] = '\0';
}

void descape(char s[], char t[])
{
    int i, j;
    int is_slash = 0;
    for (i = j = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
        case '\\':
            is_slash = 1;
            break;

        case 'n':
            if (is_slash)
            {
                s[j++] = '\n';
                is_slash = 0;
                break;
            }

        case 't':
            if (is_slash)
            {
                s[j++] = '\t';
                is_slash = 0;
                break;
            }
        default:
            s[j++] = t[i];
            break;
        }
    }
    s[j] = '\0';
}

int main(void)
{

    char s1[100];
    char s2[100];
    char t[] = "Alaa\nis\tHero";

    escape(s1, t);
    printf("Original One\n");
    printf("%s\n", t);
    printf("Excaped One\n");
    printf("%s\n", s1);

    printf("============Descape=============\n\n");
    descape(s2, s1);
    printf("Original One\n");
    printf("%s\n", s1);
    printf("Excaped One\n");
    printf("%s\n", s2);
}
