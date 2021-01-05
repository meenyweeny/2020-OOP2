#include<iostream>
using namespace std;

/*
class Point {
public:
	int x, y;
	Point() {
		x = y = 0;
	}
	Point(int _x, int _y) { //생성자 오버로딩
		x = _x;
		y = _y;
	}
	Point(const Point& pt); //복사생성자 Point(Point& pt); 로도 쓰임
	//복사생성자란?
	//자신과 동일한 타입의 객체에 대한 레퍼런스(별명)를 인자로 받는 생성자

	void Print();
};

Point::Point(const Point& pt) {
	cout << "Copy constructor!" << endl;
	x = pt.x;
	y = pt.y;
}
void Point::Print() {
	cout << x << ", " << y << endl;
}

int main() {
	Point p1, p2, p4, p5(200, 150);
	p1.x = 10;
	p1.y = 10;
	p2.x = 20, p2.y = 20;

	Point p6(p1); //복사생성자가 동작함

	p5.Print();
	p4.Print();


	Point p3 = p2; //Point(const Point& pt) 생성자가 이 시점에서 동작
	//(복사생성자가 동작) (default 생성자는 동작 x)
	p3.Print();

	p3.y = 500;
	cout << p2.y << endl; //20
	cout << p3.y << endl; //500

	p2.y = 200;
	cout << p2.y << endl; //200
	cout << p3.y << endl; //500


	p3 = p1; //대입

	p3.Print();
	p1.Print();
	p2.Print();

}
*/


//=================================

//반드시 생성자가 존재해야하는 경우
//ex 멤버변수에 const 속성 가진게 있거나 레퍼런스 타입이 있다면

/*
class NeedConstructor {
public:
	const int max;
	int & ref;
	//const와 레퍼런스는 반드시 초기화가 되어야한다는 특징이 있다
	//그래서 생성자가 필요
	int temp;

	NeedConstructor()
		:max(100),ref(temp) {
		temp = 10;
		//max = 100;
		//ref = temp;
		//얘네는 생성자가 불러지기 이전에 초기화되어야함
	}
	NeedConstructor(int cnt, int & number)
		:max(cnt), ref(number) {
		temp = 10;
	}
};

int main() {
	NeedConstructor cr;
	int num = 400;
	NeedConstructor crr(500, num);
	//cr.max = 1000; //상수라 변경 불가
	cout << cr.max << endl;
	cout << cr.ref << endl;
	cout << &cr.ref << endl; //ref의 주소 (==temp의 주소)
	cout << &cr.temp << endl;

	cout << crr.max << endl;
	cout << crr.ref << endl;
	cout << &crr.ref << endl; //ref의 주소 (==num의 주소)
	cout << crr.temp << endl;
	cout << &crr.temp << endl;
	//초기화가 달랐으니까 ref랑 temp랑은 주소 상관없어짐
	cout << num << endl;
	cout << &num << endl; //ref와 주소가 같다
}
*/

//=================================

//소멸자
//객체가 사용한 자원에 대한 정리

class DynamicArray {
public:
	int * arr;
	DynamicArray(int arraySize) {
		arr = new int[arraySize]; //동적 메모리 할당
	}
	~DynamicArray() { //소멸자
		cout << "소멸자 동작" << endl;
		delete[] arr; //해제해서 메모리 누수 방지
		arr = NULL; //완벽하게 아무데도 가리키지 않게 연결 끊기
	}
};

int main() {
	int size;
	cout << "몇 개의 정수 입력? ";
	cin >> size;

	DynamicArray da(size);

	for (int i = 0; i < size; i++)
		cin >> da.arr[i];

	for (int i = size - 1; i >= 0; i--) {
		cout << da.arr[i] << " ";
	}

	cout << endl;

	//main에서 생성된 객체의 소멸자는
	//main함수가 끝나는 시점에서 실행된다
	//생성된 객체는 해당 함수가 종료되는 동시에 소멸된다
	//(소멸자 동작 타이밍)

	//그래서 소멸자는 사용한 자원을 정리하기에 아주 적합한 기능
}