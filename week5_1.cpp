//Lambda expression c++ 11에서 추가된 개념
//기본 구조
//[캡쳐블럭](매개변수리스트)->리턴타입{함수바디(익명객체)};
//[캡쳐블럭](매개변수리스트)->리턴타입{함수바디(익명객체)}(); //람다표현식 즉시 실행
//이름없는 함수
//코드가 짧고 간결해짐

#include<iostream>
using namespace std;

int main() {
	[]()->void {}; //아무것도 작동하지않는 람다표현식
	//파라미터목록, 화살표기호, 리턴타입 생략 가능
	[]() {};
	[] {};
	//캡쳐블럭이랑 함수바디가 꼭필요한 것

	[] {cout << "Hi Lambda" << endl; }; //이렇게만 쓴다고 실행은 안됨

	//실행시키는 방법
	//1.뒤에 함수 실행하는 소괄호 붙여서
	[] {cout << "Hi Lambda" << endl; }();
	//맨끝의 소괄호 쌍은 람다 표현식을 즉시 실행시키는 역할

	//2.자유타입을 선언하고 변수 이름을 지은 다음에 뒤에 있는 람다 표현식의
	//주소를 받아서 그걸 실행

	auto inha = [] {cout << "Hi Lambda" << endl; };
	//변수가 표현식에 대한 주소를 갖고있는 상태
	//실행을 하려면 변수를 이용하여 익명함수를 실행시켜야 함
	inha();


	//두 수를 더한 값을 출력하는 코드 작성
	auto inha2 = []() {return 5 + 10; };
	cout << inha2() << endl;


	//던져준 값으로 처리하게 하고싶은 코드 작성
	//매개변수 리스트 활용해야함
	auto inha3 = [](int x, int y) {return x + y; };
	cout << inha3(5, 10) << endl;


	//화살표 사용하면 리턴타입이 꼭 필요
	auto inha4 = [](int x, int y)->int {return x + y; };
	cout << inha4(5, 10) << endl;
	//이런 경우는 계산값을 다른 type으로 리턴할때 casting을 위해
	//화살표기호랑 리턴타입 같이 사용해주어야함


	//바로 실행하는 괄호 안에 파라미터 넘겨주기 가능
	//(직접 인수 던져 처리)
	auto inha5 = [](int x, int y)->int {return x + y; }(5, 10);
	cout << inha5 << endl;


	//casting해야하는 상황
	//ex 매개변수 하나는 실수고 하나는 정수
	//두 수를 더한걸 리턴하려고함
	//리턴타입에 따라 값이 달라질 수 있음
	auto inha6 = [](float x, int y)->int {return x + y; };
	cout << inha6(7.7f, 2) << endl;
	//float랑 int랑 크기는 같아도 실수 타입이 더 크기 크게 취급됨
	//그래서 x+y연산을 할때 이미 integral promotion이 일어나서
	//x+y값 자체가 float가 되었음
	//강제로 int로 casting해서 9.7->9로 casting되어 9가 출력됨

	auto inha7 = [](float x, int y)-> float {return x + y; };
	cout << inha7(7.7f, 2) << endl;
	//이건 9.7 출력됨


	//화살표와 반환타입 생략하고 실행해보면
	auto inha8 = [](float x, int y) {return x + y; };
	cout << inha8(7.7f, 2) << endl;
	//자동으로 return 값의 결과에 따라
	//float와 integer를 더했을 때 integral promotion에 의해 형변환이 일어나고
	//x+y의 결과는 좀 더 큰 타입으로 간주되는 float type의 결과를 리턴

	//return type 명확하게 주지 않으면 들어가는 값에따라 형변환에 의해
	//의도치 않은 값이 리턴될 수 있다.



	//캡쳐블럭
	//람다함수 안에서 참조하려고 하는 바깥변수를 지정
	//여기서 지정된 변수는 람다 함수의 영역 안으로 들어와서
	//함수 바디에서 access 가능


	short c = 5, d = 7;
	auto inha9 = [c, d](float x, int y)->int {return x + y + c + d; };
	cout << inha9(1.9f, 2) << endl;
	//캡쳐 블록이 외부변수를 참조하게 해줌(접근을 가능하게 해줌)
	//auto inha9 = [](float x, int y)->int {return x + y + c + d; }; //캡쳐블록 안 지우면 에러

	auto inha10 = [c, d](float x, int y) {return x + y + c + d; };
	cout << inha10(1.9f, 2) << endl;
	//자동으로 float값이 리턴됨(가장 큰 size의 개념으로 카운팅 되는 것이 float 되기 떄문에)
}