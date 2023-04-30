

#include <stdio.h>
#include <ctype.h>
int getch(void);
void ungetch(int);

int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))
    {
        ;
    }

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
    {
        if (!isdigit(c = getch()))
        {
            ungetch(c);
            ungetch(sign == 1 ? '+' : '-');
            return 0;
        }
        c = getch();
    }

    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = (*pn * 10) + (c - '0');
    }

    *pn = *pn * sign;

    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}