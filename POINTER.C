#include<stdio.h>
#include<conio.h>
void swap(int *,int *);
int main()
{
	int a,b;
	clrscr();
	printf("enter a,b=");
	scanf("%d%d",&a,&b);
	swap(&a,&b);
	printf("after call of function a=%d\tb=%d",a,b);
	getch();
}
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	printf("a=%d\tb=%d\n",*a,*b);
}