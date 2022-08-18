#include <stdio.h>
#include <stdlib.h>

char* infix;

int get_preference(int operator){
    return 0;
}

int main(){
    infix = calloc(1000000, sizeof(char));
    scanf("%s", infix);
    printf("%s", infix);
    free(infix);
    return 0;
}
