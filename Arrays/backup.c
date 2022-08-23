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
    if (insert_index == arr_size ){
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
    for (int index = delete_index; index < arr_size-1; index++){
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

// changelogs

//[ENTER HERE]

// fixed bugs in insertion and deletion