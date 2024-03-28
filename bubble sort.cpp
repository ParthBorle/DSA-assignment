#include <stdio.h>

int swap(int *a, int *b) { // swaping function if elements are in wrong order
    int temp = *a;
    *a = *b;
    *b = temp;
}

int printArray(int arr[], int size) {  // printing array function
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int bubbleSort(int arr[], int size) {		// function of bubble sort
    int MAX_SIZE = size;
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        int lb = 0;
        int ub = MAX_SIZE  - 1;
        for (int j = lb; j < ub; j++) {
            // Compare  elements
            if (arr[j] > arr[j + 1]) {
                // Swap them if they are in the wrong order
                swap(&arr[j], &arr[j + 1]);

                // Print the current state of the array
                printf("Step ");
                printArray(arr, size);
                
            }
        }
    }
}

int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[100]; // Assuming maximum size of array is 100

    printf("Enter the elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original Array: ");			//calling the functions
    printArray(arr, size);              

    bubbleSort(arr, size);

    printf("Sorted Array: ");
    printArray(arr, size);

    return 0;
}

