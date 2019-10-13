#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char name[10];
	struct node *next;
};
typedef struct node *NODE;
void display(NODE head);
NODE insert_front(char item[10],NODE head);
NODE getnode();
int main()
{
	NODE head=NULL;
	int ch,position;
	char name[10];
	printf("Enter 1 to inser at the front,3 to insert at a given position,2 to insert at the end,4 to display\n");
	scanf("%d",&ch);
	while(ch!=0)
	{
	switch(ch)
	{
		case 1:printf("enter the name of the student=\n");
	 		scanf("%s",name);
			head=insert_front(name,head);
			break;
		
		case 4:display(head);
		default:break;
	}
	printf("again Enter 1 to inser at the front,3 to insert at a given position,2 to insert at the end,4 to display=\n");
	scanf("%d",&ch);
	}
}
NODE insert_front(char item[10],NODE head)
{
	NODE p;
	p=getnode();
	strcpy(p->name,item);
	p->next=head;
	head=p;
	return head;
}
NODE getnode()
{
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
	{
	return p;
	}
	else
	{
	printf("memory could not be allocated");
	exit(0);
	}
}

void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("list is empty");
		exit(0);
	}
	p=head;
	printf("contents of list=\n");
	while(p!=NULL)
	{
		printf("%s\n",p->name);
		p=p->next;
	}
}
