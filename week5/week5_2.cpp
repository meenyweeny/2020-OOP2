#include<iostream>
#include<functional>
using namespace std;

//�����Լ� ����
//�͸��Լ���
//�Լ� ��ü�� �����Ѵ�
//�Լ� �����Ϳ� �Լ� ��ü�� ������ ���Ѵ�
//ĸ�� ����� ���� �Լ� ���� ������ ������ �� �ְ�
// &���� ��ȣ�� ���� �����Լ� �ȿ����� �ܺ� ������ ���� ������ �� �ִ� (�����ϱ� ����)
//��� ȣ�⵵ �����ϴ�.
//�̿ܿ��� ��� ����� �� ����



int k = 1;
int main() {
	short c = 5, d = 7;
	auto inha = [c, d](float a, int b)->int { 
		//c = -11; //����->�ܺ� ������ ������ �� ����
		//�� ������ '�����μ�' �����ؼ� (ĸ���ؼ�) ����ϱ� ����
		k = 2; //���������� ������ �ǰ� ĸ�ĺ�Ͽ� ���� ���� ���ص� ��
		return a + b + c + d+k; };
	cout << inha(1.9f, 2) << endl;

	//���� �� �ٲٰ� �ʹٸ� ���ۻ��� ��ȣ�� ĸ���ؿ��� (�� ���� ���·� ĸ������)
	auto inha2 = [&c, d](float a, int b)->int {
		c = -11; //���� ��������
		return a + b + c + d + k; };
	cout << inha2(1.9f, 2) << endl;
	cout << c << endl; //updated

	short x = 5, y = 7;
	//���ο��� ���� �� �� �����ϰ� �ʹٸ�

	//1.�� �� ���ۻ��� ��ȣ ����
	auto inha3 = [&x, &y](float a, int b)->int {
		x = -11; //���� ��������
		y = 8;
		return a + b + x + y; };
	cout << inha3(1.9f, 2) << endl;

	//2.���ۻ��� ��ȣ �ϳ��� �� ����
	//���� ��� �����Լ����ִ� ������ ���� �����μ� ���̴� ��
	auto inha4 = [&](float a, int b)->int {
		x = -11; //���� ��������
		y = 8;
		return a + b + x + y; };
	cout << inha4(1.9f, 2) << endl;

	x = 5, y = 7;

	//=�� ������ ��ȭ�� ����Ű�� �׳� ��ü ���� �����Ѵٴ� ��
	//��ü ������ �����μ� ĸ��
	auto inha5 = [=](float a, int b)->int {
		//x = -11; //��ȭ�� �Ұ���
		return a + b + x + y; };
	cout << inha5(1.9f, 2) << endl;


	
	
	
	//��ȯŸ�Կ� ���� ��


	auto inha6 = [=](float a, int b)->int {
		return a + b + x + y; }(1.9f, 2);
	cout << inha6 << endl;
	cout << typeid(inha6).name() << endl;
	//int��� ��µȴ�
	//auto�� ������ inha6�� �Ϲ� ������ �������� �� �� �ִ�


	auto inha7 = [=](float a, int b)->int {
		//x = -11; //��ȭ�� �Ұ���
		return a + b + x + y; };
	cout << typeid(inha7).name() << endl;
	//int��� �ȳ����� Ŭ�������پ�¼����
	//�̰� int �Ϲݺ��� �ƴϰ� Ŭ���� ��ü��
	cout << inha7(1.9f, 2) << endl;






	//�ŵ������� ���ϴ� �����Լ�(power)
	auto power = [](int base, int e)->int {
		int result = 1; //�Լ� ���� ��������
		for (auto i = 1; i <= e; i++)
			result *= base;
		return result;
	}(2,8);
	cout << power << endl;

	//return �� ��Ȯ�ϴϱ� auto ���� �Լ����� ������� ��Ȳ
	int power2 = [](int base, int e)->int {
		int result = 1; //�Լ� ���� ��������
		for (auto i = 1; i <= e; i++)
			result *= base;
		return result;
	}(2, 8);
	cout << power2 << endl;

	//return Ÿ�� ����������µ� �׳� auto ���� �Լ����� ������� ��Ȳ
	int power3 = [](int base, int e) {
		int result = 1; //�Լ� ���� ��������
		for (auto i = 1; i <= e; i++)
			result *= base;
		return result;
	}(2, 8);
	cout << power3 << endl;

	

	//�̰� ������
	//��?
	//�����Լ� ��ü�ε� power4�� �����Լ��� �����ּҸ� �޾ƾ� �ϴ� �����ε�
	//�װ� int Ÿ���̶�� ������ �س����ϱ� �ȵȴ�
	/*
	int power4 = [](int base, int e){
		int result = 1;
		for (auto i = 1; i <= e; i++)
			result *= base;
		return result;
	};
	cout << power4(2,8) << endl;
	*/

	//�̷��� auto�� �����ָ� �ٷ� ��
	auto power5 = [](int base, int e) {
		int result = 1;
		for (auto i = 1; i <= e; i++)
			result *= base;
		return result;
	};
	//power5�� �����ε� �Լ� ������ �ش� �ּҸ� �����ؼ� �Լ�ó�� �� �� �ִ� ��
	cout << power5(2, 8) << endl;
	cout << power5(4, 2) << endl;




	//======================================================


	//����Լ� �����غ���
	//���ٴ� ���� �ܺο� �Լ� ���� �ʿ䰡 ����
	/*
	auto fact = [&fact](int n)->int {
		if (n == 1)
			return 1;
		else
			//return n * fact(n - 1); //����
			//��?
			//�ٽ� ȣ���� fact(n-1)�� ���忡�� �ۿ��� fact �Լ��� ã�� �� ����
			//ĸ�ĺ�Ͽ� &fact�� �־ �ذ�
			//�ٵ� �� ������ ���� ��?
			//auto�� �������� Ÿ�Զ����� ����
			//��?
			//�Լ��� �ڱ� �ڽ��� ȣ���ϴ°� ����ε� �װſ� ���� ���ϰ���
			//�߷��� �� ���� �����ϱ�

	}
	*/

	//->���⼭ functional�̶�� �ϴ� ���̺귯�� ����Ѵ�

	//���ٿ��� ��͸� ������ �� auto Ÿ�����δ� �߷� �Ұ�
	//�ݵ�� �����Ϸ��� �ϴ� �Լ��� Ÿ���� ��õǾ�� ��
	//functional library�� �ʿ�
	//����Լ��϶��� �̷� �κ��� ����

	//�����Ϸ��� auto�� �߷��� �Ϸ��� �Ѿ���� ������ ���� �ؾ��ϴµ�
	//�Ѿ���� ������ ���⵵ ���� ���ʿ��� �ڱ��ڽ��� ȣ���ϰ� ����
	//auto�� �װ� �˱� ���ܰ迡�� call�� �ϸ�(���) �� ���� ����
	//�װ� �˱� ���ؼ��� �ƿ� �̰� � ������ ������ �ǰ� �ִ�����
	//������־�� �Ѵ�
	//��, ����Լ����� function ���̺귯���� �ű⿡ �´� Ÿ�Կ� ���� ������ ����� �Ѵ�

	function<int(int)> fact = [&fact](int n)->int {
		if (n == 1)
			return 1;
		else
			return n * fact(n - 1);

		// return n <= 1 ? 1 : n * fact(n - 1);
	};
	cout << fact(6) << endl;



}