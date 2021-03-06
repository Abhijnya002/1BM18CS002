#include<stdlib.h>
#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node *NODE;
void display(NODE head);
NODE delete_ele_repeated(NODE head, int ele) ;
NODE delete_front(NODE head);
NODE getnode();
NODE delete_ele(NODE head,int ele);
void delete_end(NODE head);
NODE insert_front(int item,NODE head);
int check_list(int ele,NODE head);
int flag=0;
int main()
{
	NODE head=NULL;
	int n,ele,pos,i;
	int c;
	printf("Enter 1 to insert ele,2 to delete at the front,3 to delete at the end,4 to display,5 to delete the given element=\n");
	scanf("%d",&n);
	while(n!=0)
	{
	switch(n)
	{
		case 1:printf("enter the ele=\n");
	 		scanf("%d",&ele);
			head=insert_front(ele,head);
			break;
		case 2:
			head=delete_front(head);
			break;
		case 3:
			delete_end(head);
			break;
		case 4:display(head);
			break;
		case 5:printf("enter the element to be deleted=\n");
			scanf("%d",&ele);
			c= check_list( ele, head);
			if(c>1)
			{
				head=delete_ele_repeated(head,ele);
			}
			else
			{
				head=delete_ele(head,ele);
			}
			break;
		
	}
	printf("again enter choice=\n");
	scanf("%d",&n);
}
}
NODE delete_front(NODE head)
{
	NODE p=head;
	if(head==NULL)
	{
		printf("list is empty");
		return head;
	}
	printf("deleted ele=%d\n",p->data);
	head=p->next;
	free(p);
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
void delete_end(NODE head)
{
	NODE p,r;
	p=head;
	if(head==NULL)
	{
		printf("list is empty");
		return ;
	}
	while(p->next!=NULL)
	{
		r=p;
		p=p->next;
	}
	printf("deleted ele is %d\n",p->data);
	r->next=NULL;
	free(p);
	
}
NODE insert_pos(NODE head,int item,int pos)
{
	NODE curr,prev=NULL,newn;
	int count=1;
	newn=getnode();
	newn->data=item;
	newn->next=NULL;
	if(head==NULL)
	{
		if(pos==1)
		{
			return newn;
		}
		else
		{
			printf("Invalid position");
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
		curr=head;
		while(curr!=NULL&&count!=pos)
		{
			prev=curr;
			curr=curr->next;
			count++;
		}
		if(count==pos)
		{
			prev->next=newn;
			newn->next=curr;
			return head;
		}
		else
		{
			printf("Invalid position");
			return head;
		}
	}
}
void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("List is empty\n");
		exit(0);
	}
	p=head;
	printf("Contents of the list\n");
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
NODE delete_ele_repeated(NODE head, int ele) 
{
	NODE curr=head,prev=NULL;
	
	if(head==NULL)
	{
		printf("list is empty\n");
		return head;
	}
	
	if(head->next==NULL)
	{
		if(head->data==ele)
		{
			free(head);
			return NULL;
		}
		else
		{
			printf("value not found\n");
			return head;
		}
	}
	while(curr!=NULL)
	{
		if(curr->data==ele)
		{
			flag=1;
			if(prev==NULL)
			{
				head=curr->next;
				free(curr);
			}
			else
			{
				prev->next=curr->next;
				free(curr);
			}
			//return head;
		}
		prev =curr;
		curr=curr->next;
	}
	
	if(flag==0)
	{
		printf("value is not present\n");
		
	}
	return head;
}
NODE delete_ele(NODE head, int ele) 
{
	NODE curr=head,prev=NULL;
	if(head==NULL)
	{
		printf("list is empty\n");
		return head;
	}
	
	if(head->next==NULL)
	{
		if(head->data==ele)
		{
			free(head);
			return NULL;
		}
		else
		{
			printf("value not found\n");
			return head;
		}
	}
	while(curr!=NULL)
	{
		if(curr->data==ele)
		{
			if(prev==NULL)
			{
				head=curr->next;
				free(curr);
			}
			else
			{
				prev->next=curr->next;
				free(curr);
			}
			return head;
		}
		prev =curr;
		curr=curr->next;
	}
	if(curr==NULL)
	{
		printf("value is not present\n");
		return head;
	}
	
}	
int check_list(int ele,NODE head)
{
	int count;
	while(head!=NULL)
	{
		if(head->data==ele)
		{
			count++;
		}
		head=head->next;
	}
	return count;
}
	
