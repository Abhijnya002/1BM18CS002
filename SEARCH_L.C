#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node *NODE;
void display(NODE head);
void search(NODE head,int ele);
NODE getnode();
NODE insert_front(int item,NODE head);
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
	return 0;
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
void search(NODE head,int ele)
{
	NODE curr,prev=NULL;
	int count=1;
	if(head==NULL)
	{
		printf("list is empty");
		exit(0);
	}
	else
	{
		curr=head;
		while(curr!=NULL&&curr->data!=ele)
		{
			prev=curr;
			curr=curr->next;
			count++;
		}
		if(curr->data==ele)
		{
			printf("element found at %d position\n",count);
		}
		else
		{
			printf("element not found in the list\n");

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
int main()
{
	NODE head=NULL;
	int n,ele,item;
	clrscr();
	printf("enter 1 to insert,2 to dispaly,3 to search\n");
	scanf("%d",&n);
	while(n!=0)
	{
		switch(n)
		{
		case 1:printf("enter element to be inserted\n");
			scanf("%d",&ele);
			head=insert_front(ele,head);
			break;
		case 2:display(head);
			break;
		case 3:printf("enter the element to be searched\n");
			scanf("%d",&ele);
			search(head,ele);
			break;
		default:exit(0);

		}
	printf("enter your choice to continue else 0 to exit\n");
	scanf("%d",&n);
}
			getch();
			return 0;
}
	
				
