#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
 char dn[10],fn[10][10],ca[10];
 int cnt=1,ch,i,flg=0;
 printf("Enter the directory name:");
 scanf("%s",dn);
 while(1)
 {
  printf("1>create file\t2>search file\t3>delete file\t4>list directry\t5>Rename file\t6>Exit\nChoose the operation to be performed:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:printf("Enter name of file:");
          scanf("%s",fn[cnt]);
          cnt++;
          break;
   case 2:printf("Enter the file name:");
          scanf("%s",ca);
          flg=0;
          for(i=1;i<=cnt;i++)
          {
           if(strcmp(ca,fn[i])==0)
           {
            flg=1;
            break;
           }
          }
          if(flg==1)
          {
           printf("File found\n");
          }
          else
          {
           printf("File not found\n");
          }
          break;
   case 3:printf("Enter file to be deleted:");
          scanf("%s",ca);
          flg=0;
          for(i=1;i<=cnt;i++)
          {
           if(strcmp(ca,fn[i])==0)
           {
            flg=1;
            printf("File %s deleted\n",ca);
            strcpy(fn[i],fn[cnt-1]);
            cnt--;
            break;
           }
          }
          if(flg!=1)
          {
           printf("File not found\n");
          }
          break;
   case 4:for(i=1;i<cnt;i++)
          {
           printf("%s\n",fn[i]);
          }
          break;
   case 5:printf("Enter the file to be renamed:");
          scanf("%s",ca);
          flg=0;
          for(i=1;i<=cnt;i++)
          {
           if(strcmp(ca,fn[i])==0)
           {
            flg=1;
            break;
           }
          }
          if(flg==1)
          {
           printf("Enter new name:");
           scanf("%s",fn[i]);
          }
          else
          {
           printf("No such file in %s\n",dn);
          }
          break;
   default:exit(0);
  }
 }
}
          
  
