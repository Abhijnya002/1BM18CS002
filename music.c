#include<stdio.h>
#include<string.h>
#define size 10
void insert(char item[],int *r,char q[],int *f);
void delet(char q[],int *f,int *r);
void display(char q[],int r,int f);
void insert(char item[],int *r,char q[],int *f)
{
	if((*f==*r+1)||(*f==0)&&(*r==size-1))
	{
		printf("queue is full \n");
		return;
	}
	if(*f==-1)
		*f=0;
		*r=(*r+1)%size;
		q[*r]=*item;
}
void delet(char q[],int *f,int *r)
{
	char item[20];
	if(*f==-1)
	{
		printf("queue is empty\n");
	}
	*item=q[*f];
	if(*f==*r)
	{
		*f=-1;
		*r==-1;
		printf("queue underflow\n");
	}
	else
        {
		*f=(*f+1)%size;
		printf("deleted ele is %s\n",item);
        }
}
void display(char q[],int r,int f)
{
	int i;
	if(f==-1)
	{
		printf("queue is empty\n");
		return;
	}
	printf("contents of queue are :\n");
	printf(" %s\n",q);
		
}
int main()
{
	char q[100],b[size],c[size],a[size];
        int item,ch,ch_q;
	int f=-1,r=-1,e,s,i,n;
        char qw[5];
        char song[20];
	printf("1.Insert\n2.Delete\n3.DIsplay\n0 to exit=");
	scanf("%d",&ch);
	while(ch!=0){
	switch(ch)
	{
		case 1: printf("enter the no.of elements to be inserted \n");
				scanf("%d",&n);
				printf("enter the elements to be inserted\n");
				for(i=0;i<n;i++)
				{
					scanf("%d",&item);
					insert(item,&r,q,&f);
				}
		
			break;        
		case 2: delet( q, &f, &r);
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
