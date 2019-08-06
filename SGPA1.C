#include<stdio.h>
#include<conio.h>
struct stud
{
	int m[10];

};
void main()
{

	int i;
	float sgpa;
	char g;
	int grade[]={4,4,4,4,3,3,2,1};
	int gradept=0;
	struct stud s;
	clrscr();
	printf("enter the marks=\n");
	for(i=0;i<8;i++)
	{
	scanf("%d",&s.m[i]);
	}
	for(i=0;i<8;i++)
	{
	if(s.m[i]>=0&&s.m[i]<=40)
	{
	g='d';
	gradept+= (6*grade[i]);
	}
	else if(s.m[i]>40&&s.m[i]<60)
	{
	g='c';
	gradept+=(7*grade[i]);
	}
	else if(s.m[i]>60&&s.m[i]<75)
	{
	g='b';
	gradept+=(8*grade[i]);
	}
	else if(s.m[i]>75&&s.m[i]<90)
	{
	g='a';
	gradept+=(9*grade[i]);
	}
	else if(s.m[i]>=90)
	{
	g='s';
	gradept+=(10*grade[i]);
	}
	else
	{
	gradept=0;
	gradept+=(0*grade[i]);
	}
	printf("subj %d grade=%c\n",i+1,g);
}
sgpa=(float)gradept/25;
printf("sgpa=%f\n",sgpa);
getch();
}

