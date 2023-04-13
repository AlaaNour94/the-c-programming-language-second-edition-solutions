
/*
Exercise 4-2. Extend atof to handle scientific notation of the form
123.45e-6
where a floating-point number may be followed by e or E and an optionally
signed exponent
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LIMIT 100

double atof(char s[]);

int main()
{
      printf("%f\n", atof("1542"));
    printf("%f\n", atof("-10.5e-1"));
}

double atof(char s[])
{
    int i, power, ex, ex_sign, sign;
    double val;
    i= 0;
    ex_sign = sign = 1;

    if (s[i] == '-'){
        sign = -1;
        i++;
    }

    for (val=0; isdigit(s[i]); i++)
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

    

    if (s[i]== 'e' || s[i]=='E'){
        i++;
    }

    if (s[i] == '-'){
        ex_sign = -1;
        i++;
    }

    for (ex=0; s[i] != '\0'; i++){
        ex = ex * 10 + (s[i] - '0');
    }

    while (ex>0){
        if (ex_sign ==1){
            power /= 10.0; 
        } else {
            power *= 10.0;
        }
        ex--;
    }

    return sign * val / power;
}
