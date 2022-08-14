#include "choise_map.h"
#include <stdio.h>
#include <stdlib.h>

// --------------------------------------------------------------------------------------

// searching techniques - linear search, binary search
// sorting techniques - bubble sort

void print_array_menu(){
    printf(
        "    ==== Data Structures (Arrays) ==== \n \
         Choose 0 for exiting the program \n \
         Choose 1 for inserting elements in the array \n \
         Choose 2 for deleting elements from the array \n \
         Choose 3 for find any element in the array \n \
         Choose 4 for sorting the array \n \
         Enter choise : "
    );
}

int get_array_choise(){
    int choise;
    print_array_menu();
    scanf("%d", &choise);
    return choise;
}

int get_array_search_choise(){
    int choise;
    printf("ENter 1 for linear search and 2 for binary search : ");
    scanf("%d", &choise);
    return choise;
}

int get_array_sort_choise(){
    int choise;
    printf("Enter 1 for ascending order and -1 for descending order : ");
    scanf("%d", &choise);
    return choise;
}

// --------------------------------------------------------------------------------------

// fxn to map choises with array operations

void perform_array_fxn(int choise, int* array, int array_size){

    // exiting the program if choise == 0
    if (choise == 0){exit(0);}
    
    // inserting elements an array if choise == 1
    else if (choise == 1){
        int index, element;
        printf("enter the position of element (index) to insert (0-%d) : ", array_size - 1);
        scanf("%d", &index);
        printf("Enter element to insert at index %d : ", index);
        scanf("%d", &element);
        insert_array_element(array, array_size, element, index);
    } 
    
    // deleting elements from an array if choise == 2
    else if (choise == 2){
        int index;
        printf("enter the position of element (index) to delete (0-%d) : ", array_size - 1);
        scanf("%d", &index);
        delete_array_element(array, array_size, index);
    }

    // finding elements in an array if choise == 3
    else if (choise == 3){
        int array_search_choise = get_array_search_choise();
        int element;
        int sorted;
        int* sorted_array;
        printf("Enter element to find : ");
        scanf("%d", &element);
        switch (array_search_choise){
            case 1:
                linear_search(array, array_size, element);
                break;
            case 2:
                sorted = get_array_sort_choise();
                if (sorted == 1){
                    binary_search(array, array_size, element);
                }else{
                    sorted_array = bubble_sort(array, array_size, 1);
                    binary_search(sorted_array, array_size, element);
                }
                break;
            default:
                printf("Wrong choise, please try again");
                break;
            }
    }

    // sorting the array if choise == 4
    else if (choise == 4){
        int sort_choise = get_array_sort_choise();
        int* sorted_arr = bubble_sort(array, array_size, sort_choise);
        if (sort_choise == 1){
            printf("After sorting in ascending order ");
        } else{
            printf("After sorting in descending order ");
        }
        printarray(sorted_arr, array_size);
    }
    
}