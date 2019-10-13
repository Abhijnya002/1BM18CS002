#include<stdio.h>
#include<stdlib.h>
struct node
{
	int petrol;
	int distance;
	struct node *next;
};
typedef struct node *NODE;
void display(NODE head);
int printTour(NODE head, int n,int petrol,int distance);
NODE insert_front(NODE head,int petrol,int distance);
NODE getnode();
void insert_end(NODE head,int distance,int petrol);
int main()
{
	NODE head=NULL;
	int start;
  	 int n ,i;
	int petrol, distance;
	int ch,ele,position;
	printf("Enter 1 to inser at the front,3 to display starting position,2 to insert at the end,4 to display\n");
	scanf("%d",&ch);
	while(ch!=0)
	{
	switch(ch)
	{
		case 1:printf("enter the number of petrol bunks=");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				printf("enter the amount of petrol and distance=\n");
	 		scanf("%d%d",&petrol,&distance);
				head=insert_front(head,distance,petrol);
			}
			break;
		case 2:printf("enter the number of petrol bunks=");
			scanf("%d",&n);
			printf("enter the amount of petrol and distance=\n");
	 		scanf("%d%d",&petrol,&distance);
			for(i=0;i<n;i++)
			{
				insert_end(head,petrol,distance);
			}
			break;
		case 3: start = printTour(head, n,petrol,distance);
   			 (start == -1)? printf("No solution"): printf("Start = %d\n", start);
			break;
		case 4:display(head);
		default:break;
	}
	printf("again Enter 1 to inser at the front,3 to display starting position,2 to insert at the end,4 to display=\n");
	scanf("%d",&ch);
	}
}
NODE insert_front(NODE head,int petrol,int distance)
{
	NODE p;
	p=getnode();
	p->petrol=petrol;
	p->distance=distance;
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
void insert_end(NODE head,int distance,int petrol)
{
	NODE p,q;
	q=getnode();
	q->petrol=petrol;
	q->distance=distance;
	p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=q;
	q->next=NULL;
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
		printf("petrol=%d\n",p->petrol);
		printf("dist=%d\n",p->distance);
		p=p->next;
	}
}
int printTour(NODE head, int n,int petrol,int distance)
{
    int start = 0;
    int end =  1;
	NODE curr=head;
    int curr_petrol = head->petrol - head->distance;
    while (end != start || curr_petrol < 0)
    {

	while (curr_petrol < 0 && start != end)
	{

	    curr_petrol -= head->petrol - head->distance;
	    start = (start + 1)%n;
	    if (start == 0)
	       return -1;
	}
	curr=curr->next;
     curr_petrol += curr->petrol - curr->distance;
	end = (end + 1)%n;
    }
    return start;
}
