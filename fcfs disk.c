#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n,h;
	printf("enter no.of tracks:");
	scanf("%d",&n);
	int a[n];
	printf("enter track numbers:");
	int i;
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("enter head:");
	scanf("%d",&h);
	int sum=0;
	for(i=0;i<n;i++)
	{
		int x=abs(h-a[i]);
		sum=sum+x;
		h=a[i];
		
	}
	printf("%d",sum);
}
/*
8
98 183 41 122 14 124 65 67
*/