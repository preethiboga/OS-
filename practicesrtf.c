#include<stdio.h>
#include<stdlib.h>
int findminbt(int a[][6],int n,int ct,int j,int visit[])
{
	int min=9999,p=-1,i;
	for(i=1;i<=n;i++)
	{
		if((a[i][2]<min ||(min==a[i][2] && a[i][1]<=a[p][1])) && visit[i]==-1 && a[i][1]<=ct)
		{
			min=a[i][2];
			p=i;
		}
	}
	if(p==-1)
	return -1;
	else 
	return p;
}
int findminat(int a[][6],int n,int j,int visit[])
{
	int min=999,p,i;
	for(i=1;i<=n;i++)
	{
		if(a[i][1]<min && visit[i]==-1)
		{
			min=a[i][1];
			p=i;
		}
	}
	return p;
}
void main()
{
	int n;
	printf("enter no.of processes:");
	scanf("%d",&n);
	int a[n][6],gchart[100],visit[n],bt[n];
	int i;
	for(i=1;i<=n;i++)
	{
		a[i][0]=i;
		visit[i]=-1;
	}
	for(i=1;i<=n;i++)
	{
		printf("enter at,bt values:");
		scanf("%d%d",&a[i][1],&a[i][2]);
		a[i][3]=0;
		bt[i]=a[i][2];
	}
	int p=-1;
	int min=999,l=0,k=0,ct=0;
	for(i=1;i<=n;i++)
	{
		if(a[i][1]<min || (a[i][1]==min && a[i][2]<a[p][2]))
		{
			min=a[i][1];
			p=i;
		}	
	}
	//printf("%d\n%d",p,min);
	ct=min;
	if(min!=0)
	{
		gchart[l]=-1;
		l++;
		gchart[l]=p;
		l++;
		a[p][2]=a[p][2]-1;
		a[p][3]++;
		ct=ct+1;
		//ct=a[p][3];
	}
	else
	{
		gchart[l]=p;
		l++;
		a[p][2]=a[p][2]-1;
		a[p][3]++;
		ct=ct+1;
		//ct=a[p][3];	
	}
	if(a[p][2]==0)
	{
		visit[p]=1;
		k++;
	}
	while(k!=n)
	{
		p=findminbt(a,n,ct,2,visit);
		if(p==-1)
		{
			gchart[l]=-1;
			l++;
			p=findminat(a,n,1,visit);
			ct=a[p][1];
			p=findminbt(a,n,ct,2,visit);
		}
		a[p][2]--;
		if(gchart[l-1]==p)
		{
			a[p][3]=ct+1;
			ct=a[p][3];	
		}
		else
		{
			gchart[l]=p;
			l++;
			a[p][3]=ct+1;
			ct=a[p][3];
		}
		if(a[p][2]==0)
		{
			k++;
			visit[p]=1;
			
		}
	}
	int j=0;
	for(i=0;i<n;i++)
	{
		a[i][4]=a[i][3]-a[i][1];
		a[i][5]=a[i][4]-bt[i];
	}
    printf("P\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=1;i<=n;i++)
	{
		printf("P%d\t",i);
		a[i][2]=bt[i];
		for(j=1;j<6;j++)
		{
		    printf("%d\t",a[i][j]);
	    }
	    printf("\n");
	}
	printf("gnatt chart:");
	for(i=0;i<l;i++)
	{
		if(gchart[i]==-1)
		{
			printf("IDLE|");
		}
		else
		{
			printf("P%d|",gchart[i]);
		}
	}
}
/*
7
5 1
2 1
4 3
1 10
3 4
1 8
2 6 
*/