#include <stdio.h>

int binarySearch(int arr[], int no_elements, int key) {
    int lb = 0, ub = no_elements - 1;
    while (lb <= ub) {
        int mid = (lb + ub) / 2;
        if (key == arr[mid]) {
            return mid;
        } else if (key < arr[mid]) {
            ub = mid - 1;
        } else if (key > arr[mid]) {
            lb = mid + 1;
        }
    }
    
}

int main() {
    int MAX_SIZE, i, key, no_elements,choice;
    
    printf("Enter the size of the array: ");
    scanf("%d", &MAX_SIZE);

    printf("Do you want to enter the elements of the array? (1/0): ");
    scanf(" %d", &choice); 

    if (choice == 1) {
        printf("Enter the number of elements you want to enter: ");
        scanf("%d", &no_elements);

        if (no_elements <= 0 || no_elements > MAX_SIZE) {
            printf("Invalid size!\n");
            return 0;
        }

        int arr[MAX_SIZE];

        printf("Enter the elements of the array:\n");
        for (i = 0; i < no_elements; i++) {
            printf("Element %d: ", i + 1);
            scanf("%d", &arr[i]);
        }

        // Sorting the array using Bubble Sort
        for (int i = 0; i < no_elements - 1; i++) {
            for (int j = 0; j < no_elements - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        printf("Sorted Array: ");
        for (i = 0; i < no_elements; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("Enter the element to search: ");
        scanf("%d", &key);

        int result = binarySearch(arr, no_elements, key);

        if (result == -1) {
            printf("Element not found\n");
        } else {
            printf("Element found at index %d\n", result);
        }
    } else if (choice ==0) {
        printf("Thank you!\n");
    } else {
        printf("Invalid input!\n");
    }

    return 0;
}

