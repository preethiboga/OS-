#include<stdio.h>
int findminat(int a[][7],int n,int visit[])
{
	int i;
	int min=9999;
	int p=-1;
	for(i=0;i<n;i++)
	{
		if(a[i][1]<min && visit[i]==-1)
		{
			min=a[i][1];
			p=i;
		}
	}
	return p+1;
	
}
int find_min_prior(int a[][7],int n,int ct,int visit[])
{
	int i;
	int min=9999;
	int p=-1;
	for(i=0;i<n;i++)
	{
		if((a[i][1]<min || (a[i][1]==min && (a[i][3]<a[p][3] ||(a[i][3]==a[p][3] && a[i][2]<a[p][2]))))  && visit[i]==-1 && a[i][2]<=ct)
		{
			min=a[i][1];
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
	int n,ct=0,l=0,k=0;
	printf("enter no.of processes:");
	scanf("%d",&n);
	int visit[n],gchart[100];
	int a[n][7],i;
	for(i=0;i<n;i++)
	{
		a[i][0]=i+1;
		printf("enter priority,at,bt values:");
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		visit[i]=-1;
	}
	int min=9999,p=-1;
	for(i=0;i<n;i++)
	{
		if(a[i][2]<min||(a[i][2]==min && (a[i][1]<a[p][1] || (a[i][1]==a[p][1] && a[i][3]<a[p][3]))))
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
		gchart[l]=p+1;
		l++;
		a[p][4]=ct+a[p][3];
		visit[p]=1;
		k++;
		ct=a[p][4];	
	}
	else
	{
		gchart[l]=p+1;
		l++;
		a[p][4]=ct+a[p][3];
		visit[p]=1;
		k++;
		ct=a[p][4];		
	}
	while(1)
	{
		int p=find_min_prior(a,n,ct,visit);
		if(p==-1)
		{
			gchart[l]=-1;
			l++;
			p=findminat(a,n,visit);
			ct=a[p-1][2];
			p=find_min_prior(a,n,ct,visit);	
		}
		gchart[l]=p;
		l++;
		visit[p-1]=1;
		a[p-1][4]=ct+a[p-1][3];
		k++;
		ct=a[p-1][4];
		if(k==n)
		break;	
	}
	for(i=0;i<n;i++)
	{
		a[i][5]=a[i][4]-a[i][2];
		a[i][6]=a[i][5]-a[i][3];
	}
	printf("pno\tprior\tat\tbt\tct\ttat\twt\n");
	int j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<7;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("gnattchart:\n");
	for(i=0;i<l;i++)
	{
		if(gchart[i]==-1)
		printf("idle|");
		else
		printf("P%d|",gchart[i]);
	}
	
}
/*
7
2 0 3
6 2 5
3 1 4
5 4 2
7 6 9
4 5 4
10 7 10
*/