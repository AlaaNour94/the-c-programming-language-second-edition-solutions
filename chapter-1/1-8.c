#include <stdio.h>


int main(){

    int c, count;
    count = 0;

    while ((c=getchar()) != EOF){
        if (c == '\t' || c== '\n' || c== ' '){
            ++count;
        }
    }
    printf("Count is %d\n", count);
}