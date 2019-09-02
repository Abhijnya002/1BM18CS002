#include<stdio.h>
#define size 20
void insert(int item,int *r,int q[]);
void insert(int item,int *r,int q[])
{
	if(*r==size-1)
	{
		printf("queue overflow\n");
		return;
	}
	q[++(*r)]=item;
}
int main()
{
	int q[size];
	int i,n,ele;
	int r=-1;
	printf("enter the no.of process\n");
	scanf("%d",&n);
	printf("enter the burst time in seconds=\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&ele);
		insert(ele,&r,q);
	}
	printf("process 1 starts at 0th and ends at %d th second \n",q[0]);	
	for(i=1;i<n;i++)
	{
		q[i]=q[i-1]+q[i];
		printf("process %d starts at %d th and ends at %d th second \n",(i+1),q[i-1],q[i]);
	}
	return 0;
} 
