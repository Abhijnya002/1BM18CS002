#include<stdlib.h>
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node *NODE;
void display(NODE head);
NODE getnode();
NODE insert_front(int item,NODE head);
NODE delete_pos(NODE head,int pos);
int main()
{
	NODE head=NULL;
	int n,ele,p,i;
	int c,j;
	printf("Enter 1 to insert ele,2 to delete at any position,3 to display=");
	scanf("%d",&n);
	while(n!=0)
	{
	switch(n)
	{
		case 1:printf("enter the ele=\n");
	 		scanf("%d",&ele);
			head=insert_front(ele,head);
			break;
		case 2:printf("enter the pos=\n");
	 		scanf("%d",&p);
			head=delete_pos(head,p);
			break;
		case 3:display(head);
			break;
		
	}
	printf("again enter choice=\n");
	scanf("%d",&n);
}
}
NODE delete_pos(NODE head,int pos)
{
	NODE curr,prev=NULL,q,p;
	int count=1;
	if(head==NULL)
	{
		if(pos==1)
		{
			free(curr);
		}
	
		else
		{
			printf("invalid position\n");
			return head;
		}	
	}
	if(pos==1)
	{
		p=head;
		q=head;
		q=q->next;
		head=q;
		printf("deleted ele is %d\n",p->data);
		free(p);
		return head;
	}
	else
	{
		curr=head;
		while(curr!=NULL&&count!=pos)
		{
			prev=curr;
			curr=curr->next;
			count++;
		}
		q=curr->next;
		if(count==pos)
		{
			prev->next=q;
			printf("deleted ele is %d\n",curr->data);
			free(curr);
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
	p->next=head;
	head=p;
	return head;
}
NODE getnode()
{
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
		return p;
	else
		printf("Memory couldnt be allocated");
		exit(0);
}

