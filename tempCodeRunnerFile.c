/*implement queues using ADT
Umesh Kumawat Rollno:99 C22*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 10
int rear=-1;
int front=-1;
int queue[max];
int isEmpty()
{
    if((rear==-1)&&(front==-1))
    return 1;
    else
    return 0;
}
int isFull()
{
    if(rear==max-1)
    return 1;
    else
    return 0;
}
void Enqueue(int value)
{
    if(isFull()){
  printf("overflow\n");
  exit(1);
     }
    else if(isEmpty())
    {
    front=0;
    rear=0; 
    }
    else
    {
    rear++;
     }    
    queue[rear]=value;
}
int Dequeue()
{
    int value;
if(isEmpty())
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
int getFront()
{
    if(isEmpty())
    {
    printf("underflow\n");
    exit(1); }
    else
    return queue[front];
}
int getRear()
{
    if(isEmpty())
    {
    printf("underflow\n");
    exit(1);
    }
    return queue[rear];
}
void size()
{
if(isEmpty())
{
    return;
}
else
{
  int value;
  value=abs(front-rear);
  printf("%d is the size of the array\n",value+1);
}
}
void display()
{
if(isEmpty())
{
    return;
}
else
{
    printf("element of the queues are\n");
    for(int i=front;i<=rear;i++)
    {
        printf("%d\n",queue[i]);
    }
}
}
void main()
{
int choice,value1;
while(1){
printf("enter the choice as per the followings\n");
printf("1.enqueue\n2.dequeue\n3.getfront\n4.getrear\n5.display\n6.size\n7.exit\n");
scanf("%d",&choice);
switch(choice)
{
    case 1: 
    printf("enter the element you want to enter\n");
    scanf("%d",&value1);
    Enqueue(value1);
    break;
    case 2:
    printf("%d is the removed element\n",Dequeue());
    break;
    case 3:
     printf("%d is the element present at the front\n",getFront());
     break;
    case 4:
     printf("%d is the element present at the rear\n",getRear());
     break;
    case 5:
    display();
    break;
    case 6:
    size();
    break;
    case 7:
    exit(0);
    break;
    default: printf("invalid choice\n");
    break;
}
}
}