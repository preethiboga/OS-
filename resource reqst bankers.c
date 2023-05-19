#include<stdio.h>
int n,r;
int allocation[100][100],maxneed[100][100],need[100][100],available[100],re[100];
int check(int work[],int n,int r,int i)
{
	int j,flag=-1;
	for(j=1;j<=r;j++)
	{
		if(work[j]<need[i][j])
		{
			flag=1;
			break;
		}
	}
	return flag;
}
int printing(int seq[])
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("p%d ",seq[i]);
	}
	printf("\n");
}
int safety_sequence(int seq[],int finish[],int work[],int k)
{
	int i,p,j;
	if(k>n)
	{
		printing(seq);
		return;
	}
	for(i=1;i<=n;i++)
	{
		p=check(work,n,r,i);
		if(p==-1 && finish[i]==-1)
		{
			seq[k]=i;
			finish[i]=1;
			for(j=1;j<=r;j++)
			{
				work[j]=work[j]+allocation[i][j];
			}
			safety_sequence(seq,finish,work,k+1);
			for(j=1;j<=r;j++)
			{
				work[j]=work[j]-allocation[i][j];
			}
			finish[i]=-1;
			
		}
		
	}
	
}
int main()
{
	int i,j;
	printf("enter no.of process:");
	scanf("%d",&n);
	printf("enter no.of resources:");
	scanf("%d",&r);
	int finish[n],work[r],seq[n];
	printf("enter allocation matrix:");
	for(i=1;i<=n;i++)
	{
		finish[i]=-1;
		for(j=1;j<=r;j++)
		scanf("%d",&allocation[i][j]);
	}
	printf("enter maxneed matrix:");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=r;j++)
		scanf("%d",&maxneed[i][j]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=r;j++)
		need[i][j]=maxneed[i][j]-allocation[i][j];
	}
	printf("enter available instances:");
	for(i=1;i<=r;i++)
	{
		scanf("%d",&available[i]);
		work[i]=available[i];
	}
	printf("enter reqest array:");
	for(i=1;i<=r;i++)
	{
		scanf("%d",&re[i]);
	}
	int k=1;
	int fg=-1;
	i=2;
	for(j=1;j<=r;j++)
	{
		if(re[j]>need[i][j])
		{
			if(re[j]>available[j])
			{
				fg=1;
				break;
			}
		}
		
	}
	if(fg==-1)
	{
		for(j=1;j<=r;j++)
		{
			allocation[i][j]=allocation[i][j]+re[j];
			available[j]=available[j]-re[j];
			work[j]=available[j];
			need[i][j]=need[i][j]-re[j];
		}
	}
	printf("need matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=r;j++)
		printf("%d ",need[i][j]);
		printf("\n");
	}
	printf("available matrix:\n");
	for(i=1;i<=r;i++)
	{
		
			printf("%d ",available[i]);
	}
	printf("\n");
	safety_sequence(seq,finish,work,k);	
}
/*
5
3
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

3 3 2
1 0 2
*/