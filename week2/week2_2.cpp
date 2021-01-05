#include<iostream>
using namespace std;

int main() {
	auto f = 3.244562156f;
	//const Ű���� ���̸� ����Ұ�
	//f �Ⱥ��̸� �⺻������ �Ǽ�Ÿ���� double�� ����
	//auto �� type�� �߷����ִ°�

	auto s = "testgood";
	cout << f << endl; //3.24456
	cout << s << endl;
	cout << typeid(f).name() << endl;
	cout << typeid(s).name() << endl;
	cout << sizeof(f) << endl;
	cout << sizeof(s) << endl;
	//char const * �̹Ƿ� �����Ͱ� ������ size ������ 4����Ʈ

	const char * ch = "test";
	cout << sizeof(ch) << endl;
	char chs[] = "test";
	cout << sizeof(chs) << endl;

	//===================================================
	cout << endl; //void pointer
	cout << "void pointer" << endl;
	//��ó�� �� �� �ִ� ���, � Ÿ���̵� �� ���� �� ����
	short * ps;
	short a = 2;
	ps = &a; //�� ���� type�� ������ �ּҷ� ���� �� �ִ�
	cout << *ps << endl;
	void * pv;
	pv = &a; //void�� �ٹ��������� �޴� �������� ���� �ȳ�
	//�ٸ� �ּҸ� �׳� �޴°Ŷ� ���� ���� � �ڷ������� ��
	//�׷��� ����� �� type�� �˷������(���α׷��Ӱ� �˰��־����)
	cout << *(short*)pv << endl; //casting

	double b = 3.14;
	pv = &b;
	cout << *(short*)pv << endl;
	//double�ε� �߸�casting�ؼ� �������� -31457����
	//�ٵ� �ű�ٰ� 8����Ʈ�ΰ� 2����Ʈ�� ������� �Դٰ� �Ǽ��ΰ�
	//�׷��ϱ� �̷��� ������ ���� �� �ۿ� ����

	cout << *(double*)pv << endl; //��Ȯ�ϰ� ��½������� �˷������

	cout << endl;
	//========================================
	cout << "���ڿ� �迭�� void ������" << endl;
	char sa[] = "Hell"; //���� �ڵ����� null ���Ե�
	char sarr[] = { 'H','e','l','l','\0' }; //���� �˷��ֱ�����
	//���� �� null ���� �־����
	cout << sa << endl;
	cout << sizeof(sa) << endl; //5
	void * pss = &sa[0]; //�Ǿչ��� �ּ�
	pss = sa; //�迭���� ������ ����̹Ƿ� �̰͵� ���� ���� �����ǹ�
	cout << pss << endl; //�ּҰ� ����
	cout << *(char*)pss << endl; //0������ H �� �ϳ��� ����
	cout << (char*)pss << endl; //�� �ϳ��� �ƴ϶� ��ü�� ����
	for (int i = 0; i < sizeof(sa) / sizeof(char); i++) { //5����
		cout << *(char*)pss + i; //7273747576
	}
	cout << endl;
	for (int i = 0; i < sizeof(sa) / sizeof(char); i++) { //5����
		cout << *((char*)pss + i);
		//i���� ���ϸ� �׵��� ����Ű�� ��ġ���ִ� ���� 
		//0��°ĭ�� �ּ��� ��, 1��° ĭ�� �ּ��� ��,...
	}
	cout << endl;
}