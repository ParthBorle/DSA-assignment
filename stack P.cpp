#include <stdio.h>

int main()
{
	int max;
	int tmp=0;
	printf("Enter the size of stack");
	scanf("%d",max);
	int stack[max];
	int *top =NULL;
	int data;
	int option;
	do
	{
		printf("\n___MENU___\n");
		printf("1. Inesrtion\n");
		printf("2. Deletion\n");
		printf("3. Traversing\n");
		printf("4. Exit\n");
		printf("\nEnter your choice: \n");
		scanf("%d",&option);
		switch (option)
		{
			case 1:
				printf("Enter element:");
				scanf("%d",&data);
				if(*top==max)
				{
					printf("stack overflow\n");
				}
				else
				{
					(*top)++;
					stack[*top]=data;	
				}
				break;
			case 2:
				if(*top==NULL)
				{
					printf("Underflow\n");
				}
				else 
				{
					data=stack[*top];
					(*top)--;
				}
				printf("\nDeleted element is %d\n", data);	
				break;
			case 3:
				if (*top == NULL) 
				{
			        printf("Stack is empty\n");
			    }
				printf("\nElements in array are:\n");
				while(tmp<=*top)
				{
					printf("%d\n",stack[tmp]);
					tmp++;
				}
				break;
			default:
                printf("Invalid choice\n");
                break;
                
		}
						
	}while(option != 4);
	return 0;
}
