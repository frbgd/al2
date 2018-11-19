#include<math.h>
#define _USE_MATH_DEFINES
#include<iostream>
using namespace std;

class Circle {
	double r;
public:
	Circle(double a) { r = a; }
	double square() { return (M_PI * r * r); }
};

int main()
{
	double a;
	cout << "Enter a radius: "; cin >> a;
	Circle A(a);
	cout << "Square of the circle is " << A.square() << endl;
	system("pause");
	return 0;
}