#include<stdio.h>
#include<stdlib.h>
int value;
struct node{
    int data;
    struct node *next;
}*head,*temp,*tail,*current,*prev,*next,*temp1,*new,*ptr;
void create()
{   
    new=(struct node*)malloc(sizeof(struct node));
    printf("\nenter a value:"); 
    scanf("%d",&value);   
    new->data=value;
    new->next=head;
}
void insert()
{
    create();
    if(head==NULL)
    {
        head=new; //head will get the input for the first element
        tail=new; // here tail and head will point at the first element of the linked list
    }
    else
    {
        tail->next=new; //here head!=NULL means head already have the element so we move only tail node
        tail=new;      //tail will take data from new and then it will point to next element of the head in linked list
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
        tail->next=head;
        printf("the linked list is as follows\n");
      while(temp->next!=head){
          printf("%d\n",temp->data);
          temp=temp->next;     
      }
      printf("%d",temp->data);
    }
    //end of display()
}
void insertatbeginning()
{
    if(head==NULL)
    {
    printf("\nlinkedlist is empty");
    }
    else
    {
    create();
    head=new;
    //tail->next=head;   
    display();
    }
}
void deleteatfront()
{
    if(head==NULL)
    {
        printf("\nlinkedlist is empty\n");
    }
    else
    {
      temp=head;
      head=head->next;
      tail->next=head;
      free(temp);
      display();
    }
}
void deleteatend()
{
  if(head==NULL)
        printf("No Linked List found.");
    else
    {
        ptr=head;
    temp1=tail;
    free(temp1);
           tail->next=head;
           printf("the linked list is as follows\n");
       while(ptr->next!=head){
          printf("%d\n",ptr->data);
          ptr=ptr->next;     
      }
    }
}
void reversetraversal()
{ 
     if(head==NULL)
        printf("No Linked List found.");
    else
    {
    current=head;
    tail->next=head;
    while(current->next!=head)
        {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        }
    }
    head=prev;
    free(prev);
}
void forwardtraversal()
{
    display();
}
void main()
{ 
        int number1,number2,number3,choice;
    while(1)
    {
       printf("\n1.create a list\n2.display the list\n3.insert a front\n4.insertatend\n5.delete at front\n6.delete at end\n7.forward traversal\n8.backward traversal\n9.count of the number of nodes\n10.exit\n");
       printf("enter your choice as per the followings:");
       scanf("%d",&choice);
       switch(choice)
       {
      case 1:insert(); //calling insert function
             break;
        case 2:display(); //calling display function
            break;
           case 3:insertatbeginning();
           break;
             case 4:insert();
             display();
             break;
           case 5: deleteatfront();
            break;
           case 6:
           deleteatend();
           break;
            case 7:
                  forwardtraversal();
                  break;
                  case 8:
              reversetraversal();
              display();
              break;
            case 10:exit(1);
            break;
            default:printf("invalid choice\n");
            break;
       }
      }
}