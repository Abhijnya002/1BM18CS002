#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node *NODE;
NODE reverse(NODE head);
void display(NODE head);
NODE insert_front(int item,NODE head);
NODE getnode();
NODE insert_left(NODE head,int item,NODE n);
NODE insert_end(NODE head,int item);
int main()
{
	NODE head=NULL;
	int ch,ele,position;
	int c=0;
	NODE p=head;

	printf("1.insert\n2.reverse\n3.display= ");
	scanf("%d",&ch);
	while(ch!=0)
	{
	switch(ch)
	{
		case 1:printf("enter the ele=\n");
	 		scanf("%d",&ele);
			head=insert_front(ele,head);
			break;
		case 2:head=reverse(head);
			break;
		case 3:display(head);
		default:break;
	}
	printf("1.insert\n2.reverse\n3.display= ");
	scanf("%d",&ch);
	}
	
	return 0;
}
NODE insert_front(int item,NODE head)
{
	NODE p;
	p=getnode();
	p->data=item;
	p->prev=NULL;
	if(head==NULL)
	{
		p->next=NULL;
		head=p;
		return head;
	}
	else
	{
		p->next=head;
		head->prev=p;
		head=p;
		return head;
	}
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
	p=head;
	printf("contents of list=\n");
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}
NODE reverse(NODE head)
{
	NODE temp=NULL;
	NODE curr=head;
	while(curr!=NULL)
	{
		temp=curr->prev;
		curr->prev=curr->next;
		curr->next=temp;
		curr=curr->prev;
	}
	head=temp->prev;
	return head;
	
}
