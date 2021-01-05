//정적멤버(static) : 모든 객체가 공유하는 멤버
/*
#include<iostream>
#include<string>
using namespace std;

class Student {
public:
	string name;
	int sNo;
	Student(const string& name_arg, int stdNumber) {
		student_count++;
		name = name_arg;
		sNo = stdNumber;
	}
	~Student();

public:
	//이 두 가지 값은 여러 객체가 공유하고 있음
	static int student_count;
	static void PrintStdCount() {
		cout << "Student 객체 수 = " << student_count << endl;
	}
};

int Student::student_count = 0;
Student::~Student() {
	student_count--;
}

void Func() {
	Student std1("김인하", 20191234); //객체생성 +1
	Student std2("박인하", 20171111); //객체생성 +1
	Student::PrintStdCount();
	//Func함수 끝날 때 std1,std2 객체가 소멸
}
int main() {
	Student::PrintStdCount();
	//static 멤버 메서드는 객체생성없이도 쓸 수 있다

	Student std("최인하", 20202323); //객체생성 +1
	Student::PrintStdCount();
	Func();
	Student::PrintStdCount();
}
*/

//===============================================

//inline 키워드
//함수를 call하면 그쪽으로 이동하고 돌아오는게 아니라
//함수에 있는 내용을 그대로 옮겨 적는다는 원리

/*

#include<iostream>
using namespace std;

inline void Test() {
	//inline 키워드는 아래 코드를 밑으로 가져오는 역할
	//호출한 쪽으로 가서 처리하는게 아니라
	//함수에 있는 코드를 가져와서 끼워넣는 것

	//함수 안의 코드가 길지 않으면서, 자주 참조하거나 할 때는
	//inline 방식으로 쓰는 것이 유리
	//너무 길면 오히려 가져오는데 오버헤드가 발생할 수 있음
	//짧은 코드는 오버헤드 x

	//근데 모든걸 inline으로 안하는건 단점도 있긴 있음

	cout << "1" << endl;
	cout << "2" << endl;
	cout << "3" << endl;
}

//멤버함수도 inline으로 만들 수 있음
//class 안에서 "구현까지 정의된" 멤버함수들은
//모두 자동으로 inline함수가 된다
//근데 void AccessControl::AccessAllMembers(){} 처럼
//밖으로 빼서 구현하면
//inline함수가 아님
//밖으로 빼서 구현했는데도 inline으로 하고싶으면
//구현시에 return type 앞에 inline 키워드 앞에 붙이면 된다

int main() {
	Test();
	//inline함수 호출이랑 밑에 이렇게 쓰는거랑 같다

	//cout << "1" << endl;
	//cout << "2" << endl;
	//cout << "3" << endl;
	return 0;
}

*/

//================================================

//c++ 17부터는 inline 키워드를 변수에도 쓸 수 있게 해줌
//modern

#include<iostream>
#include"test.h"
using namespace std;

//const static -> 선언과 동시에 초기화 가능
//static -> 외부에다가 해당 변수에 관련된 초기화 해야함

//c++ 17부턴 inline variables가 등장하며 선언과 동시에 초기화 가능해짐
//inline variable은 헤더파일에서만 동작

int main() {
	Test aa;
	cout << aa.a++ << endl;
	cout << aa.a << endl;
	cout << aa.q << endl;
}