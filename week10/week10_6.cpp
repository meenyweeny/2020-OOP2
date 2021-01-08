#include<iostream>
using namespace std;

//순수 가상함수

class Shape {
public:
	Shape() {
		_x = _y = 0.0;
	}
	Shape(double x, double y) {
		_x = x;
		_y = y;
	}
	void Move(double x, double y) {
		_x = x;
		_y = y;
	}
	
	//virtual void Draw() const;
	//virtual로 선언하고 구현을 안하면 에러가 남->반드시 구현해야함
	//근데 구현 안하고도 쓸 수 있게 해주는게 있는데 그게 바로 순수 가상함수

	virtual void Draw() const = 0; //순수 가상함수 (pure virtual function)

	//순수 가상함수는 자기자신의 구현이 없어도 됨
	//이를 만들었다는 것은 자식클래스에서 오버라이드해서 구현하겠다고 명시해둔것과 같음

protected:
	double _x, _y;
};
/*
void Shape::Draw() const {
	cout << "[Shape] Position = ( " << _x << ", " << _y << " )\n";
}
*/

class Rectangle : public Shape {
public:
	Rectangle() {
		_width = _height = 100.0f;
	}
	Rectangle(double x, double y, double width, double height)
		: Shape(x, y) {
		Resize(width, height);
	}
	void Draw() const {
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
		: Shape(x, y) {
		SetRadius(radius);
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

	//문제가 되는 코드

	Shape * shapes[5] = { NULL };
	shapes[0] = new Circle(100, 100, 50);
	shapes[1] = new Rectangle(300, 300, 100, 100);
	shapes[2] = new Rectangle(200, 100, 50, 150);
	shapes[3] = new Circle(100, 300, 150);
	shapes[4] = new Rectangle(200, 200, 200, 200);


	for (auto i = 0; i < 5; i++)
		shapes[i]->Draw();

	for (auto i = 0; i < 5; i++) {
		delete shapes[i];
		shapes[i] = NULL;
	}
}