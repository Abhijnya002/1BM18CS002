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
	int ch,ele,position,value;
	printf("Enter 1 to inser at the front,3 to insert at right of given ele,2 to insert at the end,4 to display=");
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
		case 3:printf("enter the ele and data to right of which new node is to be inserted=\n");
	 		scanf("%d%d",&ele,&value);
			head=insert_pos(head,ele,value);
			break;
		case 4:display(head);
		default:break;
	}
	printf("again Enter 1 to inser at the front,3 to insert at right of given ele,2 to insert at the end,4 to display=");
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
NODE insert_pos(NODE head,int item,int value)
{
	int flag=0;
	NODE curr=head,q;
	NODE prev,newn;
	newn=getnode();
	newn->data=item;
	newn->next=NULL;
	if(head==NULL)
	{
		printf("list is empty\n");
		return head;
	}
	if(curr->data==value)
	{
		newn->next=curr;
		head=newn;
		return head;
	}
	while(curr!=NULL)
	{
		if(curr->data==value)
		{
			flag=1;
			newn->next=q;
			curr->next=newn;
			return head;
			break;
		}
		prev=curr;
		curr=curr->next;
		q=curr->next;
		
	}
	if(flag==0)
	{
		printf("value is not found in list\n");
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
