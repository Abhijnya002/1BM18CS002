#include<stdio.h>
#include<conio.h>
#define size 10
void insert(int item,int *r,int q[],int *f);
int delet(int q[],int *f,int *r);
void display(int q[],int f,int r);
void insert(int item,int *r,int q[],int *f)
{
	if((*f==*r+1)||(*f==0)&&(*r==size-1))
	{
		printf("queue is full \n");
		return;
	}
	if(*f==-1)
		*f=0;
		*r=(*r+1)%size;
		q[*r]=item;
}
int delet(int q[],int *f,int *r)
{
	int item;
	if(*f==1)
	{
		printf("queue is empty\n");
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
	if(f == -1)
	{
		printf("queue is empty\n");
		return;
	}
	printf("contents of queue=\n");
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
	clrscr();
	printf("enter choice=");
	scanf("%d",&ch);
	do{
	switch(ch)
	{
		case 1:insert(1,&r,q,&f);
			insert(2,&r,q,&f);
			display(q,f,r);
			break;
		case 2:e=delet( q, &f, &r);
			printf("deleted ele is %d\n",e);
			break;
		case 3: display( q, f, r);
			break;
		default: break;
	}
	printf("again enter 1 to insert,2 to delete,3 to display,0 to exit=");
	scanf("%d",&ch);
	}while(ch!=0);
	getch();
}