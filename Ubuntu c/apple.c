#include<stdio.h>
#include<string.h>
void main()
{
 char a[10];
 int n,i,j,k=0,l;
 printf("Enter the string:");
 scanf("%s",a);
 n=strlen(a);
 l=n-1;
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   if(i==j)
   {
    printf("%c",a[k]);
    k++;
   }
   else if(i+j==(n-1))
   {
    printf("%c",a[l]);
   }
   else
   {
    printf(" ");
   }
  }
  l=n-(i+2);
  printf("\n");
 }
}   
