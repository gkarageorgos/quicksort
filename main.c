#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int* a, int*b);
int split(int *arr, int first, int last);
void quickSort(int arr[], int first, int last);

int main(){
    int n; // Size of the array
    int max_value; // Maximum possible element in the array

    printf("Enter the size of the array:");
    scanf("%d", &n);

    printf("Enter the maximum possible element in the array:");
    scanf("%d", &max_value);

    // Set the seed for the rand() function based on the current time
    srand(time(0));

    // Create and generate random integers for the array
    int array[n];
    for (int i = 0; i < n; i++) {
        array[i] = rand() % max_value; // Generate a random number in the range [0, max_value-1]
    }

    printf("Random integer array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    quickSort(array, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }


    return 0;
}


void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int split(int *A, int first, int last){
    int x = A[first];
    int splitPoint = first;
    for (int i = first + 1; i <= last; i++){
        if (A[i] < x) {
            splitPoint += 1;
            swap(&A[splitPoint], &A[i]);
        }
    }
    swap(&A[first], &A[splitPoint]);
    return splitPoint;
}

void quickSort(int *arr, int first, int last){
    if (first < last) {
        int splitPoint = split(arr, first, last);
        quickSort(arr, first, splitPoint - 1);
        quickSort(arr, splitPoint + 1, last);
    }
}