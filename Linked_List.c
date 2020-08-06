#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*root = NULL;

void Insert(int x)
{
	struct Node *t;
	struct Node *last;

	t = (struct Node*)malloc(sizeof(struct Node));
	t->data = x;
	t->next = NULL;

	if(root == NULL)
	{
		root = t;
		last = t;
	}
	else
	{
		last->next = t;
		last = t;
	}
}

void Display(struct Node *p)
{
	while(p!=NULL)
	{
		printf("%d, ",p->data);
		p = p->next;
	}
}

int main()
{
	Insert(1);
	Insert(2);
	Insert(3);
	Insert(4);

	Display(root);

	return 0;
}