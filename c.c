
#include<stdio.h>
#include<stdlib.h>
void display(int s[100],int t);
void push(int ele,int s[100],int *t);
int main()
{
	int stack1[100],top1=-1,x,ch,e,n1=0,n2=0,n3=0,sum1=0,sum2=0,sum3=0;
	float d;
	int stack2[100],top2=-1,i;
	int stack3[100],top3=-1;
	printf("enter n1\n");
	scanf("%d",&n1);
	printf("enter the heights of sylinders in first stack\n");
	for(i=0;i<n1;i++)
	{
	scanf("%d",&e);
	push(e,stack1,&top1);
	n1++;
	sum1+=e;
	}
	display(stack1,top1);
	printf("enter n2\n");
	scanf("%d",&n2);
	printf("enter heights of sylinders in 2ndstack\n");
	for(i=0;i<n2;i++)
	{
	scanf("%d",&e);
	push(e,stack2,&top2);
	n2++;
	sum2+=e;
	
	}
	display(stack2,top2);
	printf("enter n3\n");
	scanf("%d",&n3);
	printf("enter the heights of sylinders in 3 stack\n");
	for(i=0;i<n3;i++)
	{
	scanf("%d",&e);
	push(e,stack3,&top3);
	n3++;
	sum3+=e;
	
	}
	display(stack3,top3);
  	while (1) 
  	{ 
      	int top1 =0, top2 = 0, top3 = 0;
     	 if (top1 == n1 || top2 == n2 || top3 == n3) 
         printf("maximum height is 0\n");
      
      if (sum1 == sum2 && sum2 == sum3) 
        printf("maximum height is %d\n",sum1); 
      
      if (sum1 >= sum2 && sum1 >= sum3) 
         sum1 -= stack1[top1++]; 
      else if (sum2 >= sum3 && sum2 >= sum3) 
         sum2 -= stack2[top2++]; 
      else if (sum3 >= sum2 && sum3 >= sum1) 
         sum3 -= stack3[top3++] ; 
  	 } 
}

void push(int ele,int s[100],int *t)
{
	if(*t==99)
	{
		printf("stack is full\n");
		return;
	}
	else
	{
		*t=*t+1;
		s[*t]=ele;
	}
}
void display(int s[100],int t)
{
	int i;
	if(t==-1)
	{
		printf("Stack is empty\n");
		return;
	}
	else
	{
		for(i=t;i>=0;i--)
			printf("%d\n",s[i]);
	}
	
}


int rem(int st1[100],int st2[100],int st3[100],int n1,int n2,int n3,int sum1,int sum2,int sum3)
{
	
} 
