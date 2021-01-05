//�������(static) : ��� ��ü�� �����ϴ� ���
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
	//�� �� ���� ���� ���� ��ü�� �����ϰ� ����
	static int student_count;
	static void PrintStdCount() {
		cout << "Student ��ü �� = " << student_count << endl;
	}
};

int Student::student_count = 0;
Student::~Student() {
	student_count--;
}

void Func() {
	Student std1("������", 20191234); //��ü���� +1
	Student std2("������", 20171111); //��ü���� +1
	Student::PrintStdCount();
	//Func�Լ� ���� �� std1,std2 ��ü�� �Ҹ�
}
int main() {
	Student::PrintStdCount();
	//static ��� �޼���� ��ü�������̵� �� �� �ִ�

	Student std("������", 20202323); //��ü���� +1
	Student::PrintStdCount();
	Func();
	Student::PrintStdCount();
}
*/

//===============================================

//inline Ű����
//�Լ��� call�ϸ� �������� �̵��ϰ� ���ƿ��°� �ƴ϶�
//�Լ��� �ִ� ������ �״�� �Ű� ���´ٴ� ����

/*

#include<iostream>
using namespace std;

inline void Test() {
	//inline Ű����� �Ʒ� �ڵ带 ������ �������� ����
	//ȣ���� ������ ���� ó���ϴ°� �ƴ϶�
	//�Լ��� �ִ� �ڵ带 �����ͼ� �����ִ� ��

	//�Լ� ���� �ڵ尡 ���� �����鼭, ���� �����ϰų� �� ����
	//inline ������� ���� ���� ����
	//�ʹ� ��� ������ �������µ� ������尡 �߻��� �� ����
	//ª�� �ڵ�� ������� x

	//�ٵ� ���� inline���� ���ϴ°� ������ �ֱ� ����

	cout << "1" << endl;
	cout << "2" << endl;
	cout << "3" << endl;
}

//����Լ��� inline���� ���� �� ����
//class �ȿ��� "�������� ���ǵ�" ����Լ�����
//��� �ڵ����� inline�Լ��� �ȴ�
//�ٵ� void AccessControl::AccessAllMembers(){} ó��
//������ ���� �����ϸ�
//inline�Լ��� �ƴ�
//������ ���� �����ߴµ��� inline���� �ϰ������
//�����ÿ� return type �տ� inline Ű���� �տ� ���̸� �ȴ�

int main() {
	Test();
	//inline�Լ� ȣ���̶� �ؿ� �̷��� ���°Ŷ� ����

	//cout << "1" << endl;
	//cout << "2" << endl;
	//cout << "3" << endl;
	return 0;
}

*/

//================================================

//c++ 17���ʹ� inline Ű���带 �������� �� �� �ְ� ����
//modern

#include<iostream>
#include"test.h"
using namespace std;

//const static -> ����� ���ÿ� �ʱ�ȭ ����
//static -> �ܺο��ٰ� �ش� ������ ���õ� �ʱ�ȭ �ؾ���

//c++ 17���� inline variables�� �����ϸ� ����� ���ÿ� �ʱ�ȭ ��������
//inline variable�� ������Ͽ����� ����

int main() {
	Test aa;
	cout << aa.a++ << endl;
	cout << aa.a << endl;
	cout << aa.q << endl;
}