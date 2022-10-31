#include<stdio.h>
#define MAX 4
#include<stdlib.h>

int top=-1;
int stack_arr[MAX];
int IsEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int IsFull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}
void push(int data)
{
    if(IsFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack_arr[top]=data;
}
int pop()
{
    int data;
    if(IsEmpty())
    {
        printf("Stack underflow\n");
        exit;
    }
    data=stack_arr[top];
    top--;
    return data;
}
void display()
{
    if(MAX==-1)
    {
        printf("Stack underflow\n");
    }
    for(int i=top; i>=0; i--)
    {
        printf("%d\t",stack_arr[i]);
    }
    printf("\n");
}
int peak()
{
    printf("%d\n",stack_arr[top]);
}
int main()
{
    int choice,count=0,data;
    while(1)
    {
        printf("Menu:\n");
        printf("1.Push\n");
        printf("2.POP\n");
        printf("3.Peek\n");
        printf("4.IsEmpty\n");
        printf("5.IsFull\n");
        printf("6.Display\n");
        printf("7.Size\n");
        printf("8.Exit\n");
        printf("Enter choice based on operations you want to perform\n");
        scanf("%d",&choice);

        switch(choice)
        {

        case 1:
        {
            printf("Enter number to be pushed\n");
            scanf("%d",&data);
            push(data);
            count++;
            break;
        }
        case 2:
            data=pop();
            printf("Deleted Element is %d\n",data);
            count--;
            break;
        case 3:
            peak();
            break;
        case 4:
            if(IsEmpty())
                printf("Stack is empty\n");
            else
                printf("Stack is not empty\n");
            break;
        case 5:
            if(IsFull())
            {
                printf("Stack is Full\n");
            }
            else
                printf("Stack is not Full\n");
            break;
        case 6:
            display();
            break;
        case 7:
            printf("%d",count);
            break;
        case 8:
            exit(0);
        default:
            printf("Not a valid input\n");

        }
    }
}