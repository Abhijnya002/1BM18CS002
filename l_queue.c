#include<stdio.h>
#define size 100

void insert(int item,int *r,int q[],int *f)
{
	if((*f==*r+1)//(*f==0&&*r=size-1))
	{
		printf("queue is full \n");
		return;
	}
	if(*f==-1)
		*f=0;
		*r=(*r+1)%size;
		q[*r]=item;
}
int delete(int q[],int *f,int *r)
{
	int item;
	if(*f==1)
	{
		printf("queue is empty");
		return -9999;
	}
	else
	{
		item=q[*f];
		if(*f==*r)
		{
		*f=-1;
		*r=-1;
		}
		else
		*f=(*f+1)%size;
		return item;
	}
}
void display(int q[],int f,int r)
{
	int i;
	if(*f==-1)
	{
		printf("queue is empty");
		return;
	}
	printf("contents of queue=");
	for(i=f;i!=r;(i++)%size)
	{
		printf("%d\n",q[i]);
	}
	printf("%d\n",q[i]);
}
void main()
{
	int q[size],item,ch,ch_q;
	int f=-1,r=-1,e;
	printf("enter choice=");
	scanf("%d",&ch);
	do{
	switch(ch)
	{
		case 1:insert(int item,int *r,int q[],int *f);
			break;
		case 2:e= delete(int q[],int *f,int *r);
			printf("deleted ele is %d",e);
			break;
		case 3: display(int q[],int f,int r);
			break;
		default:break;
	}
	printf("do u want to continue(1/0)?\n");
	scanf("%d",&ch_q);
	}while(ch_q!=0);
}

	
