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
NODE insert_pos(NODE head,int item,int pos);
void insert_end(NODE head,int item);
int main()
{
	NODE head=NULL;
	int ch,ele,position;
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
			insert_end(head,ele);
			break;
		case 3:printf("enter the ele and position=\n");
	 		scanf("%d%d",&ele,&position);
			head=insert_pos(head,ele,position);
			break;
		case 4:display(head);
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
NODE insert_pos(NODE head,int item,int pos)
{
	NODE p,newn;
	p=head;
	newn=getnode();
	newn->data=item;
	newn->next=NULL;
	int i;
	if(head==NULL)
	{
		if(pos==1)
		{
			return newn;
		}
		else
		{
			printf("invalid position\n");
			return head;
		}
	}
	if(pos==1)
	{
		newn->next=head;
		head=newn;
		return head;
	}
	else
	{
		for(i=1;i<pos-1&&p!=NULL;i++)
		{
			p=p->next;
		}
		newn->next=p->next;
		p->next=newn;
		if(i==pos)
		{
			p->next=newn;
			newn->next=p;
			return head;
		}
		else
		{
			printf("invalid position");
			return head;
		}
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
