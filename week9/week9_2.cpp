#include"point.h"
#include<iostream>
using namespace std;

//�Ϲ��Լ������� �Լ������� ������
typedef void(*FP1)(int); //�̷� ������ ������ ����
//Ŭ���� �Լ��� ���� ������
typedef void(Point::*FP2)(int); //Ŭ������ ����Լ� ������ �Լ�������

void area(const Point & pt) {
	int area = pt.getX()*pt.getY();
	cout << "0, 0�� �� ���� �̷�� �簢���� ���� = " << area << endl;
}

void main() {
	Point pt(100, 100);
	//area(pt);
	
	//�Լ��� ���� �ٲٴ� ���
	pt.Print();
	pt.setX(50); //set�����ڿ� ���� private ���� x�� �����ؼ� 50�� ������
	pt.Print();
	pt.setX(-55);
	pt.Print();

	//FP1 fp1 = &Point::setY; //FP1�� �������� ��������
	FP2 fp2 = &Point::setY; //PointŬ������ setY ����Լ��� �ּҸ� ����
	(pt.*fp2)(50); //��ȣ�� ������ �켱���������� �ּ� ��Ÿ���ºκ��� �����ذ�
	pt.Print();


	//�Լ� �����ͷ� ���� �ٲٴ� ���
	//typedef �ڷ�Ÿ�Կ����� ������ ���鶧 ���� Ű����
	/*
	typedef unsigned int * ui_ptr;
	unsigned int a = 10000;
	ui_ptr pui = &a; //unsigned int * pui = &a; //���� ����
	cout << *pui << endl;
	*/
}

