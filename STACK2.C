#include<stdio.h>
#include<conio.h>
struct stack
{
	int s[100];
	int top;
};
void push(struct stack *st,int ele);
void dis(struct stack st);
int pop(struct stack *st);
int main()
{
	int x;
	struct stack st;
	st.top=-1;
	clrscr();
	push(&st,1);
	push(&st,2);
	push(&st,3);
	dis(st);
	x=pop(&st);
	if(x!=-9999)
	{
	printf("popped ele is %d\n",x);
	}
	dis(st);
	getch();
}
void push(struct stack *st,int ele)
{
	if(st->top==99)
	{
	printf("overflow\n");
	return;
	}
	st->top=st->top+1;
	st->s[st->top]=ele;
}
void dis(struct stack st)
{
	int i;
	if(st.top==-1)
	{
	printf("stack is empty\n");
	return;
	}
	for(i=st.top;i>=0;i--)
	{
	printf("%d\n",st.s[i]);
	}
}
int pop(struct stack *st)
{
	int ele;
	if(st->top==-1)
{
	printf("underflow\n");
	return -9999;
}
	ele=st->s[st->top];
	st->top=st->top-1;
	return ele;
}
