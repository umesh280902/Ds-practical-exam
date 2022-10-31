#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
int data;
struct node *left;
struct node *right;
};
struct node *root;
int max(int x,int y)
{   
	if(x>y)
    {
return x;
    }
	else
	{
		return y;
	}
}
struct node *insertElement( struct node *root, int val )
{
struct node *ptr, *nodeptr, *parentptr;
ptr=(struct node*) malloc(sizeof(struct node));
ptr -> data = val;
ptr -> left = NULL;
ptr -> right = NULL;
if(root == NULL)
	root = ptr;
else
{
	parentptr = NULL;
	nodeptr = root;
	while(nodeptr != NULL)
{
	parentptr = nodeptr;
	if(val < nodeptr -> data)
		nodeptr = nodeptr -> left;
	else
		nodeptr = nodeptr -> right;
}
if(val < parentptr -> data)
	parentptr -> left = ptr;
else
	 parentptr -> right = ptr;
}
return root;
}

void preorder(struct node *root){
    if(root==NULL)
    {
        return;
    }
    printf("%d\n",root->data);
    preorder(root->left);
    preorder(root->right);

}
void postorder(struct node* root){
if(root==NULL)
{
    return;
}
postorder(root->left);
postorder(root->right);
printf("%d\n",root->data);
}
void inorder(struct node* root){
if(root==NULL)
{
    return;
}
inorder(root->left);
printf("%d",root->data);
inorder(root->right);
}
struct node *smallest1(struct node *root)
{
	if(root ==  NULL || root->left == NULL)
		return root; 	
	else
		return smallest1(root->left);
}
struct node *deleteNode( struct node *root, int key )
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
if(root == NULL)
	root = root;
if(key > root->data)
	root->right = deleteNode(root->right,key);
else if(key < root -> data)
	root->left = deleteNode(root->left,key);
else
{	//case 1 or case 2
	if(root -> left == NULL)
	{
		temp = root -> right;
		free(root);
		return temp;
	}
	else if(root -> right == NULL)
	{
        temp=root->left;
		free(root);
		return temp;
	}
else
	{	
		struct node *ptr ;
        ptr= smallest1(root->right);
		root -> data = ptr -> data;
		root -> right =  deleteNode(root -> right,ptr -> data);
	}

}
return root;
}
struct node *BSTSearch(struct node *root, int key)
{
	if(root==NULL)
		return NULL;
	else if(key == root -> data)
		return root;
	else if(key < root -> data)
		return BSTSearch(root -> left, key);
	else
		return BSTSearch(root -> right, key);
}
int total_nodes(struct node *root)
{
	if(root != NULL)
		return ( total_nodes(root -> left) + total_nodes(root -> right) +1);
	else
		return 0;
}
int internal_nodes(struct node *root)
{
	if(root == NULL || (root -> left == NULL) && (root -> right == NULL))
		return 0; 	
	else
		return ( internal_nodes(root -> left) + internal_nodes(root -> right) +1);
}
int leaf_nodes(struct node *root)
{
	if(root == NULL)
		return 0; 	
	else if((root -> left == NULL) && (root -> right == NULL))
		return 1;
	else
		return ( leaf_nodes(root -> left) + 	leaf_nodes(root -> right));
}
int height(struct node *root)
{
	if(root ==  NULL)
		return -1; 	
	else
	{
		int leftht=height(root -> left);
		int rightht=height(root -> right);
		return(max(leftht, rightht) + 1);
	}
}

void main(){
int ch,value;
int a,b,c,d,e;
while(1)
{
    printf("\nMain Menu\n");
    printf("1.Insert \n2.Inorder Traversal \n3.Postorder Traversal \n4.Preoreder Traversal \n5.Deletion \n6.Search \n7.total nodes \n8.internal nodes \n9.height \n10.leaf nodes\n");
    printf("Enter Choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1: printf("enter the value you want to enter:");
    scanf("%d",&value);
    root=insertElement(root,value);
    break;
    case 2:printf("Inorder traversal:");
    inorder(root);
    break;
    case 3:printf("Postorder traversal:");
    postorder(root);
    break;
    case 4:printf("Preorder traversal");
    preorder(root);
    break;
    case 5: printf("enter the value you want to delete:");
    scanf("%d",&value);
    deleteNode(root,value);
    break;
	case 6:printf("enter the value you want to enter:");
    scanf("%d",&value);
	 printf("%d",BSTSearch(root,value));
	break;
	case 7:
	b=total_nodes(root);
	printf("%d",b);
	break;
	case 8:
	c=internal_nodes(root);
	printf("%d",c);
	break;
	case 9:
	d=height(root);
	printf("%d",d);
	break;
	case 10:
	e=leaf_nodes(root);
	printf("%d",e);
	break;
    case 11:exit(0);
    break;
    default:printf("invalid choice");
    break;
}
}
}


