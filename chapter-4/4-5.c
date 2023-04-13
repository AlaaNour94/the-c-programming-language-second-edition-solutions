
/*
Exercise 4-5. Add access to library functions like sin, exp, and pow. See
<math •h> in Appendix B, Section 4.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define LIMIT 100
#define NUMBER '0'

int getop(char s[]);

double atof(char s[]);

int getch();
void ungetch(int c);

double pop();
void push(double e);
double top();
void swap();
void duplicate();
void clear();

int main()
{
    int type;
    char s[LIMIT];
    double e2, temp;
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;

        case '+':
            push(pop() + pop());
            break;

        case '-':
            e2 = pop();
            push(pop() - e2);
            break;

        case '*':
            push(pop() * pop());
            break;

        case '/':
            e2 = pop();
            if (e2 != 0.0)
            {
                push(pop() / e2);
            }
            else
            {
                printf("Error: Division by Zero\n");
            }
            break;
        case 'e':
            push(exp(pop()));
            break;
        case '~':
            push(sin(pop()));
            break;
        case '^':
            e2 = pop();
            push(pow(pop(), e2));
            break;
        case 't':
            top();
            break;
        case 'd':
            duplicate();
            break;
        case 'c':
            clear();
            break;
        case 's':
            swap();
            break;
        case '\n':
            top();
            break;
        default:
            printf("Error: unknowen commnad %s\n", s);
            break;
        }
    }
    return 0;
}

double stack[LIMIT];
int sp = 0;

double pop()
{
    return stack[--sp];
}

void push(double e)
{
    stack[sp++] = e;
}

double top(){
    if (sp){
        printf("The top element is %0.3f\n",stack[sp-1]);
    }else {
        printf("Stack is empty\n");
    }
}
void swap(){
    double temp1 = pop();
    double temp2 = pop();
    push(temp1);
    push(temp2);
}
void clear(){
    do {
        stack[sp] = 0.0;
    } while (sp--);
}
void duplicate(){
    double temp = pop();
    push(temp);
    push(temp);
}
int getop(char s[])
{
    int c, i;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c; // not a number

    i = 0;

    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

double atof(char s[])
{
    int i, power, ex, ex_sign, sign;
    double val;
    i = 0;
    ex_sign = sign = 1;

    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }

    for (val = 0; isdigit(s[i]); i++)
    {
        val = val * 10.0 + (s[i] - '0');
    }
    if (s[i] == '.')
    {
        i++;
    }
    for (power = 1; isdigit(s[i]); i++)
    {
        val = val * 10.0 + (s[i] - '0');
        power *= 10;
    }

    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
    }

    if (s[i] == '-')
    {
        ex_sign = -1;
        i++;
    }

    for (ex = 0; s[i] != '\0'; i++)
    {
        ex = ex * 10 + (s[i] - '0');
    }

    while (ex > 0)
    {
        if (ex_sign == 1)
        {
            power /= 10.0;
        }
        else
        {
            power *= 10.0;
        }
        ex--;
    }

    return sign * val / power;
}

#define BUFF_LIMIT 100
int buffp = 0;
char buffer[BUFF_LIMIT];

int getch()
{
    return (buffp > 0) ? buffer[--buffp] : getchar();
}

void ungetch(int c)
{
    if (buffp > BUFF_LIMIT)
    {
        printf("ungetch: Too many characters\n");
    }
    buffer[buffp++] = c;
}