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
	float totaltat=0;
	float totalwt=0;
	printf("enter no.of process:");
	scanf("%d",&n);
	struct process p[n];
	int i;
	int visit[n];
	int gc[n];
	int burstremaining[n];
	for(i=0;i<n;i++)
	{
		printf("enter process id:");
		scanf("%d",&p[i].pid);
		printf("enter at:");
		scanf("%d",&p[i].at);
		printf("enter bt:");
		scanf("%d",&p[i].bt);
		burstremaining[i]=p[i].bt;
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
				if(burstremaining[i]<minburst)
				{
					minburst=burstremaining[i];
					idx=i;
				}
				if(burstremaining[i]==minburst)
				{
					if(p[i].at<p[idx].at)
					{
						minburst=burstremaining[i];
						idx=i;
					}
				}	
			}
    	}
		if(idx!=-1)
			{
				if(p[idx].bt==burstremaining[idx])
				{
					p[idx].st=current_time;
				}
				burstremaining[idx]--;
				//gc[j++]=p[idx].pid;
				current_time++;
				if(burstremaining[idx]==0)
				{
					p[idx].ct=current_time;
					p[idx].tat=p[idx].ct-p[idx].at;
					p[idx].wt=p[idx].tat-p[idx].bt;
					p[idx].rt=p[idx].st-p[idx].at;
					totalwt+=p[idx].wt;
					totaltat+=p[idx].tat;
					visit[idx]=1;
					gc[j++]=p[idx].pid;
					completed++;
			    }
				
			}
			else
			{
				gc[j++]=0;
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
		printf("%d |",gc[i]);
	}
	printf("avg tat=%f",totaltat/n);
	printf("avg wt=%f",totalwt/n);
}