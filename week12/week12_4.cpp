#include<iostream>
using namespace std;

void C() {
	//throw "Hell"; //문자열로 하면 catch로 잡을 수 있는게 없다
	//문자열 예외 잡을 수 있는 catch 추가해줘야한다
	throw 2.71f; //main의 기타예외로 처리됨
}

void B() { C(); }

void A() {
	try {
		B();
	}
	catch (int ex) {
		cout << "예외(A함수/정수처리) = " << ex << endl;
		throw;
	}
}

int main() {
	try {
		A();
	} catch (int ex) {
		cout << "예외(main함수/정수처리) = " << ex << endl;
	} catch (const char * ex) {
		cout << "예외(main함수/문자열처리) = " << ex << endl;
	} catch (...) {
		//잡지 못하는 type에 대해선 이렇게 선언해서 잡을 수 있다
		//catch(...)이 첫번째 catch로 오면 안됨
		//왜? ( 맨 위에서 다 잡아버리기 때문에 밑에서 처리할 일이 없음 )
		cout << "예외(main함수/기타 예외)" << endl;
	}
}