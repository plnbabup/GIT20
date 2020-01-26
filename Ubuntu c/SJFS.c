#include<stdio.h>
void main()
{
	//declaration section
	int tt[10],bt[10],wt[10],p[10],i,k,j,n;
	float awt=0,att=0;
	printf("Enter no of process:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter burst time of p%d:",i);
		scanf("%d",&bt[i]);
		p[i]=i;
	}
	//logic section
	printf("Now the process are scheduled as below:\n");
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(bt[i]>bt[j])
			{
				k=bt[i];
				bt[i]=bt[j];
				bt[j]=k;
				k=p[i];
				p[i]=p[j];
				p[j]=k;
			}
		}
		printf("p%d\t",p[i]);
	}
	printf("\n");
	for(i=1;i<=n;i++)
	{
		if(i==1)
		{
			wt[i]=0;
		}
		else
		{
			wt[i]=wt[i-1]+bt[i-1];
		}
		awt=awt+wt[i];
		printf("The waiting time of p%d:%d\n",p[i],wt[i]);
	}
	awt=awt/(float)n;
	for(i=1;i<=n;i++)
	{
		tt[i]=bt[i]+wt[i];
		att=att+tt[i];
		printf("The turn around time of p%d:%d\n",p[i],tt[i]);
	}
	att=att/(float)n;
	printf("Average waiting time:%f\n",awt);
	printf("Average turn around time:%f\n",att);
}
