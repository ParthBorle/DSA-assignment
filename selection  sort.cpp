#include <stdio.h>

int selectionSort(int arr[], int max) {
    int i, loc, small, tmp;
    
    for (i = 0; i < max - 1; i++) {
        small = i;
        for (loc = i + 1; loc < max; loc++) {
            if (arr[loc] < arr[small]) {
                small = loc;
            }
        }
        tmp = arr[small];
        arr[small] = arr[i];
        arr[i] = tmp;
    }
}

int main() {
    int max;
    printf("Enter no of elements: ");
    scanf("%d", &max);
    
    int arr[max];
    int i;
    
    for (i = 0; i < max; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    printf("Original array: ");
    for (i = 0; i < max; i++) {
        printf("%d ", arr[i]);
    }
    
    selectionSort(arr, max);
    
    printf("\nSorted array: ");
    for (i = 0; i < max; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

