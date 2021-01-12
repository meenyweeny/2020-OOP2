//앞에서 살펴본 구조적 예외처리의 문제점
//1. 자원을 정리하기 전에 함수가 먼저 끝나버림

/*
#include<iostream>
using namespace std;

void B() {
	throw "Exception!!";
}

void A() {
	char * p = new char[100]; //동적 메모리 할당
	cout << "예외가 발생하기 전" << endl;
	B();
	//예외로 인해서 동적할당된 메모리가 delete 되지 못하는 문제를 갖고있다
	//B는 문제를 발생시키는 함수인데, throw가 던져지고 A에서 받을 곳이 없어서
	//main함수의 catch로 바로 가서
	//아래의 세개의 줄은 실행이 안된다

	cout << "예외가 발생한 후" << endl;
	delete[] p;
	p = NULL; //memory leak
}

int main() {
	try {
		A();
	}
	catch (const char * ex) {
		cout << "예외 잡음 : " << ex << endl;
	}
}
*/


//생성자,소멸자를 이용해서 해결해보자~

#include<iostream>
using namespace std;

class SmartPointer {
public:
	SmartPointer(char * p)
		:ptr(p) {
	}
	~SmartPointer() {
		cout << "소멸자 동작 : 메모리 해제~" << endl;
		delete[] ptr;

	}
	char * const ptr;
};

void B() { throw "Exception!!"; }
void A() {
	char * p = new char[100];
	SmartPointer sp(p); //동적메모리할당된 힙메모리영역의 번지주소 가진 p를 던져줌
	cout << "예외가 발생하기 전" << endl;
	B();
	cout << "예외가 발생한 후" << endl; //이건 동작하진 않지만
	//SmartPointer의 소멸자가 동작을 함 -> 정상적으로 delete[] ptr이 동작
	//ptr이 가리키던 영역인 new char[100]을 이상없이 해제함
	//함수가 B()가 없이 정상적으로 끝나도 소멸자는 동작을 함
}

int main() {
	try {
		A();
	} catch (const char * ex) {
		cout << "예외 잡음: " << ex << endl;
	}
}