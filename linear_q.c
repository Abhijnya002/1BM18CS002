#include<stdio.h>
#define size 10
void insert(int item,int *r,int q[]);
int delet(int q[],int *f,int *r);
void display(int q[],int r,int f);
void insert(int item,int *r,int q[])
{
	if(*r==size-1)
	{
		printf("queue is full \n");
		return;
	}
		*r=*r+1;
		q[*r]=item;
}
int delet(int q[],int *f,int *r)
{
	int item;
	if(*f==-1)
	{
		printf("queue is empty\n");
		return -9999;
	}
	item=q[*f];
	if(*f>*r)
	{
		
		printf("queue underflow\n");
		return -9999;
	}
	else
		item=q[*f];
		*f=(*f+1);
		return item;
}
void display(int q[],int r,int f)
{
	int i;
	if(f>r)
	{
		printf("queue is empty\n");
		return;
	}
	printf("contents of queue are :\n");
	for(i=f;i<=r;i++)
	printf(" %d\n",q[i]);
	
}
int main()
{
	int q[size],item,ch,ch_q;
	int f=0,r=-1,e,s,i,n;
	printf("enter choice=");
	scanf("%d",&ch);
	while(ch!=0){
	switch(ch)
	{
		case 1:printf("enter the no.of elements to be inserted \n");
				scanf("%d",&n);
				printf("enter the elements to be inserted\n");
				for(i=0;i<n;i++)
				{
					scanf("%d",&item);
					insert(item,&r,q);
				}
		
			break;
		case 2:e=delet( q, &f, &r);
			printf("deleted ele is %d\n",e);
			break;
		case 3: display( q, r,f);
			break;
		default: break;
	}
	printf("again enter 1 to insert,2 to delete,3 to display,0 to exit=");
	scanf("%d",&ch);
	}
	return 0;
}
