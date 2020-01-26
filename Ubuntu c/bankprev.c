#include<stdio.h>
int alc[50][50],max[50][50],avl[100],ned[50][50],work[100],fin[100],ss[100],maximum=0;
int i,j,k,l,m,n,z,t,y,u;
int check(int k,int sz)
{
 z=0;
 for(i=1;i<=sz;i++)
 {
  if((ned[k][i]<=work[i])&&(fin[k]==0))
  {
   ++z;
  }
 }
 return z;
}
void main()
{
 int i,j,k,h=1;
 printf("Enter no of process:");
 scanf("%d",&n);
 printf("Enter no of resources:");
 scanf("%d",&m);
 printf("Enter resource allocation matrix:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=m;j++)
  {
   scanf("%d",&alc[i][j]);
  }
  fin[i]=0;
 }
 printf("Enter maximum resources matrix:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=m;j++)
  {
   scanf("%d",&max[i][j]);
  }
 }
 printf("Enter available resources:");
 for(i=1;i<=m;i++)
 {
  scanf("%d",&avl[i]);
  work[i]=avl[i];
 }
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=m;j++)
  {
   ned[i][j]=max[i][j]-alc[i][j];
  }
 }
 printf("Needed resources are:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=m;j++)
  {
   printf("%d ",ned[i][j]);
  }
  printf("\n");
 }
 for(i=1;(h!=n+1)&&(maximum<=m*n*n);i++)
 {
  ++maximum; 
  u=check(i,m);
  if(u==m)
  {
   fin[i]=1;
   ss[h]=i;
   h++;  
   for(j=1;j<=m;j++)
   {
    work[j]=work[j]+alc[i][j];
   }
  }
  else if(u!=m)
  {
   for(j=1;j<=m;j++)
   {
    work[j]=work[j]+alc[i][j];
    ned[i][j]=ned[i][j]+alc[i][j];
    alc[i][j]=0;
   }
  }
  if(i==n)
  {
   i=0;
  }
 }
 if(h>n)
 {
  printf("The safe sequence is:");
  for(i=1;i<=n;i++)
  {
   printf(" p%d ",ss[i]);
  }
  printf("\n");
 }
 else
 {
  printf("Dead lock occured\n");
 }
}
