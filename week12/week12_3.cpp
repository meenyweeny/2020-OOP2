#include<iostream>
using namespace std;

void C() {
	throw 121;
}

void B() {
	C();
}

//���޹��� ���� �ٽ� ������
void A() {
	try {
		B();
	}
	catch (int ex) {
		cout << "����(A�Լ�) = " << ex << endl;
		throw; //���� �ٽ� ������
		//���� �ٽ� ������ �� �ٽ� �Լ��� �Ž����ö󰡸鼭
		//�ű⿡ �˸´� ��ü ����� ã�� �ȴ�
	}
}

int main() {
	try {
		A();
	}
	catch (int ex) {
		cout << "����(main�Լ�) = " << ex << endl;
	}
}

//������ζ�� A�Լ����� �̹� ���� ��� ó���ؼ� A ������ �����µ�
//catch�ؿ� throw;�� ���ָ� ���� ���ܸ� �� �佺����