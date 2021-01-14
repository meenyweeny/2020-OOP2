//입출력
//iostream 내부에
//ostream은 cout객체의 부모, istream은 cin객체의 부모 역할
/*
//iostream 헤더파일 구성
//extern 키워드인것으로 보아 어딘가에 정의가 되어있을 것이다
//(각각 ostream, istream 객체의)
//근데 그냥 class가 아니라 template 클래스를 아래와같이 재정의한 type
//typedef로 정의된것을 보아 우리가 사용한 cout 객체는
//basic_ostream<char> 의 객체임을 알 수 있다

extern ostream cout;
extern istream cin;
typedef basic_ostream<char> ostream;
typedef basic_istream<char> istream;


basic_ostream // cout 객체의 타입
basic_istream // cin객체의 타입

//이 둘의 부모클래스 - > basic_ios
//또 이것의 부모클래스 - > ios_base

//그래서 cout이나 cin이 ios_base에 있는 기능들을 쓸 수 있다
*/

//stream? 연결된 파이프라인에 흘러가는 데이터의 흐름
/*
#include<iostream>
using namespace std;

int main() {
	float f = 0.01234f;
	ios_base::fmtflags old;
	//입출력 포맷과 관련된 기능을 제공하는 클래스
	//fmtflags type - > setf의 리턴타입, int 타입으로 리턴해줌

	cout << f << endl;

	old = cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << f << endl; //0.12340

	old = cout.setf(ios_base::scientific, ios_base::floatfield);
	//old가 setf의 리턴을 받는 변수로 사용이 되었음

	//setf는 출력형식 지정하는 기본적인 함수
	//1.234000e-02 (e-02는 10의 -2승)4

	//setf의 인수가 두개임
	//뒤에 오는 것은 floatfield->실수계열 다루기가능
	//basefield->dec,hex,oct 다루기 가능
	//adjustfield

	//앞에 오는 것은, 뒤에것이 floatfield일 때 두가지가 올 수 있음
	//지수형태->scientific, 고정소수점형태->fixed

	//old라는 정수로 받은 것 같지만 비트들이 의미를 갖고 있게 됨
	//그래서 저 인자들은 비트를 조정해줌

	//여기서의 old는 기존 정보를 백업하고 있었고, 옆에서 새로운 정보를 setting
	//setting된 대로 아래에서 출력
	cout << f << endl;

	cout.setf(old, ios_base::floatfield);
	//다시 원워치로 돌아가기 위해서 이전에 백업해둔 setting값을 가져옴

	cout << f << endl;


	int a = 10;
	cout << a << endl;
	//cout << hex; //내부적으로 연산자오버로딩이 되어있는 것
	cout.setf(ios_base::hex, ios_base::basefield); //cout<<hex와 같음
	cout << a << endl;


	bool test = true;
	cout << test << endl;
	//cout << boolalpha; //연산자 오버로딩을 통한 구현
	cout.setf(ios_base::boolalpha); //인수 하나로 위에꺼랑 같은 역할을 함
	cout << test << endl;
	//위의 old처럼 원상태로 백업해둔것이 없으면 어떻게 돌아갈까?
	cout.unsetf(ios_base::boolalpha);
	//setf의 인자 하나만 들어오는 경우엔 unsetf를 통해 되돌린다
	cout << test << endl;

}

*/

//setf말고도 출력형식을 지정해주는 다른 함수들
//너비 조정하는 width()
//소수점 자리 조정해주는 precision() 등등

#include<iostream>
using namespace std;

int main() {
	
	int a = 11;
	//cout.width(5);
	cout << a << endl;
	
	float f = 0.01234f;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << f << endl;
	cout.precision(3); //고정 소수점을 세자리까지 하겠다
	cout << f << endl;
}