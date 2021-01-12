//���ܰ�ü ���
//�⺻Ÿ���� �� ��� ��ü�� ���ܷ� ������
//��������
//��ü�� ���ܷ� �����ٴ� ���� ��ü �ȿ� �������� �پ��� ���� ���� �� �ִٴ� ��

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
	if (index<0 || index>=GetSize()) { //���ܹ߻����� ��
		//throw "Out of Range!!"; //�̰� ������ �ʰ� ��ü ���� ��
		throw MyException(this,"Out of Range!!",index);
		//��ü�� �����ؼ� ���ܸ� �����ָ� �� ���� ������ ���� �� �ְ� ����
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
		b.SetAt(9, -17); //���ܹ߻� (�ε��� �ʰ�)

		a.SetAt(20, 7); //���ܹ߻�
		b.SetAt(20, 7); //���ܹ߻�
	}
	catch (MyException& e) { //�߻��� ���ܸ� �޴� ��
		//���ܷ� ��ü�� �޴� catch ����
		//catch ������ ������ ����
		cout << &a << ", " << &b << endl;

		cout << e.sender << endl; //������ �߻��� ��ü�� �޸� �����ּ�
		cout << e.description << endl;
		cout << e.info << endl;

	}
	catch (const char * e) {
		//���ܷ� ���ڿ��� �޴� catch ����
		cout << "���� : " << e << endl;

	}
}

int main() {
	DynamicArray arr1(10);
	DynamicArray arr2(7);
	UseArray(arr1,arr2);
}