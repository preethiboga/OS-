#include<stdio.h>
int lru(int time[],int nf)
{
	int i,min=time[0],pos=0;
	for(i=1;i<nf;i++)
	{
		if(time[i]<min)
		{
			min=time[i];
			pos=i;
		}
	}
	return pos;
}
void main()
{
	int np,nf;
	printf("enter no.of pages:");
	scanf("%d",&np);
	printf("enter no.of frames:");
	scanf("%d",&nf);
	int rs[np],frames[nf];
	int i;
	for(i=0;i<nf;i++)
	{
		frames[i]=-1;
	}
	printf("enter reference string:");
	for(i=0;i<np;i++)
	{
		scanf("%d",&rs[i]);
	}
	int time[nf],pf=0,counter=0,j,f1,f2,ph=0,pos;
	printf("rs\tpage-frames\t\thit/fault\n");
	for(i=0;i<np;i++)
	{
		f1=0,f2=0;
		printf("%d\t",rs[i]);
		for(j=0;j<nf;j++)
		{
			if(frames[j]==rs[i])
			{
				counter++;
				ph++;
				time[j]=counter;
				f1=1;
				f2=1;
				break;
			}
			
		}
		if(f1==0)
		{
		 for(j=0;j<nf;j++)
	     {
			if(frames[j]==-1)
			{
				counter++;
				pf++;
				time[j]=counter;
				frames[j]=rs[i];
				f2=1;
				break;
			}
			
	      }	
		}
		if(f2==0)
		{
			pos=lru(time,nf);
			pf++;
			counter++;
			time[pos]=counter;
			frames[pos]=rs[i];
		}
		for(j=0;j<nf;j++)
		{
				printf("%d ",frames[j]);
		       printf("\t");
		}
		if(f2==1 && f1==1)
		printf("hit");
		else
		printf("fault");
		printf("\n");
		
		
	}
	printf("total no.of pagefaults:%d\n",pf);
	printf("total no.of pagehits:%d",ph);
}
/*
20
3
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

10
3
2 3 4 2 1 3 7 5 4 3


12
4
1 2 3 4 1 2 5 1 2 3 4 5

*/