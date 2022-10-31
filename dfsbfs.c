#include<stdio.h>
#include<conio.h>
int adj[30][30],n;
void BFS(int front ,int rear,int vis[],int queue[],int start)
{
 int i;
 for(i=0;i<n;i++)
 {
 if(adj[start][i]!=0 && vis[i]!=1)
 {
 rear=rear+1;
 queue[rear]=i;
 vis[i]=1;
 printf("%d ",i);
 }
 }
 front=front+1;
 if(front<=rear)
 BFS(front,rear,vis,queue,queue[front]);
}
void DFS(int vis[],int start)
{
 int j;
 for(j=0;j<n;j++)
 {
 if(vis[j]==0 && adj[start][j]!=0)
 {
 vis[j]=1;
 printf("%d ",j);
 DFS(vis,j);
 }
 }
}
int main()
{
 int choice,v;
 int front=-1,rear=-1;
 int queue[10],vis1[10],vis2[10]={0};
 printf("Enter no of vertices of adjaceny matrix: ");
 scanf("%d",&n);
 printf("Enter the adjacency Matrix:\n");
 for(int i=0;i<n;i++)
 {
 for(int j=0;j<n;j++)
 scanf("%d",&adj[i][j]);
 }
 for(int i=0;i<n;i++)
 {
  vis1[i]=0;
}
 printf("Press 1.BFS\n");
 printf("Press 2.DFS\n");
 printf("Press 3.Exit\n");
 do
 {
 printf("\nEnter the choice: ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:printf("Enter the starting vertex: ");
 scanf("%d",&v);
 front=0;
 rear=0;
 queue[rear]=v;
 vis1[v]=1;
 printf("BFS Traversal: ");
 printf("%d ",v);
 BFS(front,rear,vis1,queue,v);
 break;
 case 2:printf("Enter the starting vertex: ");
 scanf("%d",&v);
 printf("DFS Traversal: "); 
 vis2[v]=1;
 printf("%d ",v);
 DFS(vis2,v);
 break; 
 }
 } while (choice!=3);
 return 0; 
}
