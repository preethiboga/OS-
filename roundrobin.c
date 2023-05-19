#include<stdio.h>
int st=-1,end=-1;
int e=0;
int queue[100];
int find_min(int n,int a[][6],int vis[])
{
	int j,min=999,flag;
	for(j=1;j<=n;j++)
	{
		if(a[j][1]<min && vis[j]==-1)
		{
	     	min=a[j][1];
	     	flag=j;
		}
	}
	return flag;
}
int find_min1(int n,int a[][6],int visit[],int ct)
{
	int min=999,flag=-1,i;
	for(i=1;i<=n;i++)
	{
		if(a[i][1]<min && a[i][1]<=ct && visit[i]==-1 )
		{
			min=a[i][1];
			flag=i;
		}
	}
	return flag;
}

int find_process(int n,int a[][6],int visit[],int ct)
{
	int p=find_min1(n,a,visit,ct);
	while(p!=-1)
	{
		enqueue(p);
		visit[p]=1;
		e++;
		p=find_min1(n,a,visit,ct);
	}
}
int enqueue(int p)
{
	if(st==-1)
	{
		st=0;
		end=0;
		queue[end]=p;
	}
	else
	{
		end++;
		queue[end]=p;	
	}
}
int dequeue()
{
	if(st==-1)
	{
		return -1;
	}
	if(st==end)
	{
		int r=queue[st];
		st=-1;
		end=-1;	
		return r;
	}
	else
	{
		int r=queue[st];
		st++;
		return r;	
	}
	
}

void main()
{
	int n,i,TQ,j,ct=0;
	printf("enter no.of process:");
	scanf("%d",&n);
	int a[n][6],vis[n],visit[n],gchart[100],bt[n];
	printf("enter timequantum:");
	scanf("%d",&TQ);
	for(i=1;i<=n;i++)
	{
		vis[i]=-1;
		visit[i]=-1;
		a[i][0]=i;
	}
	for(i=1;i<=n;i++)
	{
		printf("enter at,bt values:");
		scanf("%d%d",&a[i][1],&a[i][2]);
		bt[i]=a[i][2];
	}
	int p=-1,l=0,k=0,min=9999;
	for(i=1;i<=n;i++)
	{
		if(a[i][1]<min)
		{
			min=a[i][1];
		}
	}
	ct=0;
	if(min!=0)
	{
		ct=min;
		gchart[l]=-1;
		l++;
	}
	find_process(n,a,visit,ct);
	p=dequeue();
	gchart[l]=p;
	l++;
	if(a[p][2]>TQ)
	{
		a[p][2]=(a[p][2]-TQ);
		ct=ct+TQ;
	}
	else
	{
		ct=ct+a[p][2];
		a[p][3]=ct;
		a[p][2]=0;
		vis[p]=1;
		k++;
	}
	while(k!=n)
	{
		if(e!=n)
		{
			find_process(n,a,visit,ct);
			if(a[p][2]!=0)
			{
				enqueue(p);
			}
		}
		p=dequeue();
		if(p==-1)
		{
			gchart[l]=-1;
			l++;
			p=find_min(n,a,vis);
			ct=a[p][1];
			find_process(n,a,visit,ct);
			p=dequeue();
		}
		if(gchart[l-1]!=p)
		{
			gchart[l]=p;
			l++;
		}
		if(a[p][2]>TQ)
		{
			a[p][2]=(a[p][2]-TQ);
			ct=ct+TQ;
			if(e==n)
			enqueue(p);
		}
		else
		{
			ct=ct+a[p][2];
			a[p][3]=ct;
			a[p][2]=0;
			vis[p]=1;
			k++;
		
		}
	}
	printf("pno\tat\tbt\tct\n");
	for(i=1;i<=n;i++)
	{
		a[i][2]=bt[i];
		for(j=0;j<4;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<l;i++)
	{
		if(gchart[i]==-1)
		printf("idle|");
		else
		printf("p%d|",gchart[i]);
	}
	
	
}
/*
6
3
7 3
4 7
6 5
2 4
5 6
3 8
*/
