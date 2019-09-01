#include<stdio.h>
#include<math.h>
float compute(int op1,int op2,char symbol);
void push(float ele,float s[100],int *t);
float pop(float s[100],int *t);
void push(float ele,float s[100],int *t)
{
	if(*t==99)
	{
		printf("stack overflow \n");
		return;
	}
	s[++(*t)]=ele;
}
float pop(float s[100],int *t)
{
	if(*t==-1)
	{
		printf("stack underflow \n");
		return -9999;
	}
	return s[(*t)--];
}
float compute(int op1,int op2,char symbol)
{
	switch(symbol)
	{
		case '+':return (op1+op2);
		case '-':return (op1-op2);
		case '*':return (op1*op2);
		case '/':return (op1/op2);
		default:return 0;
	}
}
int main()
{

	float s[100];
	int op1,op2;
	float result;
	int top=-1,i;
	char postfix[20],symbol;
	printf("enter postfix expression=");
	scanf("%s",postfix);
	for(i=0;postfix[i]!='\0';i++)
	{
		symbol=postfix[i];
		if(symbol>='0'&&symbol<='9')
		{
			push((postfix[i]-'0'),s,&top);
		}
		else
		{
			op2=s[top--];
			op1=s[top--];
			 result=compute(op1,op2,symbol);
			push(result,s,&top);
		}
	}
	printf("result=%f\n",pop(s,&top));
    	return 0;
}

