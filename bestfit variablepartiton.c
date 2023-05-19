#include<stdio.h>
void main()
{
	int n;
	printf("enter no.of process:");
	scanf("%d",&n);
	int i,size[n+1],store[n+1],a[n+1];
	printf("enter sizes of process:\n");
	for(i=1;i<=n;i++)
	{
		printf("enter size of process-%d:",i);
		scanf("%d",&size[i]);
		store[i]=-1;
	}
	printf("enter no.of memory blocks:");
	int m;
	scanf("%d",&m);
	int block[m+1],visit[m+1];
	printf("enter sizes of blocks:\n");
	for(i=1;i<=m;i++)
	{
		printf("enter size of block-%d:",i);
		scanf("%d",&block[i]);
		visit[i]=-1;
	}
	int k=1,count=0;
	while(k<=n)
	{
		int min=9999,flag=-1;
		for(i=1;i<=m;i++)
		{
			if(size[k]<=block[i] && block[i]<=min)
			{
				flag=i;
				min=block[i];
			}
		}
		if(flag!=-1)
		{
			store[k]=flag;
			visit[flag]=1;
			block[flag]=block[flag]-size[k];
			k++;	
		}
		else
		{
			a[count]=k;
			count++;
			k++;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(store[i]!=-1)
		{
			printf("process-%d->block %d\n",i,store[i]);
		}
	}
	int sum=0;
	if(count!=0)
	{
		for(i=1;i<=m;i++)
		{
			if(visit[i]==-1)
			{
				sum=sum+block[i];
			}
		}
		for(i=0;i<count;i++)
		{
			if(sum>=size[a[i]])
			{
				break;
			}
		}
		if(i<count)
		printf("external fragmentation=%d",sum);
	}	
	
}