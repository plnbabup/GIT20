#include<stdio.h>
#include<stdlib.h>
int a[20][20],reach[20],n,c=0;
void dfs(int v)
{
  int i;
  for(i=1;i<=n;i++)
  {
   if(a[v][i])
   {
    if(reach[i]==0)
    {
     printf("%d->%d ",v,i);
     printf("\nThere's a cycle in graph\n");
     exit(0);
    }
    else if(reach[i]==-1)
    {
     reach[v]=0;
     printf("%d->%d ",v,i);
     dfs(i);	
    }
   }
   if(i==n)
      reach[v]=1;
   c++;
  }
}
void main()
{
 int i,j;
 printf("Enter number of vertices:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  reach[i]=-1;
  for(j=1;j<=n;j++)
   a[i][j]=0;
 }
 printf("Enter the adjacency matrix:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   scanf("%d",&a[i][j]);
  }
 }
 dfs(1);
 if(c==n*n)
     printf("\nThere's no cycle in the graph\n");
 else
     printf("\nGraph is not connected one\n");
}
