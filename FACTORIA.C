#include<stdio.h>
#include<conio.h>
int fact(int n);
int main()
{
	int n,f;
	clrscr();
	printf("enter n=");
	scanf("%d",&n);
	f=fact(n);
	printf("%d\n",f);
	getch();
	return 0;
}
int fact(int n)
{
	if(n==0)
		return 1;
	else
		return(n*fact(n-1));
}
