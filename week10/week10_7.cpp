//����ó��
//����->�츮�� �翬�ϴٰ� ������ ��Ȳ�� ������ �� ��
//��� ��Ȳ�� �߻�?
//1.��ǻ�Ϳ� ��� ������ �޸𸮰� ������ ���
//2.���������ġ�� ���� �뷮�� ������ ���
//3.����ڰ� �Է��� ���� ���� ���� �Է��ϴ� ��쳪 �������� �ʴ� ������ �̸��� �Է��ϴ� ���

//���׳� �������� �������� �Ǽ��� �Ͼ�� ���� ���ܴ� �ٸ�
//���ܴ� ���α׷��� �߸�¥�� ����°� �ƴ϶�
//���α׷� ������ ���ο��� �߻�
//�̸� �����ϰ� ��ó�ϴ� ó���� �߿���

#include<iostream>
using namespace std;

class DynamicArray {
public:
	DynamicArray(int arraySize) {
		arr = new int[arraySize];
		size = arraySize;
	}
	~DynamicArray() {}
	/*
	void SetAt(int index, int value) {
		arr[index] = value; //���⼭ ���� �߻� ����
		//�߸��� �ε����� �޾��� ��
	}
	*/
	bool SetAt(int index, int value) {
		if (index<0 || index > GetSize())
			return false;
		arr[index] = value;
		return true;
	}

	int GetAt(int index) const { return arr[index]; }
	int GetSize() const { return size; }

protected:
	int * arr;
	int size;
};

int main() {
	/*
	DynamicArray arr(10);
	for (auto i = 0; i < 11; i++) 
		arr.SetAt(i, (i + 1) * 10); //i�� ���� ��� ���� �ްԵ�


	cout << "Size of arr = " << arr.GetSize() << "\n";


	for (auto i = 9; i >= 0; i--)
		cout << "arr[" << i << "] = " << arr.GetAt(i) << "\n";
		*/

	//=================================================
	/*
	//SetAt�� bool Ÿ������ �ٲ㼭 ���� �ذ��غ���
	//�̷� ���� �ذ����� � �������� �����ִ��� ���캸��

	DynamicArray arr2(10);
	bool b;
	b = arr2.SetAt(20, 0);
	if (!b)
		cout << "�ε��� ���� �߻�!" << endl;

	//������ - > �Ź� ������ ������ �������� �޴� �ڵ带 �޾ƾ� ��
	//1.�Ź� ��ȯ���� ���ؾ���
	//2.�Լ��� �̹� �ٸ� �뵵�� ��ȯ���� ����ϰ� ����
	//������ �ҽ��ڵ�� ����ó���ڵ尡 �ھ��Ѽ� �������ϰ�
	//���� ��ȯ������ ���� �뵵�� ����� ���� ���� �Ǳ⵵ ��
	*/

	//->�̷��� ������ ������ ����ó���� ���ؼ� �ذ��� �� ����


}