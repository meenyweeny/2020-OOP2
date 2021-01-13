#include<iostream>
using namespace std;

//���õ� �ڵ庰�� ������ ������ ������ ȿ����
//namespace �������!
//�ҽ����ϰ� �ڵ带 ���������� ������ �� �ִٴ� ������ ����


namespace Python {
	struct Info {
		//struct�� ������ �� public
		string prof;
		int id;
		//����ü �ȿ��� ������� ���� ����
	};

	float grade;
	void talk() {
		cout << "Python ��ũ�Լ�" << endl;
	}
}

namespace Cplusplus {
	class Info {
	public:
		string prof;
		int id;
	};
	float grade;
	void talk();
}

float grade = 0.0f; //default namespace�� ���ϴϱ�
//������ �������� �ʰ� �տ� �ݷ� �ΰ��� �ٿ��� ��� ����


//using Cplusplus::talk; //talk �Լ��� ��
//using Python::talk;
using namespace Cplusplus; //���⿡ �ִ� ��ü�� �� ��

int main() {
	Cplusplus::grade = 4.5f;
	::grade = 4.0f; //���������� grade�� ����

	cout << ::grade << endl;

	Cplusplus::talk(); //�̰͵� �����ϰ�
	//main ���� using Cplusplus::talk; ��θ�
	//�׳� talk(); �ص� Cplusplus�� talk �Լ��� ����ȴ�
	//�ٵ� �׷��� �ϴ� �� ���� �̷��� ��Ȯ�ϰ� �ϴ°� ������ �ȳ��� ����

	talk(); //���� using namespace ������ ���� �ȵǾ������� ����
	Python::talk();


	Info p1; //Cplusplus�� Info ��ü�� �ڵ����� ����
	p1.prof = "������";
	p1.id = 2020;
	//grade = 3.9f; //�̷����ϸ� �������� grade���ϴ°��� cplusplus�� ���ϴ°��� ����
	//�������� grade ���ִ��� grade�� Ŭ������ ��������� �ִ���

}

namespace Cplusplus { //�����ڵ�
	//������ ���� �����ϴ� ���
	void talk() {
		cout << "C++ ��ũ�Լ�" << endl;
	}
}