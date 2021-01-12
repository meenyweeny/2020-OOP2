#include<iostream>
using namespace std;

void C() {
	throw 121;
}

void B() {
	C();
}

//전달받은 예외 다시 던지기
void A() {
	try {
		B();
	}
	catch (int ex) {
		cout << "예외(A함수) = " << ex << endl;
		throw; //예외 다시 던지기
		//예외 다시 던지면 또 다시 함수를 거슬러올라가면서
		//거기에 알맞는 객체 블록을 찾게 된다
	}
}

int main() {
	try {
		A();
	}
	catch (int ex) {
		cout << "예외(main함수) = " << ex << endl;
	}
}

//원래대로라면 A함수에서 이미 오류 잡고 처리해서 A 선에서 끝나는데
//catch밑에 throw;를 해주면 받은 예외를 또 토스해줌