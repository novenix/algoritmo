#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
int main(void){
    long long x = 999;
    char str[999];
    sprintf(str, "%lu", x);
    printf("%s\n", str);
}

