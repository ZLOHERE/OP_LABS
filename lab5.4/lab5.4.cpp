#include <iostream>
#include "position.h"
#include "square.h"
#include "circleinsquare.h"
#include "circle.h"

using namespace std;

int main()
{
	circleinsquare sq(1,5,4);
	cout << "x: " << sq.getx()<< endl;
	cout << "y: " << sq.gety() << endl;
	cout << "sqr area: " << sq.square::area() << endl;
	cout << "circl area: " << sq.circle::area() << endl;
	cout << "sqr per: " << sq.square::per() << endl;
	cout << "circl per: " << sq.circle::per() << endl;
	sq.change(4, 4);
	cout << "len: " << sq.getlen() << endl;
	cout << "rad: " << sq.getrad() << endl;
	cout << "x: " << sq.getx() << endl;
	cout << "y: " << sq.gety() << endl;
	
}
