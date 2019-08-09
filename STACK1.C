#include<stdio.h>
#include<conio.h>
void push(int ele,int s[100],int *t);
int pop(int s[100],int *t);
void dis(int s[100],int t);
int main()
{
	int st[100],top=-1,e;
	clrscr();
	push(1,st,&top);
	push(2,st,&top);
	push(3,st,&top);
	dis(st,top);
	e=pop(st,&top);
	if(e!=-9999)
	printf("popped ele is %d\n",e);
	else
	printf("empty");
	dis(st,top);
	getch();
	return 0;
}
void push(int ele,int s[100],int *t)
{
	if(*t==99)
	{
	printf("overflow");
	return;
	}
	*t=*t+1;
	s[*t]=ele;
}
int pop(int s[100],int *t)
{
	int ele;
	if(*t==-1)
	{
	printf("underflow");
	return -9999;
	}
	ele=s[*t];
	*t=*t-1;
	return ele;
}
void dis(int s[100],int t)
{
	int i;
	if(t==-1)
	{
	printf("stack is empty\n");
	return;
	}
	printf("contents of stack\n");
	for(i=t;i>=0;i--)
	{
	printf("%d\n",s[i]);
	}
}
