#include<stdio.h>
#include<stdlib.h>
struct process{
	int pid;
	int at;
	int bt;
	int st;
	int ct;
	int tat;
	int rt;
	int wt;
};
int main()
{
	int n;
	int totaltat=0;
	int totalwt=0;
	float avgtat;
	float avgwt;
	printf("enter no.of process:");
	scanf("%d",&n);
	struct process p[n];
	int i;
	int visit[n];
	int gc[n];
	for(i=0;i<n;i++)
	{
		printf("enter process id:");
		scanf("%d",&p[i].pid);
		printf("enter at:");
		scanf("%d",&p[i].at);
		printf("enter bt:");
		scanf("%d",&p[i].bt);
		visit[i]=0;
	}
	int current_time=0,completed=0,j=0;
	while(completed!=n)
	{
		int minburst=INT_MAX;
		int idx=-1;
		for(i=0;i<n;i++)
		{
			if(p[i].at<=current_time && visit[i]==0)
			{
				if(p[i].bt<minburst)
				{
					minburst=p[i].bt;
					idx=i;
				}
				if(p[i].bt==minburst)
				{
					if(p[i].at<p[idx].at)
					{
						minburst=p[i].bt;
						idx=i;
					}
				}	
			}
    	}
		if(idx!=-1)
		{
				p[idx].st=current_time;
				p[idx].ct=p[idx].bt+p[idx].st;
				p[idx].tat=p[idx].ct-p[idx].at;
				p[idx].wt=p[idx].tat-p[idx].bt;
				p[idx].rt=p[idx].st-p[idx].at;
				totalwt+=p[idx].wt;
				totaltat+=p[idx].tat;
				visit[idx]=1;
				gc[j]=p[idx].pid;
				j++;
				completed++;
				current_time=p[idx].ct;
				
		}
		else
			{
				gc[j]=0;
				j++;
				current_time++;
			}	
	}
	printf("pid\tat\tbt\tst\tct\ttat\trt\twt\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t",p[i].pid,p[i].at,p[i].bt,p[i].st,p[i].ct,p[i].tat,p[i].rt,p[i].wt);
		printf("\n");
	}
	printf("Gnatt chart\n");
	{
		for(i=0;i<j;i++)
		printf("%d ",gc[i]);
	}
	printf("avgtat=%f",totaltat/n);
	printf("avgwt=%f",totalwt/n);
}