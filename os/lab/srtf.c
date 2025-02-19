#include <stdio.h>
void main()
{
	int at[20],bt[20],ct[20],tt[20],wt[20],temp[20],count=0,i,n,smallest,time;
	double avg_wt=0,avg_tt=0;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	printf("Enter the arrival time and burst time: \n");
	for(i=0;i<n;i++)
	{
		printf("Arrival time: ");
		scanf("%d",&at[i]);
		printf("Burst time: ");
		scanf("%d",&bt[i]);
		temp[i]=bt[i];
	}
	bt[9]=999;
	for(time=0;count !=n;time++)
	{
		smallest=9;
		for(i=0;i<n;i++)
		{
			if(at[i]<=time && bt[i]<bt[smallest] && bt[i]>0)
			{
				smallest=i;
			}
		}
		bt[smallest]--;
		if(bt[smallest]==0)
		{
			count++;
			ct[smallest]=time+1;
			tt[smallest]=ct[smallest]-at[smallest];
			wt[smallest]=tt[smallest]-temp[smallest];
		}
	}
	printf("AT\tBT\tPR\tCT\tTT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",at[i],temp[i],pr[i],ct[i],tt[i],wt[i]);
		avg_wt+=wt[i];
		avg_tt+=tt[i];
	}
	printf("Average TT=%f\nAverage WT=%f",avg_tt/n,avg_wt/n);
	printf("\n");
	printf("----------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
	printf("|\tP%d\t|",i+1);
	}
	printf("\n");
	printf("----------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
	printf("\t\t%d",ct[i]);
	}
}
