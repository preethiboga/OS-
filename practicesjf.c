#include<stdio.h>
#include<stdlib.h>
int findminat(int a[][6],int n,int visit[])
{
	int i,min=9999,p=-1;
	for(i=0;i<n;i++)
	{
		if(a[i][1]<min && visit[i]==-1)
		{
			p=i;
			min=a[i][1];	
		}
	}
	return p+1;
	
}
int findmin(int a[][6],int n,int visit[],int ct)
{
	int p=-1;
	int min=9999;
	int i;
	for(i=0;i<n;i++)
	{
		if((a[i][2]<min||(a[i][2]==min && a[i][1]<a[p][1])) && visit[i]==-1 && a[i][1]<=ct)
		{
			min=a[i][2];
			p=i;
		}
	}
	if(p==-1)
	return -1;
	else
	return p+1;
}
void main()
{
	int n,k=0;
	printf("enter no.of processes:");
	scanf("%d",&n);
	int visit[n],a[n][6],gchart[100],l=0;
	int i;
	for(i=0;i<n;i++)
	{
		a[i][0]=i+1;
		visit[i]=-1;
		printf("enter at,bt values:");
		scanf("%d%d",&a[i][1],&a[i][2]);
	}
	int ct=0,p=-1,min=9999;
	for(i=0;i<n;i++)
	{
		if(a[i][1]<min||(a[i][1]==min && a[i][2]<a[p][2]))
		{
			min=a[i][1];
			p=i;
		}
	}
	ct=min;
	if(min!=0)
	{
		gchart[l]=-1;
		l++;
		gchart[l]=p+1;
		l++;
		visit[p]=1;
		a[p][3]=a[p][1]+a[p][2];	
		ct=a[p][3];
		k++;
	}
	else
	{
		gchart[l]=p+1;
		l++;
		visit[p]=1;
		k++;
		a[p][3]=a[p][1]+a[p][2];	
		ct=a[p][3];	
	}
	while(1)
	{
		p=findmin(a,n,visit,ct);
		if(p==-1)
		{
			gchart[l]=-1;
			l++;
			p=findminat(a,n,visit);	
			ct=a[p-1][1];
			p=findmin(a,n,visit,ct);
		}
		gchart[l]=p;
		l++;
		visit[p-1]=1;
		a[p-1][3]=ct+a[p-1][2];
		ct=a[p-1][3];
		k++;
		if(k==n)
		break;	
	}
	for(i=0;i<n;i++)
	{
		a[i][4]=a[i][3]-a[i][1];
		a[i][5]=a[i][4]-a[i][2];
	}
	int j=0;
	printf("pno\tat\tbt\tct\ttat\twt\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<6;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("gnattchart:");
	for(i=0;i<l;i++)
	{
		if(gchart[i]==-1)
		{
			printf("idle|");
		}
		else
		printf("%d|",gchart[i]);
	}
}
/*
6
4 2
10 1
15 2
20 3
28 8
4 3
*/