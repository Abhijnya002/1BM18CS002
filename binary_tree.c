#include<stdlib.h>
#include<stdio.h>
struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
};
typedef struct node *NODE;
NODE insert(NODE root,int item);
void display(NODE root);
NODE getnode(int item);
void inorder(NODE root);
void preorder(NODE root);
void postorder(NODE root);
int main()
{
	int ele,ch,n,i;
	NODE root=NULL;
	printf("1.insert\n2.inorder\n3.preorder\n4.postorder\n5.display=");
	scanf("%d",&ch);
	while(ch!=0)
	{
	switch(ch)
	{
		case 1:printf("enter the no of ele=\n");
			scanf("%d",&n);
			printf("enter the ele=\n");
			for(i=0;i<n;i++)
			{
			scanf("%d",&ele);
			root=insert(root,ele);
			}
			break;
		case 2:inorder(root);
			break;
		case 3:preorder(root);
			break;
		case 4:postorder(root);
			break;
		
	}
	printf("1.insert\n2.inorder\n3.preorder\n4.postorder\n5.display=");
	scanf("%d",&ch);
	}
}
void inorder(NODE root)
{
	if(root==NULL)
		return;
	inorder(root->lchild);
	
	printf("%d\n",root->data);
	inorder(root->rchild);
}
void preorder(NODE root)
{
	if(root==NULL)
		return;
	printf("%d\n",root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}
void postorder(NODE root)
{
	if(root==NULL)
		return;
	
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d\n",root->data);

}
NODE insert(NODE root,int item)
{

	if(root==NULL)
		return getnode(item);
	if(item<root->data)
		root->lchild=insert(root->lchild,item);
	else if(item>=root->data)
		root->rchild=insert(root->rchild,item);
	return root;
}
NODE getnode(int item)
{
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	p->data=item;
	p->lchild=NULL;
	p->rchild=NULL;
	return p;
}

	

	
