/*
Rewrite the temperature conversion program of Section 1.2 to
use a function for conversion
*/

#include <stdio.h>

#define STEP 20
#define LOWER 0
#define UPPER 300

float f2c(float fahr){
    return 5 * (fahr-32) / 9;
}
int main(void)
{   
    float fahr = LOWER;
    while (fahr < UPPER){
        printf("Fahr = %.02f Celsius = %.02f\n", fahr, f2c(fahr));
        fahr += STEP;
    }
}