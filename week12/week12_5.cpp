//�տ��� ���캻 ������ ����ó���� ������
//1. �ڿ��� �����ϱ� ���� �Լ��� ���� ��������

/*
#include<iostream>
using namespace std;

void B() {
	throw "Exception!!";
}

void A() {
	char * p = new char[100]; //���� �޸� �Ҵ�
	cout << "���ܰ� �߻��ϱ� ��" << endl;
	B();
	//���ܷ� ���ؼ� �����Ҵ�� �޸𸮰� delete ���� ���ϴ� ������ �����ִ�
	//B�� ������ �߻���Ű�� �Լ��ε�, throw�� �������� A���� ���� ���� ���
	//main�Լ��� catch�� �ٷ� ����
	//�Ʒ��� ������ ���� ������ �ȵȴ�

	cout << "���ܰ� �߻��� ��" << endl;
	delete[] p;
	p = NULL; //memory leak
}

int main() {
	try {
		A();
	}
	catch (const char * ex) {
		cout << "���� ���� : " << ex << endl;
	}
}
*/


//������,�Ҹ��ڸ� �̿��ؼ� �ذ��غ���~

#include<iostream>
using namespace std;

class SmartPointer {
public:
	SmartPointer(char * p)
		:ptr(p) {
	}
	~SmartPointer() {
		cout << "�Ҹ��� ���� : �޸� ����~" << endl;
		delete[] ptr;

	}
	char * const ptr;
};

void B() { throw "Exception!!"; }
void A() {
	char * p = new char[100];
	SmartPointer sp(p); //�����޸��Ҵ�� ���޸𸮿����� �����ּ� ���� p�� ������
	cout << "���ܰ� �߻��ϱ� ��" << endl;
	B();
	cout << "���ܰ� �߻��� ��" << endl; //�̰� �������� ������
	//SmartPointer�� �Ҹ��ڰ� ������ �� -> ���������� delete[] ptr�� ����
	//ptr�� ����Ű�� ������ new char[100]�� �̻���� ������
	//�Լ��� B()�� ���� ���������� ������ �Ҹ��ڴ� ������ ��
}

int main() {
	try {
		A();
	} catch (const char * ex) {
		cout << "���� ����: " << ex << endl;
	}
}