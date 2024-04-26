#include<stdio.h>
#include<stdlib.h>

int main()
 {
 
 
    struct node{
        int data;
        struct node *next;
    };
    int choice;
    struct node *head,*newnode,*temp,*prev;  
    head=NULL;
    do{
        printf("\n\n\n1. Enter for Creation of nodes\n");
        printf("2. Enter for Displaying nodes\n");
        printf("3. Enter to insert a node at beginning\n");
        printf("4. Enter to insert a node at the end\n");
        printf("5. Enter to insert a node at particular position\n");
        printf("6. Enter to insert a node after a particular data\n");
        printf("7. Enter to delete a node at beginning\n");
        printf("8. Enter to delete a node at end\n");
        printf("9. Enter to delete a node at any particular location\n");
        printf("10. Enter to delete a node of particular element\n");
        printf("11. EXIT \n");
        printf("\nEnter your choice:");
        scanf( "%d", &choice);
        
	
		if(choice>10)
		{
            printf("invalid choice");
        }
    

    
        switch(choice)
	{
            case 1:
	{

                head=NULL;
                int choice=1;
                int count=1;
                while(choice)
		{
                    newnode=(struct node*)malloc(sizeof(struct node));     
			//memory allocate to make node and store the address of it in the new node to access it.

                    ///inserting values.
                    printf("Enter the element you want to insert: ");
                    scanf("%d",&newnode->data);
                    newnode->next=NULL;

                    //conditions for checking if the node is empty of not.
                    if(head==NULL)
		    {
                        head=temp=newnode;
                    }
                    else
		    {
                        temp->next=newnode;
                        temp=newnode;
                    }
                    
                    //Displaying the contents.
                    printf("node %d contains Data = %d \nand Address = %u",count,temp->data,temp->next);  //display the items of the 1st node.
                    printf("\ndo you want to continue(1,0) = ");
                    scanf("%d",&choice);
                    
                    count++;
                }
                break;
            }

            case 2:
	{
                if (head == NULL)
		{
                    printf("NO NODE IS AVAILABLE ");
		}
                else
		{
                    temp=head;
                    printf("Node contains : ");
                    while(temp!= NULL)
		    {
                        printf(" %d",temp->data);
                        temp=temp->next;
                    }
                }
                break;

        }
            case 3:
	{
            	    int ch=1;
            	    while(ch)
		    {
					
            		int num;
				printf("\n Enter the data : ");
				scanf("%d", &num);
				newnode= (struct node*)malloc(sizeof(struct node));
				newnode -> data = num;
				newnode -> next = head;
				head=newnode;
				//traversing to print the list					
				temp=head;
			        printf("\ndo you want to continue(1,0) = ");
			       scanf("%d",&ch);
		     }
                    while(temp!= NULL)
                    {
			printf(" %d",temp->data);
                        temp=temp->next;
		   }
                break;
            }

            
            case 4:
	{
                int ch=1;
                while(ch)
		{
                    newnode=(struct node*)malloc(sizeof(struct node)); 
                                               
                    printf("Enter the number of elements you want to insert: ");
                    scanf("%d",&newnode->data);
                    newnode->next=NULL;

                    temp=head;
                    while(temp->next!= NULL)
		    {
                        temp=temp->next;
                    }
                    temp->next=newnode;
                    temp=newnode;
                    
                    printf("\ndo you want to continue(1,0) = ");
                    scanf("%d",&ch);
                }

                temp=head;
                printf("Node contains : ");
                while(temp!= NULL)
		{
                    printf(" %d",temp->data);
                    temp=temp->next;
                }
             break;   
                
            }

            case 5:{
            	int pos, num,count;
                printf("\nEnter the position : ");
                scanf("%d", &pos);
                printf("Enter the data : ");
                scanf("%d", &num);
                

                newnode = (struct node*)malloc(sizeof(struct node));
                newnode->data = num;

		if (pos==0)
		{
		printf("INVALID LOCATION");
		}
				
                if (pos == 1) 
		{
                    newnode->next = head;
                    head = newnode;
            }
                else
		{
                	temp=head;
                	count=0;
                	while (count!=pos-1)
                	{
                		prev=temp;
                		count=count+1;
                		temp=temp->next;
			}
				newnode->next=prev->next;
				prev->next=newnode;
		}
                break;
            }
            case 6:{
            	
            	int value,element;
            	int count=0;
		newnode = (struct node*)malloc(sizeof(struct node));
                printf("\n Enter the value: ");
                scanf("%d",&value);
                temp=head;
                while(temp->data!=value)
	       {
               	if(temp->data==value)
		{
	            count++;
		}            	
	      	temp=temp->next;
		}
		if(count>1){
		printf("there are %d Element present of this value",count);
						
		}
		    printf("Enter the element to be entered: ");
	            scanf("%d",&element);
					
		newnode->data=element;
		newnode->next=temp->next;
		temp->next=newnode;
         	temp=head;
		while(temp!= NULL)
		{
	 	  printf(" %d",temp->data);
	            temp=temp->next;
		}
	}
				break;
		
			
            
            
            case 7:{
				
			    if(head==NULL)
			    {
			        printf("underflow");
			    }
				 else if(head->next==NULL)
				{
					temp=head;
					head=NULL;
					free(temp);
					 printf("node deleted");
				}
				
				else
				{
			        temp = head;
			        head = temp->next;
			        free(temp);
			       
			    }
			    temp = head;
			    while(temp != NULL)
			{
			        printf(" %d", temp->data);
			        temp = temp->next;
			    }
		    

				
			    break;
			}
			
			case 8:{
				if(head==NULL)
			{
			        printf("underflow");
		        }
				 else if(head->next==NULL)
			{
					temp=head;
					head=NULL;
					free(temp);
					 printf("node deleted");
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
				
			    temp = head;
			    while(temp != NULL) 
			    {
			        printf(" %d", temp->data);
			        temp = temp->next;
			    }
			    
				
			break;
			}
			
			case 9:{
				int value;
				
				printf("Enter the location at which you want to delete: ");
				scanf("%d",&value);
				if (value <= 0)
			   {
			        printf("Invalid position.\n");
			        break;
			    }
				temp=head;
		
                        int count=0;
                	while (count!=value-1)
                	{
                	    prev=temp;
                	    temp=temp->next;
                	    count=count+1;
			    prev->next=temp->next;
				free(temp);
				
				temp = head;
			    while(temp != NULL) 
			    {
			        printf(" %d", temp->data);
			        temp = temp->next;
			    }
			    
				break;
			}
        	
			
			case 10:{
        		printf("GOODBYE");
				break;
			}    
		}    
        
    }
        while(choice<11);

return 0;

  }


