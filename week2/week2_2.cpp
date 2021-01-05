#include<iostream>
using namespace std;

int main() {
	auto f = 3.244562156f;
	//const 키워드 붙이면 변경불가
	//f 안붙이면 기본적으로 실수타입은 double로 동작
	//auto 는 type을 추론해주는거

	auto s = "testgood";
	cout << f << endl; //3.24456
	cout << s << endl;
	cout << typeid(f).name() << endl;
	cout << typeid(s).name() << endl;
	cout << sizeof(f) << endl;
	cout << sizeof(s) << endl;
	//char const * 이므로 포인터고 포인터 size 무조건 4바이트

	const char * ch = "test";
	cout << sizeof(ch) << endl;
	char chs[] = "test";
	cout << sizeof(chs) << endl;

	//===================================================
	cout << endl; //void pointer
	cout << "void pointer" << endl;
	//후처리 할 수 있는 방식, 어떤 타입이든 다 받을 수 있음
	short * ps;
	short a = 2;
	ps = &a; //꼭 같은 type의 변수만 주소로 받을 수 있다
	cout << *ps << endl;
	void * pv;
	pv = &a; //void는 다받을수있음 받는 시점에선 에러 안남
	//다만 주소만 그냥 받는거라 받은 것이 어떤 자료형인진 모름
	//그래서 사용할 땐 type을 알려줘야함(프로그래머가 알고있어야함)
	cout << *(short*)pv << endl; //casting

	double b = 3.14;
	pv = &b;
	cout << *(short*)pv << endl;
	//double인데 잘못casting해서 문제생김 -31457나옴
	//근데 거기다가 8바이트인걸 2바이트로 읽으라고 게다가 실수인걸
	//그러니까 이렇게 에러가 나올 수 밖에 없다

	cout << *(double*)pv << endl; //정확하게 출력시점에서 알려줘야함

	cout << endl;
	//========================================
	cout << "문자열 배열과 void 포인터" << endl;
	char sa[] = "Hell"; //끝에 자동으로 null 삽입됨
	char sarr[] = { 'H','e','l','l','\0' }; //끝을 알려주기위해
	//끝에 꼭 null 문자 넣어야함
	cout << sa << endl;
	cout << sizeof(sa) << endl; //5
	void * pss = &sa[0]; //맨앞번지 주소
	pss = sa; //배열명은 포인터 상수이므로 이것도 가능 둘이 같은의미
	cout << pss << endl; //주소가 찍힘
	cout << *(char*)pss << endl; //0번방의 H 딱 하나만 찍힘
	cout << (char*)pss << endl; //딱 하나가 아니라 전체가 찍힘
	for (int i = 0; i < sizeof(sa) / sizeof(char); i++) { //5번돔
		cout << *(char*)pss + i; //7273747576
	}
	cout << endl;
	for (int i = 0; i < sizeof(sa) / sizeof(char); i++) { //5번돔
		cout << *((char*)pss + i);
		//i값을 더하며 그들이 가리키는 위치에있는 값을 
		//0번째칸의 주소의 값, 1번째 칸의 주소의 값,...
	}
	cout << endl;
}