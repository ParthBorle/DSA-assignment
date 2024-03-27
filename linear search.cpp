#include <stdio.h>



int main() {
    int a[100];
    int ub, value;
	int lb=0;
    // Input array elements
    printf("Enter the number of elements: ");
    scanf("%d", &ub);
    
    for (int i = 0; i < ub; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    //display values
    printf("Array: ");
    for (int i = 0; i < ub; i++) {
        printf("%d ", a[i]);
    }
  

    // Input the value to be searched
    printf("Enter the value to be searched: ");
    scanf("%d", &value);

    //search for values.
    for (int i = 0 ;i < ub; i++){
        if (a[i] == value){
            printf("%d\n",a[i]);
            printf("Element %d found at index %d \n", value,i);
            break;
        }
    }
    return 0;
}
