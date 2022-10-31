#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100
int queue[MAX];
int front=-1,rear=-1;
int count=0;
void enqueue(int);
int dequeue();
void getFront();
void getRear();
int size();
void display();
int main()
{
    int ch,r,e;
    printf("\t\t\t\t\tLINEAR QUEUE ADT array\n");
    while(1)
    {
        printf("\nMAIN MENU\n");
        printf("1.Enqueue\n2.Dequeue\n3.Get Front\n4.Get Rear\n5.Size\n6.Display\n7.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter number to enqueue\n");
            scanf("%d",&e);
            count++;
            enqueue(e);
            break;
        case 2:
            printf("You have chosen dequeue\nElement deleted is:\t");
            dequeue();
            count--;
            display();
            break;
        case 3:
            printf("Front Element is:");
            getFront();
            break;
        case 4:
            printf("Rear Element is:");
            getRear();
            break;
        case 5:
            printf("%d",count);
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);
        }


    }
}
void enqueue(int e)
{
    if(rear==MAX-1)
        printf("Overflow\n");
    else if(front=rear==-1)
    {
        front=rear=0;
        queue[rear]=e;
    }
    else
    {
        rear++;
        queue[rear]=e;
    }
}
int dequeue()
{
    int value;
if(front==-1&&rear==-1)
{
printf("underflow\n");
exit(1);
}
else
{
   value=queue[front];
   if(front==rear)
   {
    front=-1;
    rear=-1;
   }
    else
    {
        front++;
    }
}
return value;
}


void getFront()
{
    if(front=rear==-1)
        printf("Underflow\n");
    else
        printf("%d",queue[front]);
}
void getRear()
{
    if(front=rear==-1)
        printf("Underflow\n");
    else
        printf("%d",queue[rear]);
}
void display()
{
if(front==-1&&rear==-1)
{
    return;
}
else
{
    printf("element of the queues are\n");
    for(int i=rear;i<=front;i++)
    {
        printf("%d\n",queue[i]);
    }
}
}