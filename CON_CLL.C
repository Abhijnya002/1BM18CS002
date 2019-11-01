#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node *NODE;
void display(NODE head);
NODE getnode();
NODE insert_list(int item,NODE head);
NODE concatenate(NODE head,NODE head1);
int main()
{
	NODE head=NULL, head1=NULL,head3=NULL;
	int n,ele,p,i;
	clrscr();
	printf("Enter 1 to create list1,2 tocreate list2 ,3 to concatenate,4 to display list1=");
	scanf("%d",&n);
	while(n!=0)
	{
	switch(n)
	{
		case 1:printf("enter the no.of elements to be inserted \n");
				scanf("%d",&n);
				printf("enter the elements to be inserted\n");
				for(i=0;i<n;i++)
				{
					scanf("%d",&ele);
					head=insert_list(ele,head);
				}
			break;
		case 2:printf("enter the no.of elements to be inserted \n");
				scanf("%d",&n);
				printf("enter the elements to be inserted\n");
				for(i=0;i<n;i++)
				{
					scanf("%d",&ele);
					head1=insert_list(ele,head1);
				}
			break;
		case 3:head3=concatenate(head,head1);
			display(head3);
				break;
		

	}
	printf("again enter choice=\n");
	scanf("%d",&n);
}
getch();
return 0;
}
void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("list is empty");
		exit(0);
	}
	if(head->next==head)
	{
		printf("%d\n",head->data);
		return;
	}
	printf("contents=\n");
	p=head->next;
	do
	{
		printf("%d\n",p->data);
		p=p->next;
	}while(p!=head->next);
}
NODE insert_list(int item,NODE head)
{
	NODE newn;
	newn=getnode();
	newn->data=item;
	if(head==NULL)
	{
	newn->next=newn;
	head=newn;
	return head;
	}
	newn->next=head->next;
	head->next=newn;
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
		printf("Memory couldnt be allocated");
		exit(0);
	}
	return 0;
}
NODE concatenate(NODE head,NODE head1)
{
	NODE p=head1->next;
	NODE q=head->next;
	head->next=p;
	head1->next=q;
	return head1;
}
