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
void display(NODE head);
NODE getnode(int item);
void inorder(NODE root);
void preorder(NODE root);
void postorder(NODE root);
int main()
{
	
}
void inorder(NODE root)
{
	if(root==NULL)
		return;
	inorder(root->lchild);
	printf("%d",root->data);
	inorder(root->rchild);
}
void preorder(NODE root)
{
	if(root==NULL)
		return;
	printf("%d",root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}
void postorder(NODE root)
{
	if(root==NULL)
		return;
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d",root->data);

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

	

	
