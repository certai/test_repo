#include <stdio.h>
#include <stdlib.h>
struct Tree{
	int num;
	struct Tree *left;
	struct Tree *right;
};
void insert(Tree **root,int x)
{
	if(*root == NULL)
	{
		(*root)= (Tree *)malloc(sizeof(Tree));
		(*root)->num = x;
	}
	else if(x <= (*root)->num)
	{
		insert(&((*root)->left),x);
	}
	else
	{
		insert(&((*root)->right),x);
	}
}
bool Search(Tree *root,int x)
{
	if(root == NULL) return false;
	else if(root->num == x) return true;
	else if(x <= root->num) return Search(root->left,x);
	else  return Search(root->right,x);
}
int main()
{
	Tree *root = NULL;
	insert(&root,10);
	insert(&root,7);
	insert(&root,20);
	insert(&root,15);
	insert(&root,9);
	insert(&root,25);
	insert(&root,12);
	insert(&root,6);
	if(Search(root,9)) printf("found");
	else printf("not found");
	return 0;
}