#include<stdio.h>
void main()
{
	int n;
	printf("enter no.of process:");
	scanf("%d",&n);
	int size[n+1],store[n+1],i,m,a[n+1];
	printf("enter process sizes:");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&size[i]);
		store[i]=-1;
	}
	printf("enter no.of blocks:");
	scanf("%d",&m);
	int block[m+1],visit[m+1];
	printf("enter blocks sizes:");
	for(i=1;i<=m;i++)
	{
		scanf("%d",&block[i]);
		visit[i]=-1;
	}
	int k=1,count=0;
	while(k<=n)
	{
		int index=-1,max=-1;
		for(i=1;i<=m;i++)
		{
			if(size[k]<=block[i] && block[i]>max)
			{
				max=block[i];
				index=i;
			}
		}
		if(index!=-1)
		{
			store[k]=index;
			block[index]=block[index]-size[k];
			visit[index]=1;
			k++;
		}
		else
		{
			a[count]=k;
			printf("memory can't allocated to process=%d\n",k);
			k++;
			count++;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(store[i]!=-1)
		printf("process-%d--->block-%d\n",i,store[i]);
	}
	int sum=0;
	if(count!=0)
	{
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
			printf("external fragmentation=%d\n",sum);
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