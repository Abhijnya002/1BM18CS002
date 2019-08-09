#include<stdio.h>
#include<conio.h>
int stack[100];
int top=-1;
void push(int ele);
int pop();
void dis();
int main()
{
	int e;
	clrscr();
	push(1);
	push(2);
	push(3);
	dis();
	e=pop();
	if(e!=-9999)
	printf("popped ele is %d\n",e);
	dis();
	getch();
	return 0;

}
void push(int ele)
{
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
	printf("empty\n");
	return;
	}
	printf("contents of the stack\n");
	for(i=top;i>=0;i--)
	printf("%d\n",stack[i]);
}


