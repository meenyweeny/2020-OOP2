//������ �ȿ��� ���� �� �ִ� ���ܿ� ���� ó��
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
	//������->����Ÿ���� ����->�̰� �˸����ִ� ����� ���� ����
	//������ �ȿ��� �߻��ϴ� ���ܴ� �׷��� ������ �ȿ��� ó���ؾ���
	arr = new int[arraySize];
	size = arraySize;

	throw MyException(this, "constructor inside exception", 100);
}

DynamicArray::~DynamicArray() {
	cout << "�Ҹ��� ����!" << endl;
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
		//�Ҹ��ڿ��� �߻��� ���ܸ� main���� ��Ƽ� �Ҹ��ڰ� �������� �ʾ���

		//c++���� �����ڰ� �ùٸ��� ���� ��쿡�� ��ü�� �����ߴٰ� �ϴ� ��Ģ�� ����
		//�����ڿ��� ���ܰ� �߻��� ����� ���������� ������� ���� ���̰�
		//��ü�� ��������� ���� ��-> ��ü�� ��������� �ʾ����� �Ҹ��ڵ� ������ �ʿ䰡 ����
	}
}
*/


//�׷� delete�� �ؾ��ϴµ� ��¼��? -> ������ ���ʿ��� ó�����־����

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
	catch (...) { //������ ���ʿ��� ���� ���ܸ� ������ ���ʿ��� �ذ���
		cout << "������ ���� catch ����!!!" << endl;
		delete[] arr; //�޸� ����
		throw; //�����ڴ� ����Ÿ���� ���� ������, ���� ���� �ٽ� ���� (�ܺο� �˸��� ���ؼ�)
		//�׷� �ܺ��� main �Լ����� catch�Ұ�
	}
}

DynamicArray::~DynamicArray() { //��ü�� ���������� �������� �� ����
	cout << "�Ҹ��� ����!" << endl;
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


//�Ҹ��ڿ��� ���ܰ� �������� ���
//�� ������ �ٽ� ���� throw�ϸ� �ȵ�

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
		cout << "������ ���� catch ����!!!" << endl;
		delete[] arr;
		throw;
	}
}

DynamicArray::~DynamicArray() {
	try {
		cout << "�Ҹ��� ����!" << endl;
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