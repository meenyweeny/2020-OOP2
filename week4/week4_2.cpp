#include<iostream>
using namespace std;

//열거체끼리 같은 이름의 변수일 떄 해결하는 방법
//1.각각 관여하지 못하게 서로 다른 namespace를 쓰는 방법(old style)
//2.enum class keyword 사용 (c++ 11에서 등장)(modern style)


//1.각각 관여하지 못하게 서로 다른 namespace를 쓰는 방법
//old style 해결책
/*
namespace sophomore {
	enum Java { PASS, FAIL };
}
namespace freshman {
	enum Python { PASS, FAIL };
}

//namespace가 물리적으로 다른 공간을 할당하므로 가능

int main() {
	sophomore::Java j1 = sophomore::Java::PASS;
	freshman::Python p1 = freshman::PASS;
}
*/


//================================================================

//2.enum class keyword 사용 (c++ 11에서 등장)
//modern style 해결책

/*
enum class Java{PASS,FAIL};
enum class Python{PASS,FAIL};
enum class Cplusplus{PASS,FAIL};
//class keyword를 적용하면 weak type 변수였던 것이
//strong type 변수로 적용이 되면서
//비교할 때 PASS 대신 0을 쓰거나 하면 문제가 생김
//구조체 내의 변수 이름 (PASS<FAIL)으로 비교해야 함
//old style에서는 weak type이라 0,1 등 숫자로 비교가 됐었음

int main() {
	Cplusplus c = Cplusplus::PASS;
	switch (c) {
	case Cplusplus::PASS:
		cout << "합격!";
		break;
	case Cplusplus::FAIL:
		cout << "재수강!";
		break;
	}
}
*/

//===========================================================

//reference = 변수의 별명
//변수가 이름을 하나 더 갖는거
//포인터와 내부적으로 비슷하게 동작 (파생형)
//사용방식도 비슷하지만 차이점도 있음

/* 레퍼런스 예제 1
int main() {
	//자료차임 &변수이름 = 대상변수;
	//선언과 동시에 초기화해야한다

	short s = 5;
	short & rs = s; //레퍼런스 변수
	short * ps = &s; //포인터 (주소형태로 지정)

	//모두 5라고 나옴
	cout << s << endl;
	cout << rs << endl;
	cout << *ps << endl;

	cout << endl;

	//근데 포인터랑 레퍼런스랑 비슷한데 그냥 있던 포인터 쓰지
	//꼭 레퍼런스변수 써야하나
	//차이점이 존재
	//레퍼런스같은 경우에는 short s 와 같은 번지 주소를 사용
	//즉, 별도의 공간은 x
	//하지만 포인터같은 경우에는 별도의 메모리 공간을 할당받아서 가리킴

	//주소 찍어서 확인해보자
	cout << &s << endl;
	cout << &rs << endl;
	cout << &ps << endl;
	//위에 두개는 같은데 밑에껀 다름
	//즉 포인터만 별도의 메모리 공간을 가진다
	//하지만 ps 안에는 s의 주소 값이 들어있고
	//그 값이 들어있는 공간의 주소가 또 따로 있는것
}
*/

//==============================================================

int main() {
	//레퍼런스 변수를 처음 정의할 때 외에는
	//다른 변수를 참조하게 만들 수 없다.

	int a = 1;
	int b = 2;
	int & c = a; //rule 1.레퍼런스는 선언과 동시에 초기화 되어야 함
	//a의 별명이 c가 되었다

	c = 3;
	//c는 a의 또다른 이름이니까 a값이 3으로 바뀌었다는 것

	c = b;
	//rule 2. 레퍼런스 변수를 처음 정의할 때 외에는 다른 변수를 참조하게 만들 수 없다.
	//즉 이건 b에 들어있는 2를 c에 대입할 뿐이고
	//위에서때처럼 a값이 2로 바뀜
	//(참조하는게 아님)

	c = 4;
	cout << a << endl;

	//레퍼런스 기호도 const 키워드랑 같이 쓰이는 경우가 있는데
	//const가 붙게 되면 해당 속성을 갖는 레퍼런스 변수는
	//자신의 값을 바꿀 수 없음
	//값에 단순 access는 가능

	const int & d = b;
	//근데 d를 통해서 값을 바꾸는건 안되지만
	//b를 통해서 값을 바꾸는건 가능
	
	//즉 얘네들이 불가능
	//d = 3;
	//d = a;
	//d = 5;

	cout << d << endl;

	b = 4;
	cout << d << endl;

	//레퍼런스 변수는 함수와 같이 쓰일 때 큰 장점

	//const keyword를 가진 레퍼런스의 추가적인 특징?
	//바로 상수에 대한 별명으로 쓸 수 있다.

	//일반 레퍼런스는 변수로 초기화함. 상수로 못함

	int k = 5;
	int & rk = a;

	int g = 5;
	//int & rg = 9; // error, 상수 초기화 불가, 무조건 변수 이름이 와야함

	int u = 5;
	const int & ru = 9; //const 키워드가 있어서 상수 초기화 가능
	//즉, 상수 자체를 참조하게 만들어줌
	//물론 const니까 수정은 불가

	cout << ru << endl;


}