#include<stdio.h>
void swap(int i,int j,int a[]){
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
int main(){
	int n;
	float sum=0,sum1=0;
	scanf("%d",&n);
	int at[n],bt[n],ct[n],m,p1[n],k,gc[n],time[100],i,j,p[n],min,index,t;
	for(i=0;i<n;i++){
		scanf("%d%d",&at[i],&bt[i]);
		p[i]=i+1;	
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(at[j]>at[j+1]){
				swap(j,j+1,at);
				swap(j,j+1,bt);
				swap(j,j+1,p);
			}
		}
	}
	t=0,i=0,j=0,k=0;
	while(i<n){
		if(at[i]>t){
			gc[j]=0;
			time[j]=at[i];
			t=time[j];
			j++;
		}
		else{
			gc[j]=p[i];
			time[j]=t+bt[i];
			t=time[j];
			ct[k]=t;
			p1[k]=p[i];
			k++;
			j++;
			i++;
		}
	}
	printf("ganchatt\n\n");
	for(i=0;i<j;i++){
		if(gc[i]==0)
			printf("ideal\t");
		else	
			printf("p%d\t",gc[i]);
	}
	printf("\n");
	for(i=0;i<j;i++){
		if(gc[i]==0)
			printf("%d\t",time[i]);
		else	
			printf("%d\t",time[i]);
	}
	int tat[n],wt[n];
	for(i=0;i<n;i++){
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
	}
for(i=0;i<n-1;i++){
		for(m=0;m<n-1;m++){
			if(p[m]>p[m+1]){
				swap(m,m+1,at);
				swap(m,m+1,bt);
				swap(m,m+1,p);
				swap(m,m+1,tat);
				swap(m,m+1,wt);
				swap(m,m+1,ct);
			}
		}
	}
	printf("\n\np\tat\tbt\tct\ttat\twt\n\n");
	for(i=0;i<n;i++){
		printf("p%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	for(i=0;i<n;i++){
		sum=sum+tat[i];
		sum1=sum1+wt[i];
	}
	sum=sum/n;
	sum1=sum1/n;
	printf("\n\naverage tat= %.2f\naverage wt= %.2f",sum,sum1);
}
/*
6
1 4
2 10
3 15
4 20
5 28
6 4


6
5 3
8 6
3 3
6 1
2 2
4 5


6
4 2
10 1
15 2
20 3
28 8
4 3

6
5 3
8 6
3 3
6 1
2 2
4 5

*/