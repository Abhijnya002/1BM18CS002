#include<stdio.h>
#include<stdlib.h>
struct node
{
int data ;
struct node *next;
};
typedef struct node * NODE;
NODE getnode();
NODE insert_front(int item,NODE head);
void display(NODE head);
int main()
{
NODE head=NULL;
head=insert_front(10,head);
head=insert_front(20,head);
display(head);
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
printf("memory could not be located\n");
exit(0);
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
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}
