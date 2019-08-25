#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
void main()
{

	int s[100];
	int op1,op2,result;
	int top=-1,i;
	char postfix[20],symbol;
	clrscr();
	printf("enter postfix expression=");
	scanf("%s",postfix);
	for(i=0;postfix[i]!='\0';i++)
	{
		symbol=postfix[i];
		if(symbol>='0'&&symbol<='9')
		{
			s[++top]=symbol-'0';
		}
		else
		{
			op2=s[top--];
			op1=s[top--];
			result=compute(symbol,op1,op2);
			s[++top]=result;
		}
	}
	result=s[top--];
	printf("result=%d\n",result);
	getch();
}
int compute(char symbol,int op1,int op2)
{
	switch(symbol)
	{
		case '+':return (op1+op2);
		case '-':return (op1-op2);
		case '*':return (op1*op2);
		case '/':return (op1/op2);
		case '^':return (pow(op1,op2));
		default:return 0;
	}

}
