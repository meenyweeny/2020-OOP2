//변수, 함수의 범위와 존속기간
/*
#include<iostream>
using namespace std;

//extern->다른 소스파일에 선언된 전역변수 사용
extern int ga;

int g = 10; //전역변수(일반)
int a = 8; //전역변수(일반)

extern int gk; //외부의 static 전역변수
//static이라는 키워드가 붙으면 해당 파일 안에서만 쓸 수 있게 된다

void test() {
	int l = 7; //main안에 있는 애랑 다르다, 지역변수
	cout << l << endl;
	cout << g << endl;
	cout << ga << endl;
}

void static_test() {
	static int n = 0;
	int k = 0;
	cout << n++ << endl;
	cout << k << endl;
}

int main() {

	//cout << gk << endl; //외부의 static 전역변수라 쓸 수 없음

	int l = 5;
	cout << l << endl;
	test();
	g++;
	cout << g << endl;
	test();

	//블럭 안에서의 scope
	//{
	//	int a = 1;
	//	cout<<a<<endl;
	//}
	//cout << a << endl; //위 블럭 안에서만 영향을 미치는 변수라 에러가 남
	


	cout << a << endl;
	//다른 영역에 정의한 변수 이름의 중복
	int a = 9;
	cout << a << endl;
	{
		cout << a << endl;
		int a = 1;
		cout << a << endl;
	}
	cout << a << endl;

	//static으로 정의한 지역변수
	//static을 붙여서 지역변수를 정의하면 변수의 존속기간이 바뀜
	//변수를 정의하는 순간에 생성되는 것은 동일하지만,
	//이 변수는 프로그램이 끝날 때 까지 살아있게 된다
	//(원래는 해당 함수과 끝남과 동시에 사라지게 됨)

	static_test();
	static_test();
	static_test();

	//존속기간이 늘어난다고 해서 scope가 바뀌는 것은 아님
	//즉 main에서 static_test 함수의 n을 쓰는 것이 안됨
}
*/

//함수의 범위와 존속기간

#include<iostream>
using namespace std;
extern void func(); //외부 파일의 함수 사용
extern void static_func(); //외부 파일의 static 함수 사용

//c언어로 작성된 함수를 쓰고싶으면?
//extern void c_test(); //이러면 안됨
extern "C" void c_test(); //c언어라고 표시해줘야 가능

int main() {
	func();
	//static_func(); //static이니까 불가능
	c_test();

	//레지스터 변수
	register int i = 0;
	while (i < 1000000) {
		i++;
	}
	//백만번 반복할텐데 register 키워드를 써주면 운영체제한테
	//메모리공간대신에 cpu안의 가장 빠른 저장공간인 레지스터 사용해달라고 부탁
	//메모리 갔다오는 것보다 레지스터 갔다오는게 훨씬 빠르니까
	//연산작업이 빨리 끝나게 됨 //운영체제의 여건 상 다름
	//근데 요즘은 가능한 한 기본적으로 레지스터 사용해서 성능 올리려고 하기 때문에
	//굳이 따로 이 키워드 안쓰는 추세
}