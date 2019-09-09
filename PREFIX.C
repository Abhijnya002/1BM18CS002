#define SIZE 50 
#include<string.h>
#include <ctype.h>
#include<stdio.h>
void push(char elem,char s[],int *t);
char pop(char s[],int *t);
int pr(char elem);
void push(char elem,char s[],int *t)
{ 
	s[++(*t)]=elem;
}
char pop(char s[],int *t)
{
	return(s[*t--]);
}
int pr(char elem)
{
	switch(elem)
	{
		case '#': return 0;
		case ')': return 1;
		case '+':
		case '-': return 2;
		case '*':
		case '/':return 3;
		default:exit(0);
	}
	return -999;
}
void main()
{
	char s[SIZE]; int top=-1;
	char infx[50],prfx[50],ch,elem;
	int i=0,k=0;
	clrscr();
	printf("\n\nRead the Infix Expression = ");
	scanf("%s",infx);
	push('#',s,&top);
	strrev(infx);
	while( (ch=infx[i++]) != '\0')
	{
		if( ch == ')')
		push(ch,s,&top);
		else if(isalnum(ch))
		prfx[k++]=ch;
		else if( ch == '(')
		{
		while( s[top] != ')')
		prfx[k++]=pop(s,&top);

		}
		else
		{
		while( pr(s[top]) >= pr(ch) )
		prfx[k++]=pop(s,&top);
		push(ch,s,&top);
		}
	}
	while( s[top] != '#')
	prfx[k++]=pop(s,&top);
	prfx[k]='\0';
	strrev(prfx);
	strrev(infx);
	printf("\n\nGiven Infix Expn: %s \nPrefix Expn: %s\n",infx,prfx);
	getch();

}
