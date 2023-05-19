#include<stdio.h>
#include<stdlib.h>
void main()
{
	int t;
	printf("enter size:");
	scanf("%d",&t);
	int n;
	printf("enter req size:");
	scanf("%d",&n);
	printf("enter req array:");
	int a[n],visit[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		visit[i]=-1;
	}
	int h,i,j;
	printf("enter head:");
	scanf("%d",&h);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	int sum=0;
	printf("seq:");
	printf("%d ",h);
	for(i=n-1;i>=0;i--)
	{
		if(a[i]<h && visit[i]==-1)
		{
			sum=sum+abs(h-a[i]);
			h=a[i];
			printf("%d ",h);
			visit[i]=1;
		}
	}
	sum=sum+abs(h-0);
	h=0;
	printf("%d ",h);
	for(i=0;i<n;i++)
	{
		if(a[i]>h && visit[i]==-1)
		{
			sum=sum+abs(h-a[i]);
			h=a[i];
			visit[i]=1;
			printf("%d ",h);
		}
	}
	printf("sum=%d",sum);
	
}
/*
200
8
98 183 41 122 14 124 65 67
53
*/