//함수(Function)
#include<iostream>
#include<string>
using namespace std;

/*
void Hello() {
	cout << "Hi" << endl;
}

int main() {
	Hello(); //함수 호출
}
*/

/*
//main에서 Hello()를 찾을 수 없음
int main() {
	Hello();
}
void Hello() {
	cout << "Hi" << endl;
}
*/

//그래서 프로토타입을 작성
//이런 방식이 좋을 수 있음 (함수에 대한 설명 달아놓기 좋으니까
/*
void Hello(); //인사하는 함수

int main() {
	Hello();
}

void Hello() {
	cout << "Hi" << endl;
}
*/

//매개변수 전달
/*
void Hello(int); //인사하는 함수

int main() {
	Hello(5);
}

void Hello(int n) {
	cout << "Hi " << n << endl;
}
*/

//팩토리얼을 구현하는 함수 디자인

//팩토리얼 함수 //재귀,반복 등 여러가지 방법 가능

void Hello() {
	cout << "Hi" << endl;
}

int Factorial(int); //반복문 이용하여
int FactorialRecursion(int); //재귀 이용하여

int Factorial(int f) { //반복문 이용하여
	int result = 1;
	for (int i = 1; i <= f; i++)
		result *= i;

	return result;
}

int FactorialRecursion(int n) { //재귀 이용하여
	//반복문에 비해 퍼포먼스가 떨어짐 overhead가 굉장히 심함
	//가독성은 good

	//if n=4라면
	//f=3
	//f=2
	if (n == 1)
		return 1;
	return n * FactorialRecursion(n - 1);
	//4*FactorialRecursion(3); -> 4*6
	//3*FactorialRecursion(2); -> 3* 2
	//2*FactorialRecursion(1); ->2
	//또 다시 그전으로 돌아감
}

int main() {
	cout << Factorial(5) << endl; //반복문 이용하여
	cout << FactorialRecursion(5) << endl; //재귀함수 이용하여

	int in;
	cin >> in;
	cout << Factorial(in) << endl;
	cout << FactorialRecursion(in) << endl;

	//함수포인터 활용
	//함수의 구조를 참고해서 만들면 됨
	int(*pFact)(int); //가리키려는 함수와 타입이 매칭되게 선언해야함
	void(*pHi)(); //void 포인터

	pFact = &Factorial; //함수포인터는 함수의 주소를 받음
	//변수 포인터가 변수의 주소를 받듯이
	pHi = &Hello;

	//pFact = &Hello; //타입 안맞으니까 오류

	cout << (*pFact)(in) << endl;
	(*pHi)();
}