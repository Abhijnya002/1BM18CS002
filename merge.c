#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node *NODE;
void display(NODE head);
NODE insert_front(int item,NODE head);
NODE getnode();
NODE merge(NODE head,NODE head1);
void insert_end(NODE head,int item);
void sort(NODE head);
int main()
{
	NODE head=NULL;
	NODE head1=NULL;
	int ch,ele,position;
	printf("Enter 1 to inser list1,3 to sort list1,4 to sort list2,5 to merge,2 to insert list 2,6 to display\n");
	scanf("%d",&ch);
	while(ch!=0)
	{
	switch(ch)
	{
		case 1:printf("enter the ele=\n");
	 		scanf("%d",&ele);
			head=insert_front(ele,head);
			break;
		case 2:printf("enter the ele=\n");
	 		scanf("%d",&ele);
			head1=insert_front(ele,head);
			break;
		case 3:sort(head);
			break;
		case 4:sort(head1);
			break;
		case 5:
			head=merge(head,head1);
			break;
		case 6:display(head);
		case 7:display(head1);
		default:break;
	}
	printf("again Enter 1 to inser at the front,3 to insert at a given position,2 to insert at the end,4 to display=\n");
	scanf("%d",&ch);
	}
}
NODE insert_front(int item,NODE head)
{
	NODE p;
	p=getnode();
	p->data=item;
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
void insert_end(NODE head,int item)
{
	NODE p,q;
	q=getnode();
	q->data=item;
	p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=q;
	q->next=NULL;
}
NODE merge(NODE head,NODE head1)
{
	if(head==NULL)
		return head1;
	if(head1==NULL)
		return head;
	if(head->data<head1->data)
	{
		head->next=merge(head->next,head1);
		return head;
	}
	else
	{
		head1->next=merge(head1->next,head);
		return head1;
	}
}
void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("list is empty");
		return;
	}
	p=head;
	printf("contents of list=\n");
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}
void sort(NODE head)
{
	NODE p=head,q=NULL;
	int temp;
	if(head==NULL)
	{
		return;
	}
	while(p->next!=NULL)
	{
		q=p->next;
		while(q!=NULL)
		{
			if(p->data>q->data)
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
			q=q->next;
		}
		p=p->next;
	}
}
