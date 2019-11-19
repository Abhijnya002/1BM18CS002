#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node *NODE;
NODE exchange(NODE head);
void display(NODE head);
NODE insert_front(int item,NODE head);
NODE getnode();
NODE insert_end(NODE head,int item);
int main()
{
	NODE head=NULL;
	int ch,ele,position;
	
	printf("Enter 1.insert front\n2.insert end\n3.exchange\n4.display= ");
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
		case 3:head=exchange(head);
			break;
		case 4:display(head);
			break;
	}
	printf("Enter 1.insert front\n2.insert end\n3.exchange\n4.display=");
	scanf("%d",&ch);
	}
	
	return 0;
}
NODE insert_front(int item,NODE head)
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
	printf("memory could not be allocated");
	exit(0);
	}


}
NODE insert_end(NODE head,int item)
{
	NODE q;
	q=getnode();
	q->data=item;
	if(head==NULL)
	{
		q->next=q;
		head=q;
		return head;
	}
	q->next=head->next;
	head->next=q;
	head=q;
	return q;

}

void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("list is empty");
		exit(0);
	}
	printf("contents=");
	if(head->next==head)
	{
		printf("%d\n",head->data);
		return;
	}
	p=head->next;
	do
	{
		printf("%d\n",p->data);
		p=p->next;
	}while(p!=head->next);
}
NODE exchange(NODE head)
{
	NODE q=head;
	NODE p=head->next;
	int temp;
	temp=p->data;
	p->data=q->data;
	q->data=temp;
	return head;
}
