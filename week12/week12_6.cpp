//생성자 안에서 생길 수 있는 예외에 대한 처리
/*
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
	//생성자->리턴타입이 없음->이걸 알릴수있는 방법이 딱히 없음
	//생성자 안에서 발생하는 예외는 그래서 생성자 안에서 처리해야함
	arr = new int[arraySize];
	size = arraySize;

	throw MyException(this, "constructor inside exception", 100);
}

DynamicArray::~DynamicArray() {
	cout << "소멸자 동작!" << endl;
	delete[] arr;
	arr = 0;
}

void DynamicArray::SetAt(int index, int value) {
	if (index<0 || index >= GetSize()) {
		throw MyException(this, "Out of Range!!", index);
	}
	arr[index] = value;
}

int DynamicArray::GetAt(int index) const {
	return arr[index];
}

int DynamicArray::GetSize() const {
	return size;
}

int main() {
	try {
		DynamicArray arr1(100);
	} catch (MyException& e) {
		cout << e.description << endl;
		//소멸자에서 발생한 예외를 main에서 잡아서 소멸자가 동작하지 않았음

		//c++에는 생성자가 올바르게 끝난 경우에만 객체를 생성했다고 하는 규칙이 있음
		//생성자에서 예외가 발생한 경우라면 정상적으로 종료되지 않은 것이고
		//객체도 만들어지지 않은 것-> 객체가 만들어지지 않았으니 소멸자도 동작할 필요가 없음
	}
}
*/


//그럼 delete를 해야하는데 어쩌나? -> 생성자 안쪽에서 처리해주어야함

/*
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
	try {
		arr = new int[arraySize];
		size = arraySize;

		throw MyException(this, "constructor inside exception", 100);
	}
	catch (...) { //생성자 안쪽에서 생긴 예외를 생성자 안쪽에서 해결함
		cout << "생성자 안쪽 catch 구문!!!" << endl;
		delete[] arr; //메모리 해제
		throw; //생성자는 리턴타입이 없기 때문에, 받은 예외 다시 던짐 (외부에 알리기 위해서)
		//그럼 외부의 main 함수에서 catch할것
	}
}

DynamicArray::~DynamicArray() { //객체가 정상적으로 생성됐을 때 실행
	cout << "소멸자 동작!" << endl;
	delete[] arr;
	arr = 0;
}

void DynamicArray::SetAt(int index, int value) {
	if (index<0 || index >= GetSize()) {
		throw MyException(this, "Out of Range!!", index);
	}
	arr[index] = value;
}

int DynamicArray::GetAt(int index) const {
	return arr[index];
}

int DynamicArray::GetSize() const {
	return size;
}

int main() {
	try {
		DynamicArray arr1(100);
	}
	catch (MyException& e) {
		cout << e.description << endl;
	}
}
*/


//소멸자에서 예외가 던져지는 경우
//얜 밖으로 다시 예외 throw하면 안됨

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
	try {
		arr = new int[arraySize];
		size = arraySize;

		throw MyException(this, "constructor inside exception", 100);
	}
	catch (...) {
		cout << "생성자 안쪽 catch 구문!!!" << endl;
		delete[] arr;
		throw;
	}
}

DynamicArray::~DynamicArray() {
	try {
		cout << "소멸자 동작!" << endl;
		delete[] arr;
		arr = 0;
	} catch (...) {

	}
}

void DynamicArray::SetAt(int index, int value) {
	if (index<0 || index >= GetSize()) {
		throw MyException(this, "Out of Range!!", index);
	}
	arr[index] = value;
}

int DynamicArray::GetAt(int index) const {
	return arr[index];
}

int DynamicArray::GetSize() const {
	return size;
}

int main() {
	try {
		DynamicArray arr1(100);
	}
	catch (MyException& e) {
		cout << e.description << endl;
	}
}