//다형성과 가상함수

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
	void Draw() const { //읽기 전용 const method
		//_x,_y 값을 함부로 바꿀 수 없음
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
	: Shape(x,y) { //초기화 리스트 사용, 부모클래스의 생성자 호출
		Resize(width, height);
	}
	void Draw() const { //메서드 오버라이딩
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
	: Shape(x,y) { //부모클래스의 Shape 생성자를 실행시킴 (초기화 리스트)
		SetRadius(radius); //Circle class 전용 메서드
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

	//도형 객체 생성 및 그리기
	//Shape s(100,100);
	Shape s;
	s.Move(100, 100);
	s.Draw(); //Shape class의 Draw 메서드

	//사각형 객체 생성 및 그리기
	//Rectangle r(200,100,50,50);
	Rectangle r;
	r.Move(200, 100);
	r.Resize(50, 50);
	r.Draw(); //Rectangle class의 Draw 메서드

	//원 객체 생성 및 그리기
	//Circle c(300,100,30);
	Circle c;
	c.Move(300, 100);
	c.SetRadius(30);
	c.Draw(); //Circle class의 Draw 메서드

}