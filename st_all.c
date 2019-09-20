#include<stdio.h>
int stack[100];
int top=-1;
void push(int ele);
int pop();
void display();
int main()
{
	int e,ch,n,i;
	do{
		
	printf("enter 1 to push 2 to pop 3 to dis=");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:printf("enter n=");
			scanf("%d",&n);
			printf("enter ele=");
			for(i=0;i<n;i++)
			{
				scanf("%d",&e);
				push(e);
			}break;
		case 2:printf("enter n=");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				e=pop();
				printf("popped ele=%d\n",e);
			}break;
		case 3:display();
			break;
		default:break;
	}
	}while(ch!=0);
	
}
void push(int ele)
{
	if(top==99)
	{
		printf("stack is overflow\n");
		return;
	}
	stack[++top]=ele;
}
int pop()
{
	if(top==-1)
	{
		printf("stack is underflow\n");
		return -9999;
	}
	return stack[top--];
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("stack is empty\n");
		return;
	}
	printf("contents of stack is\n");
	for(i=top;i>=0;i--)
	{
	printf("%d\n",stack[i]);
	}
}

    
