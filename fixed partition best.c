#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,m;
	printf("enter no.of process:");
	scanf("%d",&n);
	int size[n+1],a[n+1],visitp[n+1];
	int i;
	printf("enter sizes of process:");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&size[i]);
		visitp[i]=0;
	}
	printf("enter no.of blocks:");
	scanf("%d",&m);
	int block[m+1],visit[m+1];
	printf("enter block sizes:");
	for(i=1;i<=m;i++)
	{
		scanf("%d",&block[i]);
		visit[i]=-1;
	}
	int k=1,count=0,sum=0;
	while(k<=n)
	{
		int min=INT_MAX;
		int index=-1;
		for(i=1;i<=m;i++)
		{
			if(block[i]>=size[k] && visit[i]==-1 && block[i]<min)
			{
				min=block[i];
				index=i;
			}
		}
		if(index!=-1)
		{
				visit[index]=k;
				block[index]=block[index]-size[k];
				k++;
		}
	    else
		{
			a[count]=k;
			count++;
			printf("process-%d cannot insert into memory\n",k);
			k++;
		}
	}
	printf("process allocation:\n");
	for(i=1;i<=m;i++)
	{
		if(visit[i]!=-1)
		printf("process-%d------>block-%d\n",visit[i],i);
	}
	for(i=1;i<=m;i++)
	{
		if(visit[i]!=-1)
		sum=sum+block[i];
	}
	printf("internal fragmentation=%d\n",sum);
	if(count!=0)
	{
		sum=0;
		for(i=1;i<=m;i++)
		{
			if(visit[i]==-1)
			sum=sum+block[i];
		}
		for(i=0;i<count;i++)
		{
			if(sum>=size[a[i]])
			break;
		}
		if(i<count)
		{
			printf("external fragmentation=%d",sum);
		}
	}
	
}
/*
4 
212
417
112
426
5
100
500
200
300
600
*/