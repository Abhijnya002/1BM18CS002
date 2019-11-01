#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node *NODE;
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
	clrscr();
	printf("Enter 1 to inser at the front,3 to insert at a given position,2 to insert at the end,4 to display\n");
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
			head=insert_end(head,ele);
			break;
		case 3:
			while(p!=NULL)
			{
				c++;
				if(c==1)
				{
					head=insert_left(head,40,p);
				}
				p=p->next;
			}
			break;
		case 4:display(head);
		default:break;
	}
	printf("again Enter 1 to inser at the front,3 to insert at a given position,2 to insert at the end,4 to display=\n");
	scanf("%d",&ch);
	}
	getch();
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
NODE insert_end(NODE head,int item)
{
	NODE p,q;
	q=getnode();
	q->data=item;
	q->next=NULL;
	p=head;
	if(head==NULL)
	{
		q->prev=NULL;
		head=q;
	}
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=q;
		q->prev=p;
	}
	return head;
	
}
NODE insert_left(NODE head,int item,NODE n)
{
	NODE newn;
	newn=getnode();
	newn->data=item;
	if(head==n)
	{
		newn->prev=NULL;
		newn->next=n;
		n->prev=newn;
		head=newn;
		return head;
	}
	else
	{
		newn->next=n;
		newn->prev=n->prev;
		n->prev =newn;
		n->prev->next=newn;
		return head;
		
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
		printf("%d\n",p->data);
		p=p->next;
	}
}