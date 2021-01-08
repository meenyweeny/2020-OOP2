//�������� �����Լ�

#include<iostream>
using namespace std;

class Shape {
public:
	Shape() {
		_x = _y = 0.0;
	}
	Shape(double x, double y) {
		_x = x;
		_y = y;
	}
	void Move(double x,double y){
		_x = x;
		_y = y;
	}
	void Draw() const { //�б� ���� const method
		//_x,_y ���� �Ժη� �ٲ� �� ����
		cout << "[Shape] Position = ( " << _x << ", " << _y << " )\n";
	}

protected:
	double _x, _y;
};

class Rectangle : public Shape {
public:
	Rectangle() {
		_width = _height = 100.0f;
	}
	Rectangle(double x, double y, double width, double height) 
	: Shape(x,y) { //�ʱ�ȭ ����Ʈ ���, �θ�Ŭ������ ������ ȣ��
		Resize(width, height);
	}
	void Draw() const { //�޼��� �������̵�
		cout << "[Rectangle] Position = ( " << _x << ", " << _y << " ) ";
		cout << "Size = ( " << _width << ", " << _height << " ) \n";
	}
	void Resize(double width, double height) {
		_width = width;
		_height = height;
	}

protected:
	double _width;
	double _height;
};

class Circle : public Shape {
public:
	Circle() {
		_radius = 100.0f;
	}
	Circle(double x, double y, double radius) 
	: Shape(x,y) { //�θ�Ŭ������ Shape �����ڸ� �����Ŵ (�ʱ�ȭ ����Ʈ)
		SetRadius(radius); //Circle class ���� �޼���
	}
	void Draw() const {
		cout << "[Circle] Position = ( " << _x << ", " << _y << " ) ";
		cout << "Radius = " << _radius << "\n";
	}
	void SetRadius(double radius) {
		_radius = radius;
	}

protected:
	double _radius;
};

int main() {

	//���� ��ü ���� �� �׸���
	//Shape s(100,100);
	Shape s;
	s.Move(100, 100);
	s.Draw(); //Shape class�� Draw �޼���

	//�簢�� ��ü ���� �� �׸���
	//Rectangle r(200,100,50,50);
	Rectangle r;
	r.Move(200, 100);
	r.Resize(50, 50);
	r.Draw(); //Rectangle class�� Draw �޼���

	//�� ��ü ���� �� �׸���
	//Circle c(300,100,30);
	Circle c;
	c.Move(300, 100);
	c.SetRadius(30);
	c.Draw(); //Circle class�� Draw �޼���

}