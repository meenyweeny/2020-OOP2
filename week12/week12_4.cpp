#include<iostream>
using namespace std;

void C() {
	//throw "Hell"; //���ڿ��� �ϸ� catch�� ���� �� �ִ°� ����
	//���ڿ� ���� ���� �� �ִ� catch �߰�������Ѵ�
	throw 2.71f; //main�� ��Ÿ���ܷ� ó����
}

void B() { C(); }

void A() {
	try {
		B();
	}
	catch (int ex) {
		cout << "����(A�Լ�/����ó��) = " << ex << endl;
		throw;
	}
}

int main() {
	try {
		A();
	} catch (int ex) {
		cout << "����(main�Լ�/����ó��) = " << ex << endl;
	} catch (const char * ex) {
		cout << "����(main�Լ�/���ڿ�ó��) = " << ex << endl;
	} catch (...) {
		//���� ���ϴ� type�� ���ؼ� �̷��� �����ؼ� ���� �� �ִ�
		//catch(...)�� ù��° catch�� ���� �ȵ�
		//��? ( �� ������ �� ��ƹ����� ������ �ؿ��� ó���� ���� ���� )
		cout << "����(main�Լ�/��Ÿ ����)" << endl;
	}
}