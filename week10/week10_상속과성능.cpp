#pragma warning (disable : 4996)
#include<iostream>
#include<string>
using namespace std;

class Human {
protected:
	string name; //string���� �ٲ��ֱ�
	int age;
public:
	Human(const string & aname, int aage) {
		name = aname;
		age = aage;
	}
	virtual void intro() { //�����Լ��� ������ֱ�
		cout << "�̸� = " << name << ", ���� = " << age << "\n";
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
		cout << "�̰��� : " << subject << " (��米�� : " << name << ")\n";
	}
	void talk() {
		cout << "�� �� �ϰڳ�!\n";
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
		cout << id << "�й�" << name << "�Դϴ�.\n";
	}
	void study() {
		cout << "ĳ����, ��������, ���߻��, ������, �����Լ�, ���������Լ�\n";
	}
};

int main() {
	Human h("Ʈ�����ʸ���", 10);
	Student s("���ϳ�", 21, 20191234);
	Prof p("������", 40, "OOP2");
	Human * ph = &h; //����� ���ÿ� �ʱ�ȭ ( ���߿� ���� x )
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