#include<stdio.h>
#include<stdlib.h>
struct node
{
	int pno;
	int at;
	int bt;
	struct node *next;
};
struct node *front=NULL;
struct node *createnode(int pno,int at,int bt)
{
	struct node *nn=(struct node*)malloc(sizeof(struct node));
	nn->pno=pno;
	nn->at=at;
	nn->bt=bt;
	nn->next=NULL;
	return nn;
}
void readyqueue(int pno,int at,int bt)
{
	struct node *temp,*nn;
	nn=createnode(pno,at,bt);
	temp=front;
	if(front==NULL || at<front->at)
	{
		nn->next=front;
		front=nn;
	}
	else
	{
		while(temp->next!=NULL && temp->next->at<=at)
		{
			temp=temp->next;
		}
		nn->next=temp->next;
		temp->next=nn;
	}
}
int roundrobin(int at[],int bt[],int ct[],int n,int tq)
{
	int i;
	for(i=0;i<n;i++)
	{
		readyqueue(i,at[i],bt[i]);
	}
	struct node *temp=front;
	int time=0;
	while(temp!=NULL)
	{
		if(temp->at>time)
		{
			printf("%d idle %d|",time,temp->at);
			time=temp->at;
		}
		if((temp->bt)>tq)
		{
			printf("%d p:%d %d|",time,temp->pno+1,time+tq);
			time=time+tq;
			readyqueue(temp->pno,time,temp->bt-tq);
			
		}
		else
		{
			printf("%d p:%d %d|",time,temp->pno+1,time+temp->bt);
			time=time+temp->bt;
			ct[temp->pno]=time;
			
		}
		temp=temp->next;
	}
}
int main()
{
	int n;
	printf("enter n:");
	scanf("%d",&n);
	int at[n],bt[n],i,ct[n],btt[n],tat[n],wt[n];
	printf("enter at:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&at[i]);
	}
	printf("enter bt:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
		btt[i]=bt[i];
	}
	int tq;
	printf("enter tq:");
	scanf("%d",&tq);
	roundrobin(at,btt,ct,n,tq);
	printf("\n");
	int tatt=0,wtt=0;
	for(i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
    }
	printf("pno\tat\tbt\tct\ttat\twt\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	/*printf("avg tat:%f",tatt/n);
	printf("avg wt:%f",wtt/n);*/
}
/*
6
7 4 6 2 5 3
3 7 5 4 6 8
3
*/
