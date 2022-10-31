#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
struct node *left, *right;
};
struct node *root= NULL;
void insert();
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
void search(struct node *root, int n);
struct node *delete(struct node *root, int key);
struct node *smallest(struct node *temp);
int max(int l, int r);
int height(struct node *root);
int leaf(struct node *root);
int x=0;
int main()
{ int m,a,key,b=0,n;
while(1)
{ 
printf("\nEnter you Option\n1. Insertion\n2. Dletetion\n3. Searching\n4. Pre-Order Traversal\n5. Inorder Traversal\n6. Postorder Traversal\n7. Total number of nodes\n8. Total number of leaf nodes\n9. Total number of internal nodes\n10. Find Height of Tree\n11. Exit\n");
scanf("%d",&m);
switch(m)
{ case 1:
insert();
break;
case 2:
printf("Enter no. to be deleted\n");
scanf("%d",&key);
delete(root,key);
break;
case 3:
printf("Enter value to be searched\n");
scanf("%d",&n);
search(root,n);
break;
case 4:
preorder(root);
break;
case 5:
inorder(root);
break;
case 6:
postorder(root);
break;
case 7:
printf("Total no. of nodes is %d\n",x);
break;
case 8:
a=leaf(root);
printf("Total no. of leaf nodes is %d\n",a);
break;
case 9:
if(root == NULL)
a=0;
else
a=x-leaf(root);
printf("Total no. of internal nodes is %d\n",a);
break;
case 10:
a=height(root);
printf("Height is %d\n",a);
break;
case 11:
exit(0);
default:
printf("Wrong Choice\n");
break;
} }
return 0;
}
void insert()
{ int m;
printf("Enter element to be inserted\n");
scanf("%d",&m);
struct node *newnode,*t1,*t2;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=m;
newnode->left=newnode->right=NULL;
if(root==NULL)
root=newnode;
else
{ t2=NULL;
t1=root;
while(t1!=NULL)
{ t2=t1;
if(m>=t1->data)
t1=t1->right;
else
t1=t1->left;
}
if(m<t2->data)
t2->left=newnode;
else
t2->right=newnode;
}
x++;
}
void inorder(struct node *root)
{ if(root==NULL)
return;
inorder(root->left);
printf("%d\t",root->data);
inorder(root->right);
}
void preorder(struct node *root)
{ if(root==NULL)
return;
printf("%d\t",root->data);
preorder(root->left);
preorder(root->right);
}
void postorder(struct node *root)
{ if(root==NULL)
return;
postorder(root->left);
postorder(root->right);
printf("%d\t",root->data);
}
void search(struct node *root,int n)
{ if(root==NULL)
{ printf("BST is empty\n");
return;
}
if(root->data==n)
printf("%d exists\n",n);
else if(n>root->data)
search(root->right,n);
else if (n<root->data)
search(root->left,n);
else if(root==NULL)
printf("Element not found\n");
}
struct node *delete(struct node *root, int key)
{ struct node *temp;
temp=root;
if(temp==NULL)
printf("Empty");
else if(key<temp->data)
temp->left=delete(temp->left,key);
else if(key>temp->data)
temp->right=delete(temp->right,key);
else
{ if(temp->left==NULL && temp->right==NULL)
{ free(temp);
temp=NULL;
}
else if(temp->left==NULL)
{ struct node *t1=temp;
temp=temp->right;
free(t1);
}
else if(temp->right==NULL)
{ struct node *t2=temp;
temp=temp->left;
free(t2);
}
else
{ struct node *t1;
t1=smallest(temp->right);
temp->data=t1->data;
temp->right=delete(t1->right,t1->data);
}
x--;
}
return temp;
}
struct node *smallest(struct node *temp)
{ if(temp==NULL || temp->left==NULL)
return temp;
else
return smallest(temp->left);
}
int max( int l, int r)
{ if(l>=r)
return l;
else
return r;
}
int height(struct node *root)
{ struct node * temp;
temp=root;
if(temp==NULL)
return -1;
int leftht=height(temp->left);
int rightht=height(temp->right);
return (max(leftht,rightht) +1);
}
int leaf(struct node *root)
{ if(root == NULL)
return 0;
if(root->left == NULL && root->right == NULL)
return 1;
return leaf(root->left) + leaf(root->right);
}