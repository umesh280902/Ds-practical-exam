/*Aim:Implement stack ADT using array 
Umesh Kumawat Roll no:2104099 C22*/ 
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int top= -1;
int stack[MAX];
void push(int item);
int pop();
int peek();
int empty();
int full();
int size();
void display();
void main(){ 
    int x;
    int p;
    int choice;
    int item;
    while(1){
        printf("enter your choice as per the followings\n");
        printf(" 1.push\n 2.pop\n 3.peek\n 4.display\n 5.size\n 6.exit\n");
          scanf("%d",&choice);
          switch(choice){
            case 1://push//
            printf("enter the item to be pushed:\n");
                          scanf("%d",&item);
                          push(item);
                          break;
            case 2: //pop//
                     item=pop();
                       printf("item popped is:%d\n",item);
                                               break;
            case 3: 
            
                      x = peek();
                      printf("the item present at top is:%d\n",x); 
                    break;
          
            case 4: printf("the items present are:\n");
                     display();
                        break;
            case 5:
            size();
            printf("\n");
            break;
            case 6:
            exit(0);
            break;
            default:printf("invalid choice\n");
            break;
          }
    }
}
void push(int item){
        if( full() ){
                printf("\nStack Overflow\n");
                return;
        }
        top = top+1;
        stack[top] = item;
}/*End of push()*/
int pop(){
        int item;
        if( empty() ){
                printf("\nStack Underflow\n");
                exit(1);
        }
        item = stack[top];
        top = top-1;
        return item;
}/*End of pop()*/
int peek(){
        if( empty() ){
                printf("\nStack Underflow\n");
                exit(1);
        }
        return stack[top];
}/*End of peek()*/
int empty(){
        if( top == -1 )
                return 1;
        else
                return 0;
}/*End of empty*/
int full(){
        if( top == MAX-1 )
                return 1;
        else
                return 0;
}/*End of full*/
void display(){
        int i;
        if( empty() )
        {
                printf("\nStack is empty\n");
                return;
        }
    printf("\nStack elements :\n\n");
        for(i=top;i>=0;i--)
                printf(" %d\n", stack[i] );
        printf("\n");
}/*End of display()*/
int size(){
        if(empty())
        {
                printf("stack underflow\n");
                exit(1);
        }
        printf("the size of the stack is:%d",top+1);
}/*End of Size()*/