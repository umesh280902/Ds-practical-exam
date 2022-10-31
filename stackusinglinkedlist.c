#include<stdio.h>
#include<stdlib.h>
int value;
struct node{
    int data;
    struct node *next;
}*head,*temp,*tail,*new;
void create()
{   
    new=(struct node*)malloc(sizeof(struct node));
    printf("\nenter a value:"); //creating a struct pointer
    scanf("%d",&value);   // adding data to the node of the given a linked list
    new->data=value;
    new->next=NULL;
}
void insert()
{
    create();
    if(head==NULL)
    {
        head=new; 
        tail=new; 
    }
    else{
        tail->next=new; 
        tail=new;      
    }
    //end of insert
}
void display()
{ 
    temp=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("\nlinkedlist is empty");
    }
    else
    {   
        temp=head;
      while(temp!=NULL){
          printf("%d---->",temp->data);
          temp=temp->next;     
      }
      printf("NULL\n");
    }
    //end of display()
}
void push()
{
    if(head==NULL)
    {
        printf("\nlinkedlist is empty");
    }
    else
    {
    create();
    new->data=value;
     new->next=head;
     head=new;   
    display();
    }
}
void pop()
{
    if(head==NULL)
    {
        printf("\nlinkedlist is empty\n");
    }
    else
    {
      temp=head;
      head=head->next;
      free(temp);
      display();
    }
}
void peek()
{
    if(head==NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
       printf("%d is the top element of the stack\n",head->data);
    }
}
void isempty()
{
    if(head==NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("stack is not empty\n");
    }    
}
void main()
{ 
        int choice;
    while(1)
    {
       printf("\n1.create a list\n2.display\n3.push\n4.pop\n5.peek\n6.isempty\n7.exit\n");
       printf("enter your choice as per the followings:");
       scanf("%d",&choice);
       switch(choice)
       {
      case 1:insert(); //calling insert function
             break;
        case 2:display(); //calling display function
            break;
           case 3:push();
           break;
           case 4: pop();
           break;
            case 5:
            peek();
            break;
            case 6:
            isempty();
            break;
            case 7:exit(1);
            break;
       }
      }
}