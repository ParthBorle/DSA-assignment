#include <stdio.h>

int main() {
    int max;
    int h;
    printf("Enter the number of elements: ");
    scanf("%d", &max);

    int arr[max]; 

    printf("Enter the elements: ");
    for (int i = 0; i < max; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original Array: ");
    for (int i = 0; i < max; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Bubble sort
    for (int i = 0; i < max - 1; i++) {
        for (int j = 0; j < max - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // Print the current state of the array
                
                printf("Step : " );
                for (int k = 0; k < max; k++) {
                    printf("%d ", arr[k]);
                }
                printf("\n");
            }
        }
    }

    printf("Sorted Array: ");
    for (int i = 0; i < max; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

