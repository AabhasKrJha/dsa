#include "array_fxn.h"
#include <stdio.h>

// fxn to print array
void printarray(int *arr, int arr_size){  
    printf("Elements of array are : ");  
    for(int index = 0; index < arr_size; index++)  {  
        printf("%d ", arr[index]);  
    }  
    printf("\n");
}


// fxn to crrate an array
int* create_array(int *arr, int arr_size){
    for (int index = 0; index < arr_size; index++){
        printf("Enter element %d : ", index);
        scanf("%d", &arr[index]);
    }
    printf("Created an array with %d elements. \n", arr_size);
    printarray(arr, arr_size);
    return arr;
}


// fxn to insert an element in an array at a given position
int* insert_array_element(int *arr, int arr_size, int element, int insert_index){
    if (insert_index == arr_size - 1){
        arr[arr_size] = element;
    } else {
        for (int index = arr_size ; index > insert_index; index--){
            arr[index] = arr[index - 1];
        }
        arr[insert_index] = element;
    }
    arr_size++;
    printf("AFTER INSERTING ");
    printarray(arr, arr_size);
    return arr;
}


// fxn to delete an element from an array at a given position
int* delete_array_element(int* arr, int arr_size, int delete_index){
    for (int index = delete_index; index > arr_size-1; index++){
        arr[index] = arr[index + 1];
    }
    arr_size-- ;
    printf("AFTER DELETING ");
    printarray(arr, arr_size);
    return arr;
}


// fxn for linear serach in an array
void linear_search(int* arr, int arr_size, int element){
    int found_flag = 0;
    for (int index = 0; index < arr_size; index++){
        if (arr[index] == element){
            printf("%d element found at index %d", element, index);
            found_flag = 1;
            break;
        }
    }
    if (found_flag == 0){
        printf("Element not found in array.");
    }
}


// fxn to check if an arrayy is sorted (ascending order)
int if_array_sorted(int* arr, int arr_size){
    int sorted = 1;
    for (int index = 0; index < arr_size - 1; index++){
        if(arr[index] > arr[index + 1]){
            sorted = 0;
            break;
        }
    }
    return sorted;
}


// fxn for bubble sort in an array
int* bubble_sort(int* arr, int arr_size, int order){
    for (int index = 0; index < arr_size; index++){
        for (int sort_index = 0; sort_index < arr_size - index - 1; sort_index++){
            if (order == 1){
                if (arr[sort_index] > arr[sort_index + 1]){
                    int temp_var = arr[sort_index];
                    arr[sort_index] = arr[sort_index + 1];
                    arr[sort_index + 1] = temp_var;
                }
            } else{
                if (arr[sort_index] < arr[sort_index + 1]){
                    int temp_var = arr[sort_index];
                    arr[sort_index] = arr[sort_index + 1];
                    arr[sort_index + 1] = temp_var;
                }
            }
        }   
    }
    return arr;
}


// fxn for binary search in an array
void binary_search(int* arr, int arr_size, int element){
    int found_flag = 0;
    int high_index = arr_size - 1;
    int low_index = 0;
    while (high_index >= low_index){
        int mid_index = (high_index + low_index)/2;
        int mid_element = arr[mid_index];
        if (mid_element == element){
            found_flag = 1;
            printf("%d element found at index %d", element, mid_index);
            break;
        } else if (mid_element > element){
            high_index = mid_index - 1;
        } else if (mid_element < element){
            low_index = mid_index + 1;
        }
    }
    if (found_flag == 0){
        printf("Element not found in array.");
    }
}