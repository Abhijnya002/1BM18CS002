#include<stdio.h>
#include<conio.h>
int stack[100];
int top=-1;
void push(int ele);
int pop();
void dis();
int main()
{
	int e,j,ch;
	clrscr();
	do{
	printf("enter 1 to enter ele and 2 for exit=\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:push(e);
			break;
		case 2:dis();
		break;
	}
	}while(ch!=2);
	for(j=top;j>=0;j--)
	{
	e=pop();
	if(e!=-9999)
	printf("popped ele is %d\n",e);
	dis();
	}
	getch();
	return 0;

}
void push(int ele)
{

	printf("enter the ele to be pushed=\n");
	scanf("%d",&ele);
	if(top==99)
	{
	printf("stack overflow\n");
	return;
	}
	stack[++top]=ele;
	return ;
}
int pop()
{
	if(top==-1)
	{
	printf("stack underflow");
	return -9999;
	}
	 return stack[top--];


}
void dis()
{
	   int i;
	if(top==-1)
	{
	printf(" stack is empty\n");
	return;
	}
	printf("contents of the stack\n");
	for(i=top;i>=0;i--)
	{
	printf("%d\n",stack[i]);
	}
}


