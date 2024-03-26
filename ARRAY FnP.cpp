#include <stdio.h>

// Function to input elements into the array
int create(int arr[100], int *size) {
    printf("Enter the number of elements you want to enter: ");
    scanf("%d", size);
    for (int i = 0; i < *size; i++) {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    return 0;
}

// Function to display elements of the array
int display(int arr[], int size) {
    printf("Array contains: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0; 
}

// Function to insert an element at the beginning of the array
int insertion_beg(int arr[], int *size) {
    if (*size >= 100) { // Check against the capacity of the array
        printf("Array is full. Insertion at the beginning is not possible.\n");
        return 0;
    }

    int beg;
    printf("Enter the element to insert at the beginning: ");
    scanf("%d", &beg);

    // Shift elements to the right to make space for the new element
    for (int i = *size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element at the beginning
    arr[0] = beg;

    // Increase the size of the array
    (*size)++;

    printf("Element inserted at the beginning successfully.\n");
    return 0;
}

// Function to insert an element at the end of the array
int insertion_end(int arr[], int *size) {
    if (*size >= 100) { // Check if array is full
        printf("Array is full. Insertion at the end is not possible.\n");
        return 0;
    }
	
    int end;
    printf("Enter the element to insert at the end: ");
    scanf("%d", &end);
    arr[*size] = end; // Inserting the element at the end
    (*size)++;   	//increasing the size of array
    printf("Element inserted at the end successfully.\n");
    return 0;
}

// Function to insert an element at a particular location in the array
int insertion_PL(int arr[], int *size, int *loc) {
    if (*size >= 100) { // Check if array is full
        printf("Array is full. Insertion is not possible.\n");
        return 0;
    }
	
    int element;
    printf("Enter the location you want to insert the element: ");
    scanf("%d", loc);
    printf("Enter the element you want to insert: ");
    scanf("%d", &element);
	
    if (*loc < 0 ) {
        printf("Invalid location. Insertion is not possible.\n");
        return 0;
    }

    // Shift elements to the right to make space for the new element
    for(int i = *size; i > *loc; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element at the specified location
    arr[*loc] = element;

    (*size)++;
    printf("Element successfully inserted.\n");
    return 0;
}

// Function to insert an element after a specified element in the array
int insertion_AE(int arr[], int *size) {
    if (*size >= 100) { // Check if array is full
        printf("Array is full. Insertion is not possible.\n");
        return 0;
    }

    int element, ae;
    printf("Enter the element you want to insert: ");
    scanf("%d", &element);
    printf("Enter the element after which you want to insert: ");
    scanf("%d", &ae);
    for (int i = 0; i < *size; i++) 
	{
        if (arr[i] == ae) {
            // Shift elements to the right to make space for the new element
            for (int j = *size; j > i + 1; j--) {
                arr[j] = arr[j - 1];
            }

            // Insert the new element after the specified element
            arr[i + 1] = element;

            (*size)++;
            printf("Element successfully inserted after %d.\n", ae);
            return 0;
        }
       
     }
      printf("Element %d not found in the array. Insertion is not possible.\n", ae);
		return 0;
}

// Function to insert an element before a specified element in the array
int insertion_BE(int arr[], int *size) 
{
    if (*size >= 100) { // Check if array is full
        printf("Array is full. Insertion is not possible.\n");
        return 0;
    }

    int element, be;
    printf("Enter the element you want to insert: ");
    scanf("%d", &element);
    printf("Enter the element before which you want to insert: ");
    scanf("%d", &be);
    for (int i = 0; i < *size; i++) 
	{
        if (arr[i] == be) {
            // Shift elements to the right to make space for the new element
            for (int j = *size; j > i + 1; j--) {
                arr[j] = arr[j - 1];
            }

            // Insert the new element after the specified element
            arr[i - 1] = element;

            (*size)++;
            printf("Element successfully inserted before %d.\n", be);
            return 0;
        }
        
     }
     printf("Element %d not found in the array. Insertion is not possible.\n", be);
		return 0;
}

// Function to delete an element from the beginning of the array
int deletion_beg(int arr[],int *size)
{
	 if (*size <= 0) 
	{ // Check if array is empty
        printf("Array is empty. Deletion is not possible.\n");
        
    }
    for (int i = 0; i < *size - 1; i++)
	 {
        arr[i] = arr[i + 1];
    }

    // Decrease the size of the array
    (*size)--;

    printf("Element at the beginning deleted successfully.\n");
    return 0;
}

// Function to delete an element from the end of the array
int deletion_end(int arr[],int *size)
{
	 if (*size <= 0) 
	{ // Check if array is empty
        printf("Array is empty. Deletion is not possible.\n");
        
    }
    (*size)--;   	//decreasing the size of array
    printf("Element deleted at the end successfully.\n");
    return 0;
}

// Function to delete an element from a particular location in the array
int deletion_PL(int arr[],int*size,int *loc)
{
    
    if (*size <= 0) 
	{ // Check if array is empty
        printf("Array is empty. Deletion is not possible.\n");
        
    }
	printf("Enter the location you want to delete the element: ");
    scanf("%d", loc);

    if (*loc < 0) 
	{
        printf("Invalid location. Deletion is not possible.\n");
        return 0;
    }

    // Shift elements to the left to remove the specified element
    for (int i = *loc; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Decrease the size of the array
    (*size)--;

    printf("Element at location %d deleted successfully.\n", *loc);
    return 0;
}

// Function to delete a specified element from the array
int deletion_E(int arr[],int *size)
{
	if (*size <= 0) { // Check if array is empty
        printf("Array is empty. Deletion is not possible.\n");
        return 0;
    }

    int e;
    printf("Enter the element before which you want to delete: ");
    scanf("%d", &e);

    for (int i = 0; i < *size; i++) {
        if (arr[i] == e) {
            // Shift elements to the left to remove the specified element
            for (int j = i; j < *size - 1; j++) {
                arr[j] = arr[j + 1];
            }

            // Decrease the size of the array
            (*size)--;

            printf("Element %d deleted successfully.\n", e);
            return 0;
        }
    }

    printf("Element %d not found in the array. Deletion is not possible.\n", e);
    return 0;
}

// Function to delete an element after a specified element in the array
int deletion_ae(int arr[],int *size)
{
	if (*size <= 0) { // Check if array is empty
        printf("Array is empty. Deletion is not possible.\n");
        return 0;
    }

    int ae;
    printf("Enter the element before which you want to delete: ");
    scanf("%d", &ae);

    for (int i = 0; i < *size; i++) {
        if (arr[i] == arr[ae+1])
		 {
            // Shift elements to the left to remove the specified element
            for (int j = i; j < *size ; j++) {
                arr[j] = arr[j + 1];
            }

            // Decrease the size of the array
            (*size)--;

            printf("Element %d deleted successfully.\n", ae);
            return 0;
        }
    }

    printf("Element %d not found in the array. Deletion is not possible.\n", ae);
    return 0;

}

// Function to delete an element before a specified element in the array
int deletion_be(int arr[],int *size)
{
		if (*size <= 0) { // Check if array is empty
        printf("Array is empty. Deletion is not possible.\n");
        return 0;
    }

    int ae;
    printf("Enter the element before which you want to delete: ");
    scanf("%d", &ae);

    for (int i = 0; i < *size; i++) {
        if (arr[i] == ae)
		 {
            // Shift elements to the left to remove the specified element
            for (int j = i; j < *size ; j++) {
                arr[j] = arr[j + 1];
            }

            // Decrease the size of the array
            (*size)--;

            printf("Element %d deleted successfully.\n", ae);
            return 0;
        }
    }

    printf("Element %d not found in the array. Deletion is not possible.\n", ae);
    return 0;

}


int main() {
    int choice;
    int size = 0;
    int loc;
 
    int arr[100];

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
    	printf("\n11. deletion of an element");
    	printf("\n12. deletion after an element");
     	printf("\n13. deletion before an element");
    	printf("\n14. Exit ");
    	
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        if (choice <=15 && choice > 0) {
            switch(choice) {
                case 1:
                    create(arr, &size);
                    
                    break;
                case 2:
                    display(arr, size);
                    break;
                case 3:
                    insertion_beg(arr, &size);
                    break;
                    
                case 4:
                    insertion_end(arr,&size);
					break;
					
                case 5:
					insertion_PL(arr,&size,&loc);
					break;
				
				case 6:
					insertion_AE(arr,&size);
					break;
				
				case 7:
					insertion_BE(arr, &size);
					break;
				
				case 8:
					deletion_beg(arr,&size);
					break;
				
				case 9:
					deletion_end(arr,&size);
					break;
				
				case 10:
					deletion_PL(arr,&size,&loc);
					break;
				
				
				
				case 11:
					deletion_E(arr,&size);
					break;
				
				case 12:
					deletion_ae(arr,&size);
					break;
				
				case 13:
					deletion_be(arr,&size);
					break;
				
				case 14:
                    printf("GOODBYE\n");
                    break;
                
                
            }
        } else {
            printf("INVALID CHOICE\n");
        }

    } while (choice != 14);

    return 0;
}

