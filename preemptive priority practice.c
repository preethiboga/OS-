#include<stdio.h>
int findminprior(int a[][7],int n,int ct,int visit[])
{
	int min=999;
	int p=-1,i;
	for(i=1;i<=n;i++)
	{
		if((a[i][1]<min || (a[i][1]==min && (a[i][3]<a[p][3] || (a[i][3]==a[p][3] && a[i][2]<a[p][2])))) && visit[i]==-1 && a[i][2]<=ct)
		{
			min=a[i][1];
			p=i;
		}
	}
	return p;
}
int findminat(int a[][7],int n,int visit[])
{
	int i,min=999,p;
	for(i=1;i<=n;i++)
	{
		if((a[i][2]<min || (min==a[i][2] && (a[i][1]<a[p][1] || (a[i][1]==a[p][1] && a[i][3]<a[p][3]))))&& visit[i]==-1)
		{
			min =a[i][2];
			p=i;
		}
	}
	return p;
}
void main()
{
	int n;
	printf("enter no.of process:");
	scanf("%d",&n);
	int i,a[n][7],l=0,k=0,ct=0,bt[n],visit[n],gchart[100];
	for(i=1;i<=n;i++)
	{
		a[i][0]=i;
		printf("enter priority,at,bt:");
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		bt[i]=a[i][3];
		a[i][4]=0;
		visit[i]=-1;	
	}
	int p=-1,min=9999;
	for(i=1;i<=n;i++)
	{
		if(a[i][2]<min||(min==a[i][2] && (a[i][1]<a[p][1] || (a[i][1]==a[p][1] && a[i][3]<a[p][3]))))
		{
			min=a[i][2];
			p=i;
		}
	}
	ct=min;
	if(min!=0)
	{
		gchart[l]=-1;
		l++;
		gchart[l]=p;
		l++;
		a[p][4]++;
		a[p][3]--;
		ct=a[p][4];	
	}
	else
	{
		gchart[l]=p;
		l++;
		a[p][4]++;
		a[p][3]--;	
		ct=a[p][4];
	}
	if(a[p][3]==0)
	{
		k++;
		visit[i]=1;
	}
	while(k!=n)
	{
		p=findminprior(a,n,ct,visit);
		if(p==-1)
		{
			gchart[l]=-1;
			l++;
			p=findminat(a,n,visit);	
			ct=a[p][2];
			p=findminprior(a,n,ct,visit);
		}
		a[p][3]--;
		if(gchart[l-1]==p)
		{
		   a[p][4]=ct+1;
		   ct=a[p][4];	
		}
		else
		{
			gchart[l]=p;
			l++;
			a[p][4]=ct+1;
			ct=a[p][4];
		}
		if(a[p][3]==0)
		{
			visit[p]=1;
			k++;
		}
	}
	for(i=1;i<=n;i++)
	{
		a[i][5]=a[i][4]-a[i][2];
		a[i][6]=a[i][5]-bt[i];
	}
	int j;
	printf("P\tPRI\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=1;i<=n;i++)
	{
		printf("P%d\t",i);
		a[i][3]=bt[i];
		for(j=1;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("gnattchart:\n");
	for(i=0;i<l;i++)
	{
		if(gchart[i]==-1)
		{
			printf("idle|");	
		}
		else
		printf("p%d|",gchart[i]);
	}
}
/*
7
2 0 4
4 1 2
6 2 3
1 3 5
8 4 1
3 5 4
2 11 6
*/