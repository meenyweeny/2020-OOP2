#include "point.h"
#include<iostream>
using namespace std;


int main() {
	//��ü�� �迭
	//class�� Ÿ���� �� �����ϱ� �迭�� �� �� �ִ�
	//struct�� ����ϱ��ѵ� �����ڹ����� �ִ�
	
	Point arr[4];
	for (auto i = 0; i < 4; i++)
		arr[i].Print();
	//��� 0, 0���� ��µǴ� ���� ���� �⺻�����ڰ� ���������� �˼��ִ�

	Point arr2[4] = { Point(10,20),Point(11,27),
		Point(99,80),Point(1000,-99) };
	for (auto i = 0; i < 4; i++)
		arr2[i].Print();
	


	//��ü�� �����Ҵ�

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