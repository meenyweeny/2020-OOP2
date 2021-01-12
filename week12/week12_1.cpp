//예외객체 사용
//기본타입의 값 대신 객체를 예외로 던지기
//장점많음
//객체를 예외로 던진다는 것은 객체 안에 여러가지 다양한 값을 담을 수 있다는 것

#include<iostream>
#include"myexception.h"
using namespace std;

class DynamicArray {
public:
	DynamicArray(int arraySize);
	~DynamicArray();

	void SetAt(int index, int value);
	int GetAt(int index) const;
	int GetSize() const;

protected:
	int * arr;
	int size;
};

DynamicArray::DynamicArray(int arraySize) {
	arr = new int[arraySize];
	size = arraySize;
}

DynamicArray::~DynamicArray() {
	delete[] arr;
	arr = 0;
}

void DynamicArray::SetAt(int index, int value) {
	if (index<0 || index>=GetSize()) { //예외발생했을 때
		//throw "Out of Range!!"; //이걸 던지지 않고 객체 던질 것
		throw MyException(this,"Out of Range!!",index);
		//객체를 생성해서 예외를 던져주며 더 많은 정보를 보낼 수 있게 됐음
	}
	arr[index] = value;
}

int DynamicArray::GetAt(int index) const {
	return arr[index];
}

int DynamicArray::GetSize() const {
	return size;
}

void UseArray(DynamicArray & a,DynamicArray & b) {
	try {
		a.SetAt(3, 29);
		b.SetAt(3, 29);

		a.SetAt(9, -17);
		b.SetAt(9, -17); //예외발생 (인덱스 초과)

		a.SetAt(20, 7); //예외발생
		b.SetAt(20, 7); //예외발생
	}
	catch (MyException& e) { //발생한 예외를 받는 쪽
		//예외로 객체를 받는 catch 구문
		//catch 구문은 여러개 가능
		cout << &a << ", " << &b << endl;

		cout << e.sender << endl; //문제가 발생한 객체의 메모리 번지주소
		cout << e.description << endl;
		cout << e.info << endl;

	}
	catch (const char * e) {
		//예외로 문자열을 받는 catch 구문
		cout << "예외 : " << e << endl;

	}
}

int main() {
	DynamicArray arr1(10);
	DynamicArray arr2(7);
	UseArray(arr1,arr2);
}