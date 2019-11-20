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
NODE delete(NODE root,int key);
void printlevelorder(NODE root);
NODE getnode(int item);
void inorder(NODE root);
void preorder(NODE root);
void postorder(NODE root);
NODE min(NODE root);
int height(NODE head);
int max(NODE root);
void display(NODE root,int level);
int main()
{
	int ele,ch,n,i;
	int key,level;
	NODE root=NULL;
	printf("1.insert\n2.inorder\n3.preorder\n4.postorder\n5.delete\n6.max\n7.display\n8.level order=");
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
		case 5:printf("enter the ele to be deleted=\n");
			scanf("%d",&key);
			root=delete(root,key);
			break;
		case 6:printf("max node =%d\n",max(root));
			break;
		case 7:printf("enter the level=\n");
			scanf("%d",&level);
			display(root,level);
			break;
		case 8:printf("level order traversal is\n");
			printlevelorder(root);
			break;
		
	}
printf("1.insert\n2.inorder\n3.preorder\n4.postorder\n5.delete\n6.max\n7.display\n8.level order=");
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
int max(NODE root)
{
	NODE curr=root;
	while(curr->rchild!=NULL)
	{
		curr=curr->rchild;
	}
	return (curr->data);
}
NODE min(NODE root)
{
	NODE curr=root;
	while(curr->lchild!=NULL)
	{
		curr=curr->lchild;
	}
	return root;
}
NODE delete(NODE root,int key)
{
	if(root==NULL)
	{
		return root;
	}
	if(key<root->data)
		root->lchild=delete(root->lchild,key);
	if(key>root->data)
		root->rchild=delete(root->rchild,key);
	else
	{
		if(root->lchild==NULL)
		{
			NODE temp=root->rchild;
			free(root);
			return temp;
		}
		if(root->rchild==NULL)
		{
			NODE temp=root->lchild;
			free(root);
			return temp;
		}
		NODE temp=min(root->rchild);
		root->data=temp->data;
		root->rchild=delete(root->rchild,temp->data);
	}
	return root;
}
void display(NODE root,int level)
{
	if(root==NULL)
		return;
	if(level==1)
		printf("%d\n",root->data);
	else if(level>1)
	{
		display(root->lchild,level-1);
		display(root->rchild,level-1);
	}
}
int height(NODE root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		int l=height(root->lchild);
		int r=height(root->rchild);
		if(l>r)
		{
			return(l+1);
		}
		else return(r+1);
	}
}
void printlevelorder(NODE root)
{
	int h=height(root);
	int i;
	for(i=1;i<=h;i++)
	{
	printf("level:%d\n",i);
	display(root,i);
	}
}

