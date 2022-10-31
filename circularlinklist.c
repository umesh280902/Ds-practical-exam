/*Circular linked list
Umesh Kumawat Roll no:99 C22*/
#include <stdio.h>
#include <stdlib.h>
struct node{
 int data;
 struct node *next;
};
struct node *start = NULL;
struct node *create(struct node *start);
struct node *display(struct node *start);
struct node *insertBeg(struct node *start);
struct node *insertEnd(struct node *start);
struct node *deleteBeg(struct node *start);
struct node *deleteEnd(struct node *start);
struct node *reverse(struct node *start);
struct node *totalNodes(struct node *start);
void main(){
 int option;
 do{
 printf("\n1 for creating\n");
 printf("2 for display\n");
 printf("3 for inserting at beginning\n");
 printf("4 for inserting at end\n");
 printf("5 for deleting at beginning\n");
 printf("6 for deleting at end\n");
 printf("7 for backward traversing\n");
 printf("8 for number of nodes\n");
 printf("9 for exit\n\n");
 printf("Enter your option: ");
 scanf("%d", &option);
 switch(option){
 case 1:
 start = create(start);
 printf("\nLinked List created\n");
 break;
 case 2:
 start = display(start);
 break;
 case 3:
 start = insertBeg(start);
 break;
 case 4:
 start = insertEnd(start);
 break;
 case 5:
 start = deleteBeg(start);
 break;
 case 6:
 start = deleteEnd(start);
 break;
 case 7:
 start = reverse(start);
 break;
 case 8:
 start = totalNodes(start);
 break;
 }
 }while(option!=9);
}
struct node *create(struct node *start){
 struct node *newnode, *ptr;
 int num;
 printf("Enter -1 to end\n");
 printf("Enter data\n");
 scanf("%d", &num);
 while(num!=-1){
 newnode = (struct node*)malloc(sizeof(struct node));
 newnode -> data = num;
 if(start==NULL){
 newnode->next = newnode;
 start = newnode;
 }
 else{
 ptr = start;
 while(ptr->next != start){
 ptr = ptr->next;
 }
 ptr->next = newnode;
 newnode->next = start;
 }
 printf("Enter data\n");
 scanf("%d", &num);
 }
 display(start);
 return start;
}
struct node*display(struct node *start){
 struct node *ptr;
 ptr = start;
 while(ptr->next != start){
 printf("%d\t", ptr->data);
 ptr = ptr->next;
 }
 printf("%d\t", ptr->data);
 return start;
}
struct node *insertBeg(struct node *start){
 struct node *newnode, *ptr;
 newnode = (struct node *)malloc(sizeof(struct node));
 int num;
 printf("Enter data\n");
 scanf("%d", &num);
 newnode->data = num;
 ptr = start;
 while(ptr -> next != start){
 ptr = ptr->next;
 }
 ptr->next = newnode;
 newnode->next = start;
 start = newnode;
 display(start);
 return start;
}
struct node *insertEnd(struct node *start){
 struct node *newnode, *ptr;
 newnode = (struct node *)malloc(sizeof(struct node));
 int num;
 printf("Enter data\n");
 scanf("%d", &num);
 ptr = start;
 newnode->data = num;
 newnode->next = start;
 while(ptr->next != start){
 ptr = ptr->next;
 }
 ptr->next = newnode;
 display(start);
 return start;
}
struct node *deleteBeg(struct node *start){
 struct node *ptr;
 ptr = start;
 while(ptr->next != start){
 ptr = ptr->next;
 }
 ptr->next = start->next;
 free(start);
 start = ptr->next;
 display(start);
 return start;
}
struct node *deleteEnd(struct node *start){
 struct node *ptr, *preptr;
 ptr = start;
 while(ptr->next != start){
 preptr = ptr;
 ptr = ptr->next;
 }
 preptr->next = ptr->next;
 free(ptr);
 display(start);
 return start;
}
struct node *reverse(struct node *start){
 struct node *prev, *cur, *next, *last;
 last = start;
 prev = start;
 cur = (start)->next;
 start = (start)->next;
 while (start != last){
 start = (start)->next;
 cur->next = prev;
 prev = cur;
 cur = start;
 }
 cur->next = prev;
 start = prev;
 display(start);
 return start;
}
struct node *totalNodes(struct node *start){
 struct node *ptr;
 ptr = start;
 int count = 1;
 while(ptr->next != start){
 count++;
 ptr = ptr->next;
 }
 printf("Total number of nodes are %d", count);
 return start;
}
