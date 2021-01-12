//예외는 함수를 여러개 건너서도 전달이 가능함
//a,b,c 라는 함수 만들었는데 c에서 예외 발생했는데 여기서 해결 못하면
//b로넘기고 여기도 catch 없으면 a로 던져지고 a도 없으면 다시
//main으로 던져져서 예외를 잡아서 처리하는 방식

#include<iostream>
using namespace std;

void C() {
	throw 121; //정수를 던짐
	//이 C안엔 받을 것이 없음
}

void B() {
	C();
}

void A() {
	B();
}

//함수 선언 순서 중요함 ( a,b,c 순서로 선언하면 a에선 b를 찾을 수가 없음 )

int main() {
	try {
		A();
	}
	catch (int ex) {
		cout << "예외 = " << ex << endl;
	}
}