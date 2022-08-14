// ARRAY ALGORITHM FUNCTIONS

#ifndef ARRAY_FXN_H
#define ARRAY_FXN_H

// fxn to print array
void printarray(int *arr, int arr_size);

// fxn to crrate an array
int* create_array(int *arr, int arr_size);

// fxn to insert an element in an array at a given position
int* insert_array_element(int *arr, int arr_size, int element, int insert_index);

// fxn to delete an element from an array at a given position
int* delete_array_element(int* arr, int arr_size, int delete_index);

// fxn for linear serach in an array
void linear_search(int* arr, int arr_size, int element);

// fxn to check if an arrayy is sorted (ascending order)
int if_array_sorted(int* arr, int arr_size);

// fxn for bubble sort in an array
int* bubble_sort(int* arr, int arr_size, int order);

// fxn for binary search in an array
void binary_search(int* arr, int arr_size, int element);

#endif