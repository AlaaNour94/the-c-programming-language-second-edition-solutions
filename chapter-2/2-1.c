
/*
Write a program to determine the ranges of char, short,
int and long variables, both signed and unsigned, by printing appropriate
values from standard headers and by direct computation. Harder if you com-
pute them: determine the ranges of the various floating-point types. 0
*/

#include <stdio.h>
#include <limits.h>
int main(void)
{
    printf("\nchar:\n");
    printf("Size of char: %d bits\n", CHAR_BIT);
    printf("Maximum value of char: %d\n", CHAR_MAX);
    printf("Minimum value of char: %d\n", CHAR_MIN);
    printf("Maximum value of signed char: %d\n", SCHAR_MAX);
    printf("Minimum value of signed char: %d\n", SCHAR_MIN);
    printf("Maximum value of unsigned char: %u\n", UCHAR_MAX);
    printf("\nint:\n");
    printf("Maximum value of int: %d\n", INT_MAX);
    printf("Minimum value of int: %d\n", INT_MIN);
    printf("Maximum value of unsigned int: %u\n", UINT_MAX);
    printf("\nlong:\n");
    printf("Maximum value of long: %ld\n", LONG_MAX);
    printf("Minimum value of long: %ld\n", LONG_MIN);
    printf("Maximum value of unsigned long: %lu\n", ULONG_MAX);
    printf("\nshort:\n");
    printf("Maximum value of short: %d\n", SHRT_MAX);
    printf("Minimum value of short: %d\n", SHRT_MIN);
    printf("Maximum value of unsigned short: %u\n", USHRT_MAX);
    return 0;
}
