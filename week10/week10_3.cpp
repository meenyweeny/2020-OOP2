#include<iostream>
using namespace std;
#include<string>

//���߻��
//�ΰ� �̻��� �θ�Ŭ������ ���ÿ� ����ϴ� ���
//������ ����� �� Ȱ���� �� �ִ� ������ �ִ�
//�� ���� ����� �� �ٸ� ���� �Ⱦ���?

//�������� �ִ�
//������ ���̾Ƹ�� ���...


class UnderGradStudent { //�кλ�
public:
	string name;
	string dept;

	void Warn() {}; //�л���
};

class DormStudent { //������
public:
	string building;
	int roomNo;

	void Warn() {}; //���� ����� ���
};

class UnderGrad_DormStudent :
	public UnderGradStudent, public DormStudent {
public:

};


int main() {
	UnderGrad_DormStudent s1;
	s1.name = "������";
	s1.dept = "CSE";
	s1.building = "1st";
	s1.roomNo = 1024;

	//s1.Warn(); //���� �θ�κ��� ����� ���� ��ü�̱� ������
	//��� ��ӹ޾ƾ����� �𸥴� //�׷��� error


	//scope �������� �ذ� ����
	s1.DormStudent::Warn();
}