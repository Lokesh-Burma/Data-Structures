#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

struct node 
{
	int data;
	struct node *next;
}*first = NULL;

void Append(struct node *p, int value)
{
	struct node *t, *last;
	t = (struct node *)malloc(sizeof(struct node));
	t->data = value;
	t->next = NULL;

	if(first==NULL)
	{
		first=t;
		last=t;
	}
	else
	{
		last->next=t;
		last=t;
	}
}

void Display(struct node *p)
{
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

int Count(struct node *p)
{
	int count=0;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}

int Min(struct node *p)
{
	int Min=INT32_MAX;
	while(p!=NULL)
	{
		if(Min>p->data)
			Min = p->data;
		p=p->next;
	}
	return Min;
}

int Max(struct node *p)
{
	int Max=INT32_MIN;
	while(p!=NULL)
	{
		if(Max<p->data)
			Max = p->data;
		p=p->next;
	}
	return Max;
}

void Insert(int value, int position)
{
	struct node *t,*p=first;
	t=(struct node*)malloc(sizeof(struct node));
	t->data = value;
	t->next = NULL;

	if(position<0 || position>Count(first))
		return;

	if(position==1)
	{
		t->next = first;
		first = t;
	}
	else
	{
		int i=1;
		while(i++ < position-1)
			p=p->next;	
		t->next=p->next;
		p->next=t;
	}
}

void Advanced_LinearSearch(struct node *p, int key)
{
	struct node *q = NULL;

	while(p!=NULL)
	{
		if(p->data == key)
		{
			q->next = p->next;
			p->next = first;
			first = p;
			printf("Element %d found:",key);
			Display(first);
			return;
		}
		q = p;
		p = p->next;
	}
	if(p==NULL)
		printf("Element %d not found!\n",key);
}

void delete(int value)
{
	struct node *p=first, *q=NULL;

	if(p->data==value && q==NULL)
	{
		first = p->next;
		printf("Element %d Deleted! : ",p->data);
		Display(first);
		free(p);
	}
	else
	{
		while(p)
		{
			if(p->data==value)
			{
				q->next=p->next;
				printf("Element %d Deleted! : ",p->data);
				Display(first);
				free(p);
			}
			q=p;
			p=p->next;
		}
	}

}

void reverse(struct node *p)
{
	struct node *q=NULL,*r=NULL;
	while(p)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	first=q;
	printf("Elements reversed!: ");
	Display(first);
}

int main()
{
	Append(first,10);
	Append(first,100);
	Append(first,20);
	Insert(30,2);

	printf("Elements: ");
	Display(first);

	printf("Count: %d\n",Count(first));
	printf("Min: %d\n",Min(first));
	printf("Max: %d\n",Max(first));
	delete(10);
	reverse(first);
	Advanced_LinearSearch(first,100);

	return 0;
}
