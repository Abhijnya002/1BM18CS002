#include<stdio.h>
#include<conio.h>
	struct stud
	{
	int id,age,m;
	};
int main()
{
	struct stud s[10];
	int i;
	clrscr();
	for(i=0;i<10;i++)
	{
	printf("enter id,age,marks=\n");
	scanf("%d%d%d",&s.id,&s.age,&s.m);
	if(s[i].age>20&&s[i].m>0&&s[i].m <=100)
	{
		if(s[i].m>=65)
			printf("eligible");
		else
			printf("not eliglible");
	}
	else
		printf("data invalid");
	getch();
}