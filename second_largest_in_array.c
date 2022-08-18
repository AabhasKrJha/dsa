#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[5] = {968, 456, 4562,35 , 6};
    int big, small;
    big = arr[0];
    int temp_var;

    for (int i = 0; i < 5; i++){
        if (arr[i] > big){
            temp_var = big;
            big = arr[i];
            small = temp_var;
        }
        
    }

    printf("%d    %d", big, small);
    
    return 0;
}
