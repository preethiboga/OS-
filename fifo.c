#include<stdio.h>
void main()
{
	int n;
	printf("enter no.of pages:");
	scanf("%d",&n);
	int rs[n];
	printf("enter reference string:");
	int i;
	for(i=1;i<=n;i++)
    {
    	scanf("%d",&rs[i]);
    }
	int f;
	printf("enter no.of frames:");
	scanf("%d",&f);
	int frames[f];
	for(int i=1;i<=f;i++)
	{
		frames[i]=-1;
	}
	printf("reference string is:");
	for(i=1;i<=n;i++)
	{
		printf("%d ",rs[i]);
	}
	printf("\n");
	int j=0,k,fcount=0;
	printf("\n");
	printf("rs\tpage-------frames\thit/fault\n");
	for(i=1;i<=n;i++)
	{
		int avail=0;
		printf("%d\t",rs[i]);
		for(k=0;k<f;k++)
		{
			if(frames[k]==rs[i])
			{
				avail=1;
				for(k=0;k<f;k++)
				{
					printf("%d ",frames[k]);
						printf("\t");
				}
				printf("hit");
			}
		}
		if(avail==0)
		{
				frames[j]=rs[i];
				j=((j+1)%f);
				fcount++;
				for(k=0;k<f;k++)
				{
					printf("%d ",frames[k]);
					printf("\t");
				}
				printf("fault");
		}
		printf("\n");
		
	}
	printf("total page faults=%d",fcount);
}
/*
10
0 2 5 6 4 5 2 1 3 2
3

20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
3
  
  
12
1 2 3 4 1 2 5 1 2 3 4 5
4
*/
