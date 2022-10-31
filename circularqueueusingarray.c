/*Circular queues using array
Umesh Kumawat Rollno:99 C22*/
#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max];
int front=-1;
int rear=-1;
int isEmpty()
{
 if(front==-1&&rear==-1)
 return 1;
 return 0;
}
int isFull()
{
 if(front==0&&rear==max-1||rear==front-1)
 return 1;
 return 0;
}
void enqueue(int val)
{
 if(isFull())
 {
 printf("Queue is Full\n");
 return;
 }
 else
 {
 if(isEmpty())
 {
 rear=0;
 front=0;
 }
 else
 rear=(rear+1)%max;
 queue[rear]=val;
 }
}
void dequeue()
{
 if(isEmpty())
 {
 printf("Queue is Empty\n");
 return;
 }
 else
 {
 printf("DELETED ELEMENT=%d\n",queue[front]);
 if(rear==front)
 {
 rear=-1;
 front=-1;
 }
 else
 front=(front+1)%max;
 }
}
int size()
{
 int count=0; 
 if(isEmpty())
 return 0; 
 else if(rear>=front)
 {
 for(int i=front;i<=rear;i++)
 count++; 
 }
 else
 {
 for(int i=front;i<max;i++)
 count++;
 for(int i=0;i<=rear;i++)
 count++;
 }
 return count;
}
void display()
{
if(isEmpty())
 printf("NO ELEMENT PRESENT\n");
else if(front<=rear)
 {
 for(int i=front;i<=rear;i++)
 printf("| %d",queue[i]); 
 }
 else
 {
 for(int i=front;i<max;i++)
 printf("| %d",queue[i]);
 for(int i=0;i<=rear;i++)
 printf("| %d",queue[i]);
 }
 printf("|\n");
}
int getfront()
{
 if(isEmpty())
 return -1;
 else
 return queue[front];
}
int getrear()
{
 if(isEmpty())
 return -1;
 else
 return queue[rear];
}
int main()
{
 int num,choice;
 printf("This program is an implementation of Circular ADT using Array\n");
 do
 {
 printf("Choose Your Option:\n");
 printf("1.ENQUEUE\n");
 printf("2.DEQUEUE\n");
 printf("3.GET FRONT\n");
 printf("4.GET REAR\n");
 printf("5.SIZE\n");
 printf("6.DISPLAY\n");
 printf("7.EXIT\n");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 printf("Enter a value:");
 scanf("%d",&num);
 enqueue(num);
 break;
 case 2:
 dequeue();
 break; 
 case 3:
 if(getfront()==-1)
 printf("Queue is Empty\n");
 else
 printf("Front element of queue=%d\n",getfront());
 break;
 case 4:
 if(getrear()==-1)
 printf("Queue is Empty\n");
 else
 printf("Rear element of queue=%d\n",getrear());
 break;
 case 5:
 printf("Total no. element of queue=%d\n",size());
 break;
 case 6:
 display();
 break;
 case 7:
 exit(1);
 break;
 default:
 printf("INVALID CHOICE\n");
 break;
 }
 }while(1);
 return 0;
} 