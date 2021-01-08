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
	void Move(double x, double y) {
		_x = x;
		_y = y;
	}
	virtual void Draw() const { //읽기 전용 const method
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
		: Shape(x, y) { //초기화 리스트 사용, 부모클래스의 생성자 호출
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
		: Shape(x, y) { //부모클래스의 Shape 생성자를 실행시킴 (초기화 리스트)
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

	//문제가 되는 코드

	Shape * shapes[5] = { NULL }; //크기 5인 포인터 배열을 선언

	//동적할당
	//부모클래스의 포인터로 상속관계의 자식 클래스들의 타입으로 동적 할당
	shapes[0] = new Circle(100, 100, 50);
	shapes[1] = new Rectangle(300, 300, 100, 100);
	shapes[2] = new Rectangle(200, 100, 50, 150);
	shapes[3] = new Circle(100, 300, 150);
	shapes[4] = new Rectangle(200, 200, 200, 200);


	for (auto i = 0; i < 5; i++)
		shapes[i]->Draw();
	//각각 Circle,Rectangle 들로 동적할당을 해줬는데 Shape의 Draw가 실행됐음
	//부모포인터로 자식의 주소를 받았을 땐 부모가 가진 메서드가 실행됐음
	//각각 Circle, Rectangle의 Draw가 실행됐으면 좋겠는데 어떻게 해결할까?

	//딱 하나의 키워드로 해결 가능
	//선언한 Shape class의 Draw 함수 앞에 virtual 키워드 넣으면 된다
	//이 키워드로 각각의 자식클래스에 맞는 Draw가 동작하게 된다

	for (auto i = 0; i < 5; i++) {
		delete shapes[i];
		shapes[i] = NULL;
	}
}