#include<stdio.h>
#include<stdlib.h>
void main()
{
	int t;
	printf("enter size:");
	scanf("%d",&t);
	printf("enter no.of req:");
	int n,i;
	scanf("%d",&n);
	int a[n],visit[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		visit[i]=-1;
	}
	printf("enter head:");
	int h;
	scanf("%d",&h);
	int count=0,sum=0;
	printf("seq:");
	printf("%d ",h);
	while(count!=n)
	{
		int min=INT_MAX,idx=-1;
		for(i=0;i<n;i++)
		{
			if(visit[i]==-1)
		  {
			int x=abs(h-a[i]);
			if(x<min)
			{
				min=x;
				idx=i;
			}
		   }
		}
		if(idx!=-1)
		{
			sum=sum+min;
			visit[idx]=1;
			h=a[idx];
			printf("%d ",h);
			count++;
		}
	}
	printf("sum=%d",sum);
}
/*
200
8
98 183 41 122 14 124 65 67
*/