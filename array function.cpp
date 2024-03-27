#include <stdio.h>

int size = 0;
int max;
int arr[100];

int creat() {
    printf("Enter the max size of the array: ");
    scanf("%d", &max);
    printf("Enter the no. of elements you want to add in the array : ");
    scanf("%d", &size);
    if (size > max) {
        printf("The size is more than the limit of the array. \n");
    } else if (size == 0) {
        printf("NO MEMORY ALLOCATION\n");
    } else {
        printf("Enter elements: ");
        for (int i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
        }
    }
}

void display() {
    printf("Array contains: ");
    for (int i = 0; i < size; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

void insertionBeg() {
    if (size >= max) {
        printf("Array is Full\n");
    } else {
        int val;
        printf("Enter element you want to insert at the beginning: ");
        scanf("%d", &val);

        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = val;
        (size)++;
    }
}

void insertionEnd() {
    if (size >= max) {
        printf("Array is full\n");
    } else {
        int val;
        printf("Enter the element you want to insert at END: ");
        scanf("%d", &val);
        arr[size] = val;
        (size)++;
    }
}

void insertAP() {
    int pos;
    printf("Enter the Position to insert: ");
    scanf("%d", &pos);
    if (pos < 0 || pos > size) {
        printf("INVALID POSITION\n");
    } else if (size >= max) {
        printf("Array is Full\n");
    } else {
        int val;
        printf("Enter the element to insert: ");
        scanf("%d", &val);

        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = val;
        (size)++;
    }
}

int insertAE() {
    int element;
    printf("Enter the value after which you want to insert: ");
    scanf("%d", &element);

    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == element) {
            break;
        }
    }

    if (i == size) {
        printf("Element not found in Array\n");
    } else {
        int val;
        printf("Enter Element you want to insert: ");
        scanf("%d", &val);

        for (int j = size; j > i + 1; j--) {
            arr[j] = arr[j - 1];
        }
        arr[i + 1] = val;
        (size)++;
    };
}

void insertionBE() {
    int element;
    printf("Enter the element to be inserted Before: ");
    scanf("%d", &element);

    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == element) {
            break;
        }
    }

    if (i == size) {
        printf("Element not found in Array\n");
    } else {
        int val;
        printf("Enter Element: ");
        scanf("%d", &val);

        for (int j = size; j > i; j--) {
            arr[j] = arr[j - 1];
        }
        arr[i] = val;
        (size)++;
    }
}

void deleteionBEG() {
    if (size <= 0) {
        printf("ARRAY IS EMPTY\n");
    } else {
        for (int i = 0; i < size; i++) {
            arr[i] = arr[i + 1];
        }
        (size)--;
    }
}

void deleteionEND() {
    if (size <= 0) {
        printf("ARRAY IS EMPTY\n");
    } else {
        (size)--;
    }
}

void deleteionPos() {
    if (size <= 0) {
        printf("ARRAY IS EMPTY\n");
    } else {
        int pos;
        printf("Enter the position you want to delete:");
        scanf("%d", &pos);
        if (pos < 0) {
            printf("Invalid Position");
        } else {
            for (int i = pos - 1; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            (size)--;
        }
    }
}

void deleteELEMENT() {
    if (size <= 0) {
        printf("Array is EMPTY.\n");
    } else {
        int val;
        printf("Enter the element you want to delete: ");
        scanf("%d", &val);

        int i;
        for (i = 0; i < size; i++) {
            if (arr[i] == val) {
                for (int j = i; j < size - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                (size)--;
                break;
            }
        }

        if (i == size) {
            printf("Element not found in Array\n");
        }
    }
}

void deleteAE() {
    if (size <= 0) {
        printf("Array is empty. Deletion is not possible.\n");
    } else {
        int val;
        printf("Enter the element after which you want to delete: ");
        scanf("%d", &val);

        int i;
        for (i = 0; i < size; i++) {
            if (arr[i] == val) {
                for (int j = i + 1; j < size - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                (size)--;
                break;
            }
        }

        if (i == size) {
            printf("Element not found in Array\n");
        }
    }
}

void deleteBE() {
    if (size <= 0) {
        printf("Array is empty. Deletion is not possible.\n");
    } else {
        int val;
        printf("Enter the element before which you want to delete: ");
        scanf("%d", &val);

        int i;
        for (i = 0; i < size; i++) {
            if (arr[i] == val) {
                for (int j = i - 1; j < size - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                (size)--;
            }
        }

        if (i == size) {
            printf("Element not found in Array\n");
        }
    }
}

void deleteArray() {
    size = 0;
    printf("Array is now empty.\n");
}

int main() {
    int choice;
    do {
        printf("\n----------------------------------------");
        printf("\n                MENU                  ");
        printf("\n--------------------------------------");
        printf("\n1. Enter the Elements of the array ");
        printf("\n2. Display the array ");
        printf("\n3. Insert at the beginning ");
        printf("\n4. Insert at the End ");
        printf("\n5. Insert at the Particular location ");
        printf("\n6. Insert after a particular element ");
        printf("\n7. Insert before a particular element ");
        printf("\n8. Delete an element from the beginning ");
        printf("\n9. Delete an element at the END ");
        printf("\n10. Delete an element from the particular location ");
        printf("\n11. Delete an element by value ");
        printf("\n12. Delete an element by after any value ");
        printf("\n13. Delete an element by before any value ");
        printf("\n14. Delete entire Array ");
        printf("\n15. Exit ");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                creat();
                break;
            case 2:
                display();
                break;
            case 3:
                insertionBeg();
                break;
            case 4:
                insertionEnd();
                break;
            case 5:
                insertAP();
                break;
            case 6:
                insertAE();
                break;
            case 7:
                insertionBE();
                break;
            case 8:
                deleteionBEG();
                break;
            case 9:
                deleteionEND();
                break;
            case 10:
                deleteionPos();
                break;
            case 11:
                deleteELEMENT();
                break;
            case 12:
                deleteAE();
                break;
            case 13:
                deleteBE();
                break;
            case 14:
                deleteArray();
                break;
            case 15:
                printf("\nGOODBYE\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 15);

    return 0;
}

