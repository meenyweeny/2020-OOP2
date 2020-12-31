#include<iostream>
using namespace std;
#define MAX 10000

//���,�ݺ���,�迭 ������ ���
int FibonacciRecursion(int);
int FibonacciIterative(int);
int FibonacciArray(int);
int FiboArr[MAX]; //FibonacciArray�� ���� �迭

int n;

int main() {

	//�׳� �Ķ���� 5�� �ְ� ȣ���غ���
	cout << "Fibonacci 5 ���� �Լ��� �̿��Ͽ� ���غ� ���" << endl;
	cout << "����Լ� : " << FibonacciRecursion(5) << endl;
	cout << "�ݺ��Լ� : " << FibonacciIterative(5) << endl;
	cout << "�迭�̿� : " << FibonacciArray(5) << endl;

	cout << endl;

	//���� �Ǻ���ġ �� �Է� �޾Ƽ� ȣ���غ���
	cout << "Fibonacci �� ���� ���� �Է� : ";
	cin >> n;

	int(*pRecur)(int) = &FibonacciRecursion;
	int(*pIter)(int) = &FibonacciIterative;
	int(*pArr)(int) = &FibonacciArray;

	cout << "����Լ� : " << (*pRecur)(n) << endl;
	cout << "�ݺ��Լ� : " << (*pIter)(n) << endl;
	cout << "�迭�̿� : " << (*pArr)(n) << endl;
}


int FibonacciRecursion(int f) {
	if (f <= 2)
		return 1;
	return FibonacciRecursion(f - 1) + FibonacciRecursion(f - 2);
}
int FibonacciIterative(int f) {
	int tmp = 0, result = 1;
	for (int i = 1; i <= f-1; i++) {
		int temp;
		temp = tmp;
		tmp = result;
		result = temp + result;
	}
	return result;
}
int FibonacciArray(int f) {
	int result;

	for (int i = 1; i <= f; i++) {
		if (i == 1 || i == 2) {
			FiboArr[i - 1] = 1;
		}
		else {
			FiboArr[i - 1] = FiboArr[i - 2] + FiboArr[i - 3];
		}
		result = FiboArr[i - 1];
	}

	return result;
}