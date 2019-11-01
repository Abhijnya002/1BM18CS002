#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node *NODE;
void display(NODE head);
NODE getnode();
NODE insert_front(int item,NODE head);
NODE insert_left(NODE head,int item,int value);
int main()
{
	NODE head=NULL;
	int n,ele,p,i,value;
	int c,j;
	clrscr();
	printf("Enter 1 to insert ele,2 to insert left,3 to display=");
	scanf("%d",&n);
	while(n!=0)
	{
	switch(n)
	{
		case 1:printf("enter the ele=\n");
	 		scanf("%d",&ele);
			head=insert_front(ele,head);
			break;
		case 2:printf("enter the ele and value=\n");
	 		scanf("%d%d",&ele,&value);
			head=insert_left(head,ele,value);
			break;
		case 3:display(head);
			break;
		
	}
	printf("again enter choice=\n");
	scanf("%d",&n);
}
getch();
return 0;
}
NODE insert_left(NODE head,int item,int value)
{
	int flag=0;
	NODE curr=head,n=NULL;
	NODE q;
	q=getnode();
	q->data=item;
	if(head==NULL)
	{
		printf("list is empty\n");
		return head;
	}
	if(curr->data==value)
	{
		
		q->next=head;
		head->prev=q;
		head=q;
		return head;
	}
	while(curr!=NULL)
	{
		if(curr->data==value)
		{
			flag=1;
			q->next=curr;
			q->prev=n;
			n->next=q;
			curr->prev=q;
			return head;
			
		}
		n=curr;
		curr=curr->next;
		
	}
	if(flag==0)
	{
		printf("value is not found in list\n");
		return head;
	}

	return 0;
}
		

void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("list is empty\n");
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
		return p;
	else
	{
		printf("Memory couldnt be allocated");
		exit(0);
	}
	return 0;
}