//��������

#include<iostream>
using namespace std;

class AccessControl {
	//�ƹ��͵� ���������ָ� �⺻������ private
public:
	char publicData;
	void publicFunc() {};
protected:
	int protectedData;
	void protectedFunc() {};
private:
	float privateData;
	void privateFunc() {};
public:
	void AccessAllMembers();
};

void AccessControl::AccessAllMembers() {
	//class �ȿ����� ���� �����Ӱ� ����
	publicData = 'A';
	publicFunc();
	protectedData = 100;
	protectedFunc();
	privateData = 4.5f;
	privateFunc();
}


int main() {
	AccessControl ac;
	/*
	//����
	ac.publicData = 'A';
	ac.publicFunc();

	//�Ұ���
	//�ܺο��� ���� �Ұ�
	ac.protectedData = 100;
	ac.protectedFunc();
	ac.privateData = 4.5f;
	ac.privateFunc();
	*/


	ac.AccessAllMembers();

}
