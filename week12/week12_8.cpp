//����, �Լ��� ������ ���ӱⰣ
/*
#include<iostream>
using namespace std;

//extern->�ٸ� �ҽ����Ͽ� ����� �������� ���
extern int ga;

int g = 10; //��������(�Ϲ�)
int a = 8; //��������(�Ϲ�)

extern int gk; //�ܺ��� static ��������
//static�̶�� Ű���尡 ������ �ش� ���� �ȿ����� �� �� �ְ� �ȴ�

void test() {
	int l = 7; //main�ȿ� �ִ� �ֶ� �ٸ���, ��������
	cout << l << endl;
	cout << g << endl;
	cout << ga << endl;
}

void static_test() {
	static int n = 0;
	int k = 0;
	cout << n++ << endl;
	cout << k << endl;
}

int main() {

	//cout << gk << endl; //�ܺ��� static ���������� �� �� ����

	int l = 5;
	cout << l << endl;
	test();
	g++;
	cout << g << endl;
	test();

	//�� �ȿ����� scope
	//{
	//	int a = 1;
	//	cout<<a<<endl;
	//}
	//cout << a << endl; //�� �� �ȿ����� ������ ��ġ�� ������ ������ ��
	


	cout << a << endl;
	//�ٸ� ������ ������ ���� �̸��� �ߺ�
	int a = 9;
	cout << a << endl;
	{
		cout << a << endl;
		int a = 1;
		cout << a << endl;
	}
	cout << a << endl;

	//static���� ������ ��������
	//static�� �ٿ��� ���������� �����ϸ� ������ ���ӱⰣ�� �ٲ�
	//������ �����ϴ� ������ �����Ǵ� ���� ����������,
	//�� ������ ���α׷��� ���� �� ���� ����ְ� �ȴ�
	//(������ �ش� �Լ��� ������ ���ÿ� ������� ��)

	static_test();
	static_test();
	static_test();

	//���ӱⰣ�� �þ�ٰ� �ؼ� scope�� �ٲ�� ���� �ƴ�
	//�� main���� static_test �Լ��� n�� ���� ���� �ȵ�
}
*/

//�Լ��� ������ ���ӱⰣ

#include<iostream>
using namespace std;
extern void func(); //�ܺ� ������ �Լ� ���
extern void static_func(); //�ܺ� ������ static �Լ� ���

//c���� �ۼ��� �Լ��� ���������?
//extern void c_test(); //�̷��� �ȵ�
extern "C" void c_test(); //c����� ǥ������� ����

int main() {
	func();
	//static_func(); //static�̴ϱ� �Ұ���
	c_test();

	//�������� ����
	register int i = 0;
	while (i < 1000000) {
		i++;
	}
	//�鸸�� �ݺ����ٵ� register Ű���带 ���ָ� �ü������
	//�޸𸮰�����ſ� cpu���� ���� ���� ��������� �������� ����ش޶�� ��Ź
	//�޸� ���ٿ��� �ͺ��� �������� ���ٿ��°� �ξ� �����ϱ�
	//�����۾��� ���� ������ �� //�ü���� ���� �� �ٸ�
	//�ٵ� ������ ������ �� �⺻������ �������� ����ؼ� ���� �ø����� �ϱ� ������
	//���� ���� �� Ű���� �Ⱦ��� �߼�
}