#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int choice;
    int size = 0;
    int *ptr = NULL;
    int arr[MAX_SIZE];

    ptr = arr;

    // Menu-driven program
    do {
        printf("\n----------------------------------------");
        printf("\n                MENU                  ");
        printf("\n--------------------------------------");
        printf("\n1. Enter the Elements of the array ");
        printf("\n2. Display the array ");
        printf("\n3. Insertion at the beginning ");
        printf("\n4. Insertion at end");
        printf("\n5. Insertion at a particular location");
        printf("\n6. Insertion after an element");
        printf("\n7. Insertion before an element");
        printf("\n8. Deletion at beginning");
        printf("\n9. Deletion at end");
        printf("\n10. Deletion at a particular location");
        printf("\n11. Deletion of an element");
        printf("\n12. Deletion after an element");
        printf("\n13. Deletion before an element");
        printf("\n14. Exit ");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("Enter the number of elements you want to enter: ");
                scanf("%d", &size);
                if (size > MAX_SIZE ) {
                    printf("Invalid size.\n");
                    break;
                }
                printf("Enter the elements: ");
                for (int i = 0; i < size; i++) {
                    scanf("%d", ptr + i);
                }
                printf("Elements inserted successfully.\n");
                break;
            }
            case 2: {
                if (size == 0) {
                    printf("Array is empty.\n");
                    break;
                }
                printf("Array contains: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", *(ptr + i));
                }
                printf("\n");
                break;
            }
            case 3: {
                
                int beg;
                printf("Enter the element to insert at the beginning: ");
                scanf("%d", &beg);
                // Shift elements to the right to make space for the new element
                for (int i = size; i > 0; i--) {
                    *(ptr + i) = *(ptr + i - 1);
                }
                // Insert the new element at the beginning
                *ptr = beg;
                size++;
                printf("Element inserted at the beginning successfully.\n");
                break;
            }
            case 4: {
                if (size >= MAX_SIZE) {
                    printf("Array is full. Insertion at the end is not possible.\n");
                    break;
                }
                int end;
                printf("Enter the element to insert at the end: ");
                scanf("%d", &end);
                *(ptr + size) = end; // Inserting the element at the end
                size++; // Increasing the size of the array
                printf("Element inserted at the end successfully.\n");
                break;
            }
            case 5: {
                if (size >= MAX_SIZE) {
                    printf("Array is full. Insertion is not possible.\n");
                    break;
                }
                int element;
                int loc;
                printf("Enter the location you want to insert the element: ");
                scanf("%d", &loc);
                printf("Enter the element you want to insert: ");
                scanf("%d", &element);
                if (loc < 0 || loc > size) {
                    printf("Invalid location. Insertion is not possible.\n");
                    break;
                }
                // Shift elements to the right to make space for the new element
                for (int i = size; i > loc; i--) {
                    *(ptr + i) = *(ptr + i - 1);
                }
                // Insert the new element at the specified location
                *(ptr + loc) = element;
                size++;
                printf("Element successfully inserted.\n");
                break;
            }
            case 6: {
                if (size >= MAX_SIZE) {
                    printf("Array is full. Insertion is not possible.\n");
                    break;
                }
                int element, ae;
                printf("Enter the element you want to insert: ");
                scanf("%d", &element);
                printf("Enter the element after which you want to insert: ");
                scanf("%d", &ae);
                for (int i = 0; i < size; i++) {
                    if (*(ptr + i) == ae) {
                        // Shift elements to the right to make space for the new element
                        for (int j = size; j > i + 1; j--) {
                            *(ptr + j) = *(ptr + j - 1);
                        }
                        // Insert the new element after the specified element
                        *(ptr + i + 1) = element;
                        size++;
                        printf("Element successfully inserted after %d.\n", ae);
                        break;
                    }
                }
                if (size == 0) {
                    printf("Element %d not found in the array. Insertion is not possible.\n", ae);
                }
                break;
            }
            case 7: {
                if (size >= MAX_SIZE) {
                    printf("Array is full. Insertion is not possible.\n");
                    break;
                }
                int element, be;
                printf("Enter the element you want to insert: ");
                scanf("%d", &element);
                printf("Enter the element before which you want to insert: ");
                scanf("%d", &be);
                for (int i = 0; i < size; i++) {
                    if (*(ptr + i) == be) {
                        // Shift elements to the right to make space for the new element
                        for (int j = size; j > i; j--) {
                            *(ptr + j) = *(ptr + j - 1);
                        }
                        // Insert the new element before the specified element
                        *(ptr + i) = element;
                        size++;
                        printf("Element successfully inserted before %d.\n", be);
                        break;
                    }
                }
                if (size == 0) {
                    printf("Element %d not found in the array. Insertion is not possible.\n", be);
                }
                break;
            }
            case 8: {
                if (size <= 0) {
                    printf("Array is empty. Deletion is not possible.\n");
                    break;
                }
                // Shift elements to the left to remove the first element
                for (int i = 0; i < size - 1; i++) {
                    *(ptr + i) = *(ptr + i + 1);
                }
                size--;
                printf("Element at the beginning deleted successfully.\n");
                break;
            }
            case 9: {
                if (size <= 0) {
                    printf("Array is empty. Deletion is not possible.\n");
                   
                    break;
                }
                // Decrease the size of the array to delete the last element
                size--;
                printf("Element at the end deleted successfully.\n");
                break;
            }
            case 10: {
                if (size <= 0) {
                    printf("Array is empty. Deletion is not possible.\n");
                    break;
                }
                int loc;
                printf("Enter the location you want to delete the element: ");
                scanf("%d", &loc);
                if (loc < 0 || loc >= size) {
                    printf("Invalid location. Deletion is not possible.\n");
                    break;
                }
                // Shift elements to the left to remove the specified element
                for (int i = loc; i < size - 1; i++) {
                    *(ptr + i) = *(ptr + i + 1);
                }
                // Decrease the size of the array
                size--;
                printf("Element at location %d deleted successfully.\n", loc);
                break;
            }
            case 11: {
                if (size <= 0) {
                    printf("Array is empty. Deletion is not possible.\n");
                    break;
                }
                int e;
                printf("Enter the element you want to delete: ");
                scanf("%d", &e);
                int found = 0;
                for (int i = 0; i < size; i++) {
                    if (*(ptr + i) == e) {
                        // Shift elements to the left to remove the specified element
                        for (int j = i; j < size - 1; j++) {
                            *(ptr + j) = *(ptr + j + 1);
                        }
                        size--;
                        found = 1;
                        printf("Element %d deleted successfully.\n", e);
                        break;
                    }
                }
                if (!found) {
                    printf("Element %d not found in the array. Deletion is not possible.\n", e);
                }
                break;
            }
            case 12: {
                if (size <= 0) {
                    printf("Array is empty. Deletion is not possible.\n");
                    break;
                }
                int ae;
                printf("Enter the element after which you want to delete: ");
                scanf("%d", &ae);
                int found = 0;
                for (int i = 0; i < size - 1; i++) {
                    if (*(ptr + i) == ae) {
                        // Shift elements to the left to remove the element after specified element
                        for (int j = i + 1; j < size - 1; j++) {
                            *(ptr + j) = *(ptr + j + 1);
                        }
                        size--;
                        found = 1;
                        printf("Element after %d deleted successfully.\n", ae);
                        break;
                    }
                }
                if (!found) {
                    printf("Element %d not found in the array or it is the last element. Deletion is not possible.\n", ae);
                }
                break;
            }
            case 13: {
                if (size <= 0) {
                    printf("Array is empty. Deletion is not possible.\n");
                    break;
                }
                int be;
                printf("Enter the element before which you want to delete: ");
                scanf("%d", &be);
                int found = 0;
                for (int i = 1; i < size; i++) {
                    if (*(ptr + i) == be) {
                        // Shift elements to the left to remove the element before specified element
                        for (int j = i - 1; j < size - 1; j++) {
                            *(ptr + j) = *(ptr + j + 1);
                        }
                        size--;
                        found = 1;
                        printf("Element before %d deleted successfully.\n", be);
                        break;
                    }
                }
                if (!found) {
                    printf("Element %d not found in the array. Deletion is not possible.\n", be);
                }
                break;
            }
            case 14: {
                printf("GOODBYE\n");
                break;
            }
            default: {
                printf("INVALID CHOICE\n");
            }
        }

    } while (choice != 14);

    return 0;
}

