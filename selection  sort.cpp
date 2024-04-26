#include <stdio.h>

// Function to perform selection sort on an array
int selectionSort(int arr[], int max) {
    int i, loc, small, tmp;
    
    // iterate through the array
    for (i = 0; i < max - 1; i++) {
        small = i; // Assume the current index has the smallest value
        
        // Find the index of the smallest element in the unsorted part of the array
        for (loc = i + 1; loc < max; loc++) {
            if (arr[loc] < arr[small]) {
                small = loc;
            }
        }
        
        // Swap the smallest element with the current element 
        tmp = arr[small];
        arr[small] = arr[i];
        arr[i] = tmp;
        
        // Printing current step of the sorting process
        printf("\nStep %d: ", i + 1);
        for (loc = 0; loc < max; loc++) {
            printf("%d ", arr[loc]); 
        }
        printf("\n");
    }
}

int main() {
    int max;
    printf("Enter the number of elements: ");
    scanf("%d", &max);
    
    int arr[max];
    int i;
    
    // Input the elements of the array from the user
    for (i = 0; i < max; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    // Display the original array
    printf("Original array: ");
    for (i = 0; i < max; i++) {
        printf("%d ", arr[i]);
    }
    
    
    selectionSort(arr, max);
    
    // Display the sorted array
    printf("\nSorted array: ");
    for (i = 0; i < max; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
