
#include<stdio.h>
#include<conio.h>
struct std
{
	int id,age,marks;
};
int validate(struct std s);
int qualify(struct std s);
int main()
{
	struct std st[10];
	int i,n;
	clrscr();
	printf("enter n=\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter id,age,marks=\n");
		scanf("%d%d%d",&st[i].id,&st[i].age,&st[i].marks);
		if(qualify(st[i]))
		{
			printf("student %d is eligible\n",i+1);
		}

		else
		{
			printf("student %d is not eligible\n",i+1);
		}
	}
	getch();
	return 0;
}
int validate(struct std s)
{
	if((s.age>20)&&(s.marks>=0)&&(s.marks<=100) )
		return 1;
	else
		return 0;
}
int qualify(struct std s)
{

	if(validate(s))
	{
	if(s.marks>=65)
		return 1;
	else
		return 0;
	}
	else
	{
	printf("data invalid\n");
	return 0;
	}
}
