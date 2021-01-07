#include "point.h"
#include<iostream>
using namespace std;


int main() {
	//객체의 배열
	//class도 타입의 한 종류니까 배열로 쓸 수 있다
	//struct랑 비슷하긴한데 생성자문제가 있다
	
	Point arr[4];
	for (auto i = 0; i < 4; i++)
		arr[i].Print();
	//모두 0, 0으로 출력되는 것을 보아 기본생성자가 동작했음을 알수있다

	Point arr2[4] = { Point(10,20),Point(11,27),
		Point(99,80),Point(1000,-99) };
	for (auto i = 0; i < 4; i++)
		arr2[i].Print();
	


	//객체의 동적할당

	Point p1(5, 10);
	Point * p2 = new Point(); //default constructor
	Point * p3 = new Point(50, 50); //parameters
	Point * p4 = new Point(p1); //copy constructor

	(*p2).Print();
	p3->Print();
	p4->Print();

	delete p2;
	delete p3;
	delete p4;
	p2 = p3 = p4 = NULL;
}