#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n,h;
	int t;
	printf("enter total no.of tracks:");
	scanf("%d",&t);
	printf("enter no.of tracks:");
	scanf("%d",&n);
	int a[n],vis[n];
	printf("enter track numbers:");
	int i;
	for(i=0;i<n;i++)
	{
		vis[i]=-1;
	   scanf("%d",&a[i]);
     }
	printf("enter head:");
	scanf("%d",&h);
	int j;
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
	/*for(i=0;i<n;i++)
	{
	   printf("%d ",a[i]);
     }
     printf("\n");*/
	int sum=0;
	printf("seq:");
	printf("%d ",h);
	for(i=n-1;i>=0;i--)
	{
		if(a[i]<h)
		{
			printf("%d ",a[i]);
			vis[i]=1;
		   int x=abs(h-a[i]);
		   sum=sum+x;
		   h=a[i];
	    }
		
   }

		t=0;
		printf("%d ",t);
		int x=abs(h-t);
		sum=sum+x;
		h=t;
	   for(i=0;i<n;i++)
	   {
	   	  
	   	  if(a[i]>h && vis[i]==-1)
	   	  {
	   	  	printf("%d ",a[i]);
	   	  	int x=abs(h-a[i]);
		    sum=sum+x;
		    h=a[i];	
		  }
	   }
	printf("\n%d",sum);
}
/*
200
8
98 183 41 122 14 124 65 67
53


200
9
55 58 39 18 90 160 150 38 184
100
*/