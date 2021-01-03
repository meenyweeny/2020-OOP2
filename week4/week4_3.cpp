//�Լ�(Function)
#include<iostream>
#include<string>
using namespace std;

/*
void Hello() {
	cout << "Hi" << endl;
}

int main() {
	Hello(); //�Լ� ȣ��
}
*/

/*
//main���� Hello()�� ã�� �� ����
int main() {
	Hello();
}
void Hello() {
	cout << "Hi" << endl;
}
*/

//�׷��� ������Ÿ���� �ۼ�
//�̷� ����� ���� �� ���� (�Լ��� ���� ���� �޾Ƴ��� �����ϱ�
/*
void Hello(); //�λ��ϴ� �Լ�

int main() {
	Hello();
}

void Hello() {
	cout << "Hi" << endl;
}
*/

//�Ű����� ����
/*
void Hello(int); //�λ��ϴ� �Լ�

int main() {
	Hello(5);
}

void Hello(int n) {
	cout << "Hi " << n << endl;
}
*/

//���丮���� �����ϴ� �Լ� ������

//���丮�� �Լ� //���,�ݺ� �� �������� ��� ����

void Hello() {
	cout << "Hi" << endl;
}

int Factorial(int); //�ݺ��� �̿��Ͽ�
int FactorialRecursion(int); //��� �̿��Ͽ�

int Factorial(int f) { //�ݺ��� �̿��Ͽ�
	int result = 1;
	for (int i = 1; i <= f; i++)
		result *= i;

	return result;
}

int FactorialRecursion(int n) { //��� �̿��Ͽ�
	//�ݺ����� ���� �����ս��� ������ overhead�� ������ ����
	//�������� good

	//if n=4���
	//f=3
	//f=2
	if (n == 1)
		return 1;
	return n * FactorialRecursion(n - 1);
	//4*FactorialRecursion(3); -> 4*6
	//3*FactorialRecursion(2); -> 3* 2
	//2*FactorialRecursion(1); ->2
	//�� �ٽ� �������� ���ư�
}

int main() {
	cout << Factorial(5) << endl; //�ݺ��� �̿��Ͽ�
	cout << FactorialRecursion(5) << endl; //����Լ� �̿��Ͽ�

	int in;
	cin >> in;
	cout << Factorial(in) << endl;
	cout << FactorialRecursion(in) << endl;

	//�Լ������� Ȱ��
	//�Լ��� ������ �����ؼ� ����� ��
	int(*pFact)(int); //����Ű���� �Լ��� Ÿ���� ��Ī�ǰ� �����ؾ���
	void(*pHi)(); //void ������

	pFact = &Factorial; //�Լ������ʹ� �Լ��� �ּҸ� ����
	//���� �����Ͱ� ������ �ּҸ� �޵���
	pHi = &Hello;

	//pFact = &Hello; //Ÿ�� �ȸ����ϱ� ����

	cout << (*pFact)(in) << endl;
	(*pHi)();
}