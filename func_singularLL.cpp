#include<stdio.h>
#include<stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Function to create a new singular linked list
int creatlist(struct node *head) 
{
    head = NULL; // Initialize head pointer to NULL
    struct node *temp, *newnode;
    int choice = 1;
    int count = 1;

    // Loop to create the singular linked list
    while(choice) {
        newnode = (struct node*)malloc(sizeof(struct node)); // Allocate memory for new node
        
        // Inserting values
        newnode->next = NULL;
        printf("Enter the element you want to insert: ");
        scanf("%d", &(newnode->data));

        // Checking if the node is empty or not
        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        
        // Displaying the contents
        printf("Node %d contains Data = %d\nand address %u\n", count, temp->data,temp->next);
        printf("Do you want to continue (1/0)? ");
        scanf("%d", &choice);
        count++;
    }

    return 0;
}

// Function to display the singular linked list
int displaylist(struct node *head) {
    struct node *temp;

    if (head == NULL) {
        printf("NO NODE IS AVAILABLE\n");
    } else {
        temp = head;
        printf("Node contains: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}

// Function to insert a node at the beginning of the list
int insertion_beg(struct node *head){

    struct node *temp, *newnode;
    int choice = 1;
    int count = 1;
    while(choice){
        int num;
        printf("\n Enter the data : ");
        scanf("%d", &num);
        
        newnode= (struct node*)malloc(sizeof(struct node));
        newnode -> data = num;
        newnode -> next = head;
        head=newnode;
        //traversing to print the list                    
        temp=head;
        printf("\nDo you want to continue(1/0)? ");
        scanf("%d",&choice);
    }
    // Displaying the updated list
    temp=head;
    printf("List updated: ");
    temp!=NULL;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}

// Function to insert a node at the end of the list
int insertion_end(struct node *head)
{
    struct node *temp, *newnode;
    int choice = 1;
    
    while(choice){
        int num;
        printf("\n Enter the data : ");
        scanf("%d", &num);
        
        newnode= (struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        newnode->data=num;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        temp=newnode;

        printf("Do you want to continue(1/0)? ");
        scanf("%d",&choice);
    }
  
    // Displaying the updated list
    temp=head;
    printf("Node contains: ");
    while(temp!= NULL)
    {
        printf(" %d",temp->data);
        temp=temp->next;
    }
    return 0;
}

// Function to insert a node at a particular position
int insertion_pl(struct node *head)
{
    struct node *temp,*newnode,*prev;
    int pos ,num ,count;

    printf("Enter the position: ");
    scanf("%d",&pos);
    printf("Enter the value: ");
    scanf("%d",&num);
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    if (pos == 1) 
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        temp=head;
        count=0;
    }
    while (count!=pos-1)
    {
        prev=temp;
        count=count+1;
        temp=temp->next;
    }
    newnode->next=prev->next;
    prev->next=newnode;
    
    // Displaying the updated list
    temp=head;
    printf("List updated: ");
    temp!=NULL;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}

// Function to insert a node after a particular data
int insertion_AE(struct node *head)
{
    struct node *temp, *newnode;
    int element, num;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter the value after which to insert: ");
    scanf("%d", &num);

    temp = head;

    while (temp != NULL && temp->data != num) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in the list.\n");
        return 0;
    }

    printf("Enter the element to be inserted: ");
    scanf("%d", &element);

    newnode->data = element;
    newnode->next = temp->next;
    temp->next = newnode;

    // Displaying the updated list
    temp=head;
    printf("List updated: ");
    temp!=NULL;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}

// Function to insert a node before a particular data
int insertion_BE(struct node *head)
{
    struct node *temp, *prev, *newnode;
    int element, value;

    newnode = (struct node*)malloc(sizeof(struct node));
    
    printf("\nEnter the value before which to insert: ");
    scanf("%d", &value);

    temp = head;
    prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in the list.\n");
        return 0;
    }

    printf("Enter the element to be inserted: ");
    scanf("%d", &element);

    newnode->data = element;
    newnode->next = temp;

    if (prev == NULL) {
        // Inserting before the head node
        head = newnode;
    } else {
        prev->next = newnode;
    }

    // Displaying the updated list
    temp=head;
    printf("List updated: ");
    temp!=NULL;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}

// Function to delete a node from the beginning
int deletion_beg(struct node *head)
{
    struct node *temp;
    if(head==NULL) {
        printf("underflow");
    } else if(head->next==NULL)
    {
        temp=head;
        head=NULL;
        free(temp);
        printf("Node deleted");
    }
    else {
        temp = head;
        head = temp->next;
        free(temp);   
    }
    // Displaying the updated list
    temp =head;
    while(temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    return 0;
}

// Function to delete a node from the end
int deletion_end(struct node *head)
{
    struct node *temp,*prev;
    if(head==NULL)
	 {
        printf("underflow");
    } else if((*head)->next==NULL)
    {
        temp=head;
        head=NULL;
        free(temp);
        printf("Node deleted");
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        free(temp);
        prev->next=NULL;
    }
    
    // Displaying the updated list
    temp = head;
    while(temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    return 0;
}

// Function to delete a node at a particular location
int deletion_PL(struct node *head)
{
    struct node *temp,*prev;
    int value;
    printf("Enter the location at which you want to delete: ");
    scanf("%d",&value);
    if (value <= 0) 
    {
        printf("Invalid position.\n");
        return 0;
    }
    temp=head;
    int count=0;
    while (count!=value-1)
    {
        prev=temp;
        temp=temp->next;
        count=count+1;
    }
    prev->next=temp->next;
    free(temp);
    // Displaying the updated list
    temp = head;
    while(temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    return 0;
}

// Function to delete a node of particular element
int deletion_PE(struct node *head)
{
    struct node *temp,*prev;
    int value;
    printf("Enter the element which you want to delete: ");
    scanf("%d",&value);
    temp=head;
    prev=NULL;
    while(temp!=NULL && temp->data!=value)
    {
        prev= temp;
        prev=NULL;
    }
    if(temp==NULL)
    {
        printf("Element not found in list");
    }
    while(temp!=NULL)
    {
        if (temp->data==value)
        {
            prev->next=temp->next;
            free(temp);   
        }
        temp = head;
        while(temp != NULL) {
            printf(" %d", temp->data);
            temp = temp->next;
        }
    }
    return 0;
}

int main() 
{
    int choice;
    struct node *head=NULL;
    int count;
    int  num;
    
    // Menu-driven program loop
    do {
        printf("\n\n\n1. Enter for Creation of nodes\n");
        printf("2. Enter for Displaying nodes\n");
        printf("3. Enter to insert a node at beginning\n");
        printf("4. Enter to insert a node at the end\n");
        printf("5. Enter to insert a node at particular position\n");
        printf("6. Enter to insert a node after a particular data\n");
        printf("7. Enter to insert a node before a particular data\n");
        printf("8. Enter to delete a node at beginning\n");
        printf("9. Enter to delete a node at end\n");
        printf("10. Enter to delete a node at any particular location\n");
        printf("11. Enter to delete a node of particular element\n");
        printf("12. EXIT\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                creatlist(head);
                break;
            case 2:
                displaylist(head);
                break;
            case 3:
                insertion_beg(head);
                break;
            case 4:
                insertion_end(head);
                break;
            case 5:
                insertion_pl(head);
                break;
            case 6:
                insertion_AE(head);
                break;
            case 7:
                insertion_BE(head);
                break;
            case 8:
                deletion_beg(head);
                break;
            case 9:
                deletion_end(head);
                break;
            case 10:
                deletion_PL(head);
                break;
            case 11:
                deletion_PE(head);
                break;
                
            case 12:{
            	printf("GOODBYE");
				break;
			}
        } 
    } while(choice != 12);

    return 0;

}

