/*Evaluate Postfix Expression Using Stack ADT
Umesh kumawat roll:099 C22*/
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define max 100
float stack[max];
int top=-1;
void push(float stack[],float val);
float pop(float stack[]);
float postfixevaluation(char source[]);
int main()
{
    char equation[100];
    float result;
    printf("enter a postfix expression:\n");
    gets(equation);
 printf("token\tstack\n");
    result=postfixevaluation(equation);
    printf("the equation result is:%.2f",result);
    return 0;
}
float postfixevaluation(char source[])
{
 int i=0;
 float op1,op2,result;
 while(source[i]!='\0')
 {   
    if(isdigit(source[i]))
    {
      push(stack,(float)((source[i])-'0'));
    }
    else
    {      
        op2=pop(stack);
        op1=pop(stack);
          printf("%.2f\t%.2f\n",op1,op1);
        switch(source[i])
        {
            case '^': 
                    result=pow((int)op1,(int)op2);
                   break;
                       
            case '+':
                      result=op1+op2;
                      break;
            case '-':
                      result=op1-op2;
                      break;
            case '*':
                      result=op1*op2;
                      break;
            case '/':
                      result=op1/op2;
                      break;

        }
      printf("%.2f\t%.2f,%.2f\n",op2,op1,op2);
        push(stack,result);
      printf("%c\t%.2f\n",source[i],result);
    }
   i++;        
 };
 return(pop(stack));
}
      
void push(float stack[],float result)
{
    if(top==max-1)
    printf("stack underflow\n");
    else
    top=top+1;
    stack[top]=result;

}
float pop(float stack[])
{ 
    float result;
    if(top==-1)
    {
    printf("stack underflow\n");
      }
      else{
    result=stack[top];
    top=top-1;
     }
     return result;
}