#include<stdio.h>
#include<conio.h>
void main()
{
	struct stud
	{
	int id,age,m;
	};
	struct stud s;
	clrscr();
	printf("enter id,age,marks=\n");
	scanf("%d%d%d",&s.id,&s.age,&s.m);
	if(s.age>20&&s.m>0&&s.m <=100)
	{
		if(s.m>=65)
			printf("eligible");
		else
			printf("not eliglible");
	}
	else
		printf("data invalid");
	getch();
}