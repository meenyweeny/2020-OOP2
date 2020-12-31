#include<iostream>
using namespace std;
#define MAX 10000

//재귀,반복문,배열 세가지 방법
int FibonacciRecursion(int);
int FibonacciIterative(int);
int FibonacciArray(int);
int FiboArr[MAX]; //FibonacciArray를 위한 배열

int n;

int main() {

	//그냥 파라미터 5로 주고 호출해보기
	cout << "Fibonacci 5 수를 함수를 이용하여 구해본 결과" << endl;
	cout << "재귀함수 : " << FibonacciRecursion(5) << endl;
	cout << "반복함수 : " << FibonacciIterative(5) << endl;
	cout << "배열이용 : " << FibonacciArray(5) << endl;

	cout << endl;

	//구할 피보나치 수 입력 받아서 호출해보기
	cout << "Fibonacci 수 구할 정수 입력 : ";
	cin >> n;

	int(*pRecur)(int) = &FibonacciRecursion;
	int(*pIter)(int) = &FibonacciIterative;
	int(*pArr)(int) = &FibonacciArray;

	cout << "재귀함수 : " << (*pRecur)(n) << endl;
	cout << "반복함수 : " << (*pIter)(n) << endl;
	cout << "배열이용 : " << (*pArr)(n) << endl;
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