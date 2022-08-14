#include <stdio.h> 
#include <stdlib.h>
#include "choise_map.h"
#include "array_fxn.h"


// --------------------------------------------------------------------------------------


int main(){

    int array_size;
    printf("Enter array size : ");
    scanf("%d", &array_size);

    // creating the array
    int arr[array_size];
    int* array = create_array(arr, array_size);

    int choise = get_array_choise();
    perform_array_fxn(choise, array, array_size);
    
    return 0;

}  