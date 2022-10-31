#include<stdio.h>
#include<stdlib.h>
int value;
struct node{
    int data;
    struct node *next;
}*start,*head,*temp,*tail,*temp2,*temp1,*current,*prev,*next,*new;
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
        head=new; //head will get the input for the first element
        tail=new; // here tail and head will point at the first element of the linked list
    }
    else{
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
      while(temp!=NULL){
          printf("%d---->",temp->data);
          temp=temp->next;     
      }
      printf("NULL\n");
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
    new->data=value;
     new->next=head;
     head=new;   
    display();
    }
}
void insertatend()
{
    if(head==NULL)
    {
        printf("\nlinkedlist is empty");
    }
    else
    {
        create();  
      new->data=value; //new will take value 
      tail->next=new;   //tail is already at the end so tail next will be new 
      new->next=NULL; //new next will contain NULL
      tail=new;   //now tail will point to the last node of the linkedlist
      display();     
    }
}
void insertbeforeanode(int btn)
{ 
    
if(head==NULL)
{
    printf("\nlinkedlist is empty\n");

}
else
{
    int count=1;
temp1=head;
temp2=head;
while(temp2->data!=btn)
{
    temp2=temp1;
    temp1=temp1->next;
    count++;
} 
create();
new->data=value;
new->next=temp1;
temp2->next=new;
display();
}
}
void count()
{
     if(head==NULL)
     {
        printf("\nlinklist is empty\n");
     }
     else
     {
        int count=0;
        temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        printf("\nthe number of nodes are %d",count);
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
      free(temp);
      display();
    }
}
void deleteatend()
{
  if(head==NULL)
        printf("No Linked List found.");
    else
    temp=head;
    while(temp->next!=tail)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    tail=temp;
    display();
}
void delbeforenode(int dtn)
{
if(head==NULL)
{
    printf("\nlinkedlist is empty\n");
}
else
{
temp1=head;
temp2=head;
while(temp1->data!=dtn)
{
    temp2=temp1;
    temp1=temp1->next;
} 
temp2->next=temp1->next;
free(temp1);
}
display();
}
void sort()
{
temp1=head;
while(temp1->next!=NULL)
{
    temp2=temp1->next;
    while(temp2!=NULL)
    {
        if((temp1->data)>(temp2->data))
        {
            int temporary;
            temporary=temp1->data;
            temp1->data=temp2->data;
            temp2->data=temporary;
        }
       temp2=temp2->next;     
    }
    temp1=temp1->next;
}
display();
}
void reversetraversal()
{ 
     if(head==NULL)
        printf("No Linked List found.");
    else
    {
    current=head;
    while(current!=NULL)
        {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        }
    }
    head=prev;
    display();
    free(prev);
}
void search(int num)
{
    temp=head;
while (temp != NULL)
 {
 if (temp->data == num)
 {
 printf("Element is found\n");
 return;
 }
 temp = temp->next;
 }
 printf("Element is not found\n");
}
void main()
{ 
        int number1,number2,number3,choice;
    while(1)
    {
       printf("\n1.create a list\n2.display the list\n3.insert a front\n4.insertatend\n5.insert before a node\n6.delete at front\n7.delete at end\n8.delete before a node\n9.forward traversal\n10.reverse traversal\n11.sort\n12.count of the number of nodes\n13.search\n14.exit\n");
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
           case 4:insertatend();
           break;
           case 5: 
           printf("\nenter the node location\n");
           scanf("%d",&number1);
           insertbeforeanode(number1);
           break;
           case 6: deleteatfront();
           break;
           case 7:
                 deleteatend();
                 break;
           case 8:
             printf("\nenter the node location\n");
             scanf("%d",&number2);
             delbeforenode(number2);
             break;
           case 9:
             display();
             break;
            case 10:
             reversetraversal();
            break;
            case 11:
             sort();
             break;
           case 12: 
             count();
                   break;
            case 13:  
            printf("enter the element to be searched:");
            scanf("%d",&number3);
             search(number3);
                     break;
            case 14:exit(1);
            break;
       }
      }
}