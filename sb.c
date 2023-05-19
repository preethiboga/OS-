
#include<stdio.h>
int alloc[100][100],max[100][100],avail[100],need[100][100];
int n,r;
void print(int seq[])
{
	for(int i=1;i<=n;i++)
	{
		printf("p%d ",seq[i]);
	}
	printf("\n");
}
int che(int i,int n,int r,int work[])
{
	int p=-1;
	for(int j=1;j<=r;j++)
	{
		if(work[j]<need[i][j])
		{
			p=1;
			break;
		}
	}
	return p;
}
void safe(int work[],int k,int finish[],int seq[])
{
	if(k>n)
	{
		print(seq);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		int p= che(i,n,r,work);
		if(p==-1 && finish[i]==-1)
		{
			finish[i]=1;
			seq[k]=i;
			for(int j=1;j<=r;j++)
			{
				work[j]=work[j]+alloc[i][j];
			}
			safe(work,k+1,finish,seq);
			for(int j=1;j<=r;j++)
			{
				work[j]=work[j]-alloc[i][j];
			}
			finish[i]=-1;
			
		}
	}
}
void main()
{
	
	printf("enter no.of processes:");
	scanf("%d",&n);
	printf("enter no.of resources:");
	scanf("%d",&r);
	int i,j;
	int finish[n],seq[n];
	int work[r];
	printf("enter allocation matrix:");
	for(i=1;i<=n;i++)
	{
		finish[i]=-1;
		for(j=1;j<=r;j++)
		scanf("%d",&alloc[i][j]);
	}
	printf("enter max matrix:");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=r;j++)
		scanf("%d",&max[i][j]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=r;j++)
		need[i][j]=max[i][j]-alloc[i][j];
	}
	int k=1;
	printf("enter resources:");
	for(i=1;i<=r;i++)
	{
		scanf("%d",&avail[i]);
		work[i]=avail[i];
	}
	safe(work,k,finish,seq);
}