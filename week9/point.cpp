#include"point.h"
#include<iostream>
using namespace std;

Point::Point() {
	x = y = 0;
}

Point::Point(COOR_T _x, COOR_T _y) {
	if (_x < 0)
		x = 0;
	else if (_x > 100)
		x = 100;
	else
		x = _x;

	if (_y < 0)
		y = 0;
	else if (_y > 100)
		y = 100;
	else
		y = _y;
}

Point::Point(const Point& pt) {
	x = pt.x;
	y = pt.y;
}

void Point::Print() const {
	cout << x << ", " << y << endl;
}