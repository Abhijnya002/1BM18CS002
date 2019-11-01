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
NODE delete_pos(NODE head,int value);
int main()
{
	NODE head=NULL;
	int n,ele,p,i;
	int c,j;
	clrscr();
	printf("Enter 1 to insert ele,2 to delete at any specific value,3 to display=");
	scanf("%d",&n);
	while(n!=0)
	{
	switch(n)
	{
		case 1:printf("enter the ele=\n");
	 		scanf("%d",&ele);
			head=insert_front(ele,head);
			break;
		case 2:printf("enter the value=\n");
	 		scanf("%d",&p);
			head=delete_pos(head,p);
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
NODE delete_pos(NODE head,int value)
{
	NODE curr=head,prev,q,p;
	NODE n=NULL;
	int item;
	if(head==NULL)
	{
		printf("empty");
		return head;
	}
	if(head->next==NULL)
	{
		if(head->data==value)
		{
			free(head);
			return NULL;
		}
		else
		{
			printf("invalid position\n");
			return head;
		}	
	}
	while(curr!=NULL)
	{
		if(curr->data==value)
		{
			if(curr->prev==NULL)
			{
				item=curr->data;
				head=curr->next;
				head->prev=NULL;
				free(curr);
				return head;
			}
			else
			{
				n->next=curr->next;
				curr->next->prev=n;
				item=curr->data;
				free(curr);
				return head;
			}
		}
		n=curr;
		curr=curr->next;
	}
	printf("deleted ele is %d\n",item);
	if(curr==NULL)
	{
		printf("invalid position");
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