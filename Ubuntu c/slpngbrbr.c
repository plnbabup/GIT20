#include<stdio.h>
#include<stdlib.h>
int c[100],t[100],d[100],f=0,r=0,n,b=1,i,count,j,a,k,g;
void wait()
{
 --b;
}
void signal()
{
 ++b;
}


int del(int key,int sz)
{
 int p,e;
 for(p=1;p<=sz;p++)
 {
  if(d[p]==key)
  {
   for(e=p;e<sz;e++)
   {
    d[e]=d[e+1];
   }
  }
 }
 return sz-1;
}


void en(int v)
{
 if(r==0&&f==0)
 {
  f=1;
 }
 r=r+1;
 c[r]=v;
}

int de()
{
 int v;
 v=c[f];
 if(f==r)
 {
  r=0;
  f=0;
 }
 else
 {
  f=f+1;
 }
 return v;
}
 
void swap(int c[],int t[])
{
 int i,j,k;
 for(i=f;i<=r;i++)
 {
  for(j=i+1;j<=r;j++)
  {
   if(t[i]>t[j])
   {
    {
     k=t[i];
     t[i]=t[j];
     t[j]=k;
    }			
    {
     k=c[i];
     c[i]=c[j];
     c[j]=k;
    }	
   }
  }
 }
}


void main()
{
 printf("Enter no of clients:");
 scanf("%d",&n);
 if(n==0)
 {
  z:printf("Barber is sleeping as there are no customers\n");
  exit(1);
 }
 count=n;
 printf("Issue tokens for each client\n");
 for(i=1;i<=n;i++)
 {
  printf("Enter token for client %d :",i);
  scanf("%d",&t[i]);
  en(i);
  d[i]=i;
 }
 for(i=f;i<=r;i++)
 {
  printf("Token no of client %d : %d\n",c[i],t[i]);
 }
 swap(c,t);
 printf("\n");
 for(i=1;i<=n;i++)
 {
  if(b==1)
  {
   wait();
   g=de();
   printf("Client %d is getting hair cut\n",g);
   printf("clients waiting are:\t");
   count=del(g,count);
   if(count!=0)
   {
    for(j=1;j<=count;j++)
    {
      printf("%d\t",d[j]);
    }
    signal();
    printf("\nDo you wish to add new client [1/0] :");
    scanf("%d",&a);
    if(a==1)
    {
     ++r;
     ++count;
     ++n;
     printf("Issue token for client %d :",r);
     scanf("%d",&t[r]);
     c[r]=r;
     d[count]=r;
     swap(c,t);
    }
   }
   else
   {
    printf("0\n");
   }
  }
  printf("\n");
 }
 goto z;
}
