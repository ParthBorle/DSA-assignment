#include <stdio.h>

int inputArray(int a[], int *ub) {
    
    for (int i = 0; i < *ub; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    return 0;
}

int displayArray(int a[], int ub) {
    printf("Array: ");
    for (int i = 0; i < ub; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

int searchValue(int a[], int ub, int value) {
     for (int i = 0 ;i < ub; i++){
    
        if (a[i] == value){
             printf("%d\n",a[i]);
            printf("Search successful\nelement %d found in %d index \n", value,i);
            break;
            break;
        }
    }
    return 0;
}


int main() {
    int a[1000];
    int ub, value;
	int lb=0;
    printf("Enter the number of elements: ");
    scanf("%d",&ub);
    // Input array elements
    inputArray(a, &ub);

    // Display the array
    displayArray(a, ub);

    // Input the value to be searched
    printf("Enter the value to be searched: ");
    scanf("%d",&value);

    // Search for the value
    searchValue(a, ub, value);
return 0;
}


