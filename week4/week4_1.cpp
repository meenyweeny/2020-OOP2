//열거체
/* 열거체 사용 전
#include<iostream>
using namespace std;

struct Character {
	int jobType; // 0:강령술사, 1:야만용사, 2:마법사
};

int main() {
	Character c;
	c.jobType =2;

	if (c.jobType ==2) {
		cout << "비전격류!" << endl;
	}
	//숫자 2가 어떤 캐릭터인지 코드를 보고서는 명확하게 알 수 없다
	//이 문제를 열거체를 이용해서 해결할 수 있다

}
*/

/*
#include<iostream>
using namespace std;

//enum { JOB_NECROMANCER, JOB_BARBARIAN, JOB_WIZARD };
//값들 자체가 수치의 의미를 가짐 0,1,2,...

//enum {JOB_NECROMANCER,JOB_BARBARIAN=2, JOB_WIZARD};
//값이 0,2,3,.. 이렇게 됨 (인덱스 값 변병가능)

//열거체도 struct,union처럼 하나의 타입
//그래서 이름을 가질 수 있음
enum JOB_KINDS {JOB_NECROMANCER,JOB_BARBARIAN,JOB_WIZARD};

struct Character {
	//int jobType; // 0:강령술사, 1:야만용사, 2:마법사
	JOB_KINDS jobType; //int 대신 enum type으로 열거체 변수로 해줬음
};

int main() {
	Character c;
	c.jobType = JOB_WIZARD;

	if (c.jobType == JOB_WIZARD) {
		cout << "비전격류!" << endl;
	}
	//명확하게 알 수 있다

}
*/

#include<iostream>
using namespace std;

enum Color {RED,GREEN,BLUE,YELLOW};
//기본적으로 int 타입으로 동작하지만 (0,1,2,...였던것처럼)
//정수의 기본적인 연산이 가능하지 않다 (ex: GREEN+BLUE 불가)

//enum의 가장 큰 문제는 정수형변수로 묵시적으로 변환되는
//weak type 변수
//항상 정수를 베이스로 하고 있고 나랑 상관없는 정수랑 연결되면
//문제를 일으킬 소지를 항상 갖고 있다

/*
enum Java{PASS,FAIL};
enum Python{PASS,FAIL};
*/

//다른 열거체임에도 불구하고 같은 이름의 변수를 쓸 수 없는 문제가 있다

int main() {
	Color c1 = RED;
	Color c2;

	//명시적 Casting 후 대입 가능
	//명시적으로 숫자 2를 Casting하여 할당
	Color c3 = (Color)2; //BLUE가 저장되는 효과를 갖는다
	cout << c3 << endl;

	//하지만 range가 중요
	Color c4 = (Color)1000;
	//이렇게 해버리면 오류는 안나긴하는데
	//Color 구조체에 없는 거니까 뭔지 알수가 없게 된다
	//1000에 해당하는 기호가 없어서 결과 보장 불가

	//반대의 경우 대입과 산술 연산이 가능
	//이유:묵시적 Casting
	int n = BLUE; //int형에 직접 값을 넣는 것은 가능
	int o = GREEN + BLUE; //int형에 덧셈값 넣기 가능
	//즉 받는 쪽의 변수가 구조체 변수가 아니라 int면 받을 수 있다
	//열거체의 symbol들이 묵시적으로 int 타입으로 casting 되고 있음

	cout << n << endl;
	cout << o << endl;

	//산술연산 불가
	//c1 = GREEN + BLUE; //error
	//c1 = c1 + 2;

	//정수대입 불가
	//c2 = 3;
}