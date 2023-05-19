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
	for(i=0;i<n;i++)
	{
		if(a[i]>h && visit[i]==-1)
		{
			sum=sum+abs(a[i]-h);
			h=a[i];
			printf("%d ",h);
			visit[i]=1;
		}
	}
	for(i=n-1;i>=0;i--)
	{
		if(a[i]<h && visit[i]==-1)
		{
			sum=sum+abs(a[i]-h);
			h=a[i];
			printf("%d ",h);
			visit[i]=1;
		}
	}
	printf("\nsum=%d\n",sum);
}