#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *top=NULL;

int main(){
    int ch;
    do{
        printf("\n1. Push the element\n");
        printf("2. Display\n");
        printf("3. Peek the element\n");
        printf("4. Pop the element\n");
        printf("5. EXIT\n");
        printf("\nEnter your choice (1-5): ");
        scanf("%d",&ch);

     
        
        switch (ch) {
            case 1:{
                int val;
                printf("Enter the data: ");
                scanf("%d",&val);
                struct node *newnode;
                newnode = (struct node*)malloc(sizeof(struct node));
                newnode->data=val;
                newnode->next=top;
                top=newnode;
                break;
            }
            case 2:{
                struct node *tmp;
                if (top==NULL){
                    printf("Stack is Empty\n");
                }
		else
		{
                    tmp=top;
                    while(tmp!=NULL){
                        printf("%d\n",tmp->data);
                        tmp=tmp->next;
                    }
                }
                break;
            }
            case 3:
		{
                if (top==NULL){
                    printf("Stack is Empty\n");
                    
                }
		else
		{
                    printf("The top of the Data is %d\n",top->data);
                }
                break;
            }
            case 4:
		{
                struct node *tmp;
                if (top==NULL)
		{
                    printf("The stack is Empty\n");
                    return 0;
                }
		else
		{
                    tmp=top;
                    printf("The popped element is %d\n",tmp->data);
                    top=tmp->next;
                    free(tmp);
                }
                break;
            }
            case 5:
		{
                printf("GOODBYE");
                break;
            default:
                printf("Invalid choice\n");
            }
        }
    }
	    while(ch<5);
}
