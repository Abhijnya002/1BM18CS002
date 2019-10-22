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
NODE concatenate(NODE head,NODE head1);
NODE reverse(NODE head);
void sort(NODE head);
int main()
{
	NODE head=NULL,head1=NULL,head3=NULL;
	int n,ele,i,ch;
	printf("enter the no of ele to be inserted =");
	scanf("%d",&n);
	printf("enter the ele=\n");
	for(i=0;i<n;i++)
	{
	 	scanf("%d",&ele);
		head=insert_front(ele,head);
	}
	printf("Enter the choice\n1.sort\n2.concatenate\n3.reverse\n4.display=\n");
	scanf("%d",&ch);
	while(ch!=0)
	{
	switch(ch)
	{
		case 1:sort(head);
			break;
		case 2:printf("enter the no of ele inserted into 2nd list=");
			scanf("%d",&n);
			printf("enter the ele=\n");
			for(i=0;i<n;i++)
			{
	 		scanf("%d",&ele);
			head1=insert_front(ele,head1);
			}
			head3=concatenate(head,head1);
			display(head3);
			break;
		case 3:head=reverse(head);
			break;
		case 4:display(head);
			break;
		
	}
	printf("again enter choice\n1.sort\n2.concatenate\n3.reverse\n4.display=\n");
	scanf("%d",&ch);
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
	{
		return p;
	}
	else
	{
		printf("Memory couldnt be allocated");
		exit(0);
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
NODE concatenate(NODE head,NODE head1)
{

	if(head==NULL)
	{
		return head1;
	}
	else if(head1==NULL)
	{
		return head;
	}
	else
	{
			NODE p=head;
		while(p->next!=NULL)
		{
			p=p->next;
			
		}
		p->next=head1;
		return head;
	}
}
NODE reverse(NODE head)
{
	NODE curr=head,prev =NULL,nextn=NULL;
	if(head==NULL)
	{
		printf("list is empty\n");
		return head;
	}
	if(head->next==NULL)
	{
		return head;
	}
	while(curr!=NULL)
	{
		nextn=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextn;
	}
	head=prev;
	return head;
}
