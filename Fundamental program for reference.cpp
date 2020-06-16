#include<iostream>

using namespace std;

class Rectangle
{

	private:
		int length;
		int breadth;

	public:
		Rectangle(int l, int b)
		{
			length = l;
			breadth = b;
		}

		int area()
		{
			return length*breadth;
		}

		void changelength(int l)
		{
			length = l;
			cout << "\nlength changed to " << length << "\n";	
		}
};

int main()
{
	Rectangle r(10,5);

	cout << "Area = " << r.area();				// call by value to not modify data variables
	r.changelength(20);					
} 
