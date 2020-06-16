#include<stdio.h>

struct Rectangle
{
	int length;
	int breadth;
};

void initialize(struct Rectangle *p, int l, int b)
{
	p->length = l;
	p->breadth = b;
}

int area(struct Rectangle r)
{
	return r.length*r.breadth;
}

void changelength(struct Rectangle *p, int l)
{
	p->length = l;	
}

int main()
{
	struct Rectangle r;

	initialize(&r,10,5);			// call by reference to modify data variables
	printf("length = %d, breadth = %d \n",r.length,r.breadth);
	printf("Area = %d \n",area(r));		// call by value to not modify data variables
	changelength(&r,20);			// call by reference to modify data variables
	printf("length changed to %d \n",r.length);
}
