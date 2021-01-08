#pragma warning (disable : 4996)
#include<iostream>
#include<string>
using namespace std;

class Human {
protected:
	string name; //string으로 바꿔주기
	int age;
public:
	Human(const string & aname, int aage) {
		name = aname;
		age = aage;
	}
	virtual void intro() { //가상함수로 만들어주기
		cout << "이름 = " << name << ", 나이 = " << age << "\n";
	}
};

class Prof :public Human {
protected:
	string subject;
public:
	Prof(const string & aname, int aage, const string & asubject)
		: Human(aname, aage) {
		subject = asubject;
	}
	virtual void intro() {
		cout << "미공시 : " << subject << " (담당교수 : " << name << ")\n";
	}
	void talk() {
		cout << "한 잔 하겠나!\n";
	}
};

class Student : public Human {
protected:
	int id;

public:
	Student(const string & aname, int aage, int aid)
		:Human(aname, aage) {
		id = aid;
	}
	virtual void intro() {
		cout << id << "학번" << name << "입니다.\n";
	}
	void study() {
		cout << "캐스팅, 접근제어, 다중상속, 다형성, 가상함수, 순수가상함수\n";
	}
};

int main() {
	Human h("트레버필립스", 10);
	Student s("송하나", 21, 20191234);
	Prof p("신지드", 40, "OOP2");
	Human * ph = &h; //선언과 동시에 초기화 ( 나중에 대입 x )
	Student * ps = &s;
	Prof * pp=&p;

	ph = &s;
	ps = (Student*)&h;

	ph->intro();
	ps->intro();
	(*pp).intro();
	pp->talk();
	ps->study();
}