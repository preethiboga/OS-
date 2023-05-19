#include<stdio.h>
/*int search(int p,int frames[],int fn)
{
	int i;
	for(i=0;i<fn;i++)
	{
		if(frames[i]==p)
		return i;
	}
	return -1;
}*/
int find(int pages[],int frames[],int fn,int pn,int p)
{
	int i,j;
	int res=-1,far=p;
	for(i=0;i<fn;i++)
	{
		for(j=p;j<pn;j++)
		{
			if(frames[i]==pages[j])
			{
				if(j>far)
				{
					far=j;
					res=i;
				}
				break;
			}
		}
		if(j==pn)
		return i;
	}
	return (res==-1)?0:res;
	
}
void main()
{
	int pn,i;
	printf("enter no.of pages:");
	scanf("%d",&pn);
	int fn;
	printf("enter no.of frames:");
	scanf("%d",&fn);
	int pages[pn],frames[fn];
	printf("enter reference string:");
	for(i=0;i<pn;i++)
	{
		scanf("%d",&pages[i]);
	}
	for(i=0;i<fn;i++)
	{
		frames[i]=-1;
	}
	int hit=0,fault=0;
	printf("page\tpage----------frames\t\tfault/hit\n");
	for(i=0;i<pn;i++)
	{
		printf("%d\t",pages[i]);
		int flag1=0,flag2=0;
		for(int j=0;j<fn;j++)
		{
			if(frames[j]==pages[i])
			{
				hit++;
				flag1=1;
				flag2=1;
				break;
			}
		}
		if(flag1==0)
		{
			for(int j=0;j<fn;j++)
			{
				if(frames[j]==-1)
				{
					frames[j]=pages[i];
					fault++;
					flag2=1;
					break;
				}
			}
		}
		if(flag2==0)
		{
			int ind=find(pages,frames,fn,pn,i+1);
			frames[ind]=pages[i];
			fault++;
			
		}
		for(int k=0;k<fn;k++)
		{
			printf("%d\t",frames[i]);
		}
		if(flag1==1 && flag2==1)
		printf("hit\n");
		else
		printf("fault\n");
    }
	printf("total no.of faults=%d\n",fault);
	printf("total no.of hits=%d",hit);
}
/*
20
3
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
*/