/*
Exercise 5-10. Write the program expr, which evaluates a reverse Polish
expression from the command line, where each operator or operand is a separate
argument. For example,
exper 2 3 4 + *   evaluates 2 x (3+4).
*/

#include <stdio.h>
#include <ctype.h>

#define STACKLEN 1000
#define NUMBER 1
#define OPERATOR 0

void push(double c);
double pop();
char arg_type(char *arg);
double atof(char s[]);

int main(int argc, char *argv[])
{
    double num1;
    char type;
    while (--argc)
    {
        ++argv;
        type = arg_type(*argv);
        switch (type)
        {
        case NUMBER:
            push(atof(*argv));
            break;
        case '*':
            push(pop() * pop());
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            num1 = pop();
            push(pop() - num1);
            break;
        case '/':
            num1 = pop();
            push(pop() / num1);
            break;
        };
    }
    printf("%f\n", pop());
    return 0;
}

double stack[STACKLEN];
int p = 0;

void push(double c)
{
    stack[p++] = c;
}

double pop()
{
    return stack[--p];
}

char arg_type(char *arg)
{
    return isdigit(arg[0]) ? NUMBER : arg[0];
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
