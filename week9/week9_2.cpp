#include"point.h"
#include<iostream>
using namespace std;

//일반함수에대한 함수포인터 접근은
typedef void(*FP1)(int); //이런 구조의 포맷을 가짐
//클래스 함수에 대한 접근은
typedef void(Point::*FP2)(int); //클래스의 멤버함수 참조용 함수포인터

void area(const Point & pt) {
	int area = pt.getX()*pt.getY();
	cout << "0, 0과 이 점이 이루는 사각형의 면적 = " << area << endl;
}

void main() {
	Point pt(100, 100);
	//area(pt);
	
	//함수로 값을 바꾸는 방법
	pt.Print();
	pt.setX(50); //set접근자에 의해 private 변수 x에 접근해서 50을 대입함
	pt.Print();
	pt.setX(-55);
	pt.Print();

	//FP1 fp1 = &Point::setY; //FP1은 접근지정 안해줬음
	FP2 fp2 = &Point::setY; //Point클래스의 setY 멤버함수의 주소를 전달
	(pt.*fp2)(50); //괄호는 연산자 우선순위때문에 주소 나타내는부분은 묶어준것
	pt.Print();


	//함수 포인터로 값을 바꾸는 방법
	//typedef 자료타입에대한 별명을 만들때 쓰는 키워드
	/*
	typedef unsigned int * ui_ptr;
	unsigned int a = 10000;
	ui_ptr pui = &a; //unsigned int * pui = &a; //둘이 같음
	cout << *pui << endl;
	*/
}

