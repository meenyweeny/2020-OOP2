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
	
	void SetAt(int index, int value) {
		if (index<0 || index>GetSize())
			throw "Out of Range!!";
		arr[index] = value;
	}

	int GetAt(int index) const { return arr[index]; }
	int GetSize() const { return size; }

protected:
	int * arr;
	int size;
};

void useArray(DynamicArray & a) {
	//���۷����� ����
	//���縦 ���� �����ϱ� ������ �޸� ������ �ʿ����� �ʰ�
	//�����ϴµ� �ɸ��� �ð��� save �Ҽ� �ִ�

	try {
		a.SetAt(3, 29);
		a.SetAt(9, -17);
		a.SetAt(20, 7); //���� �߻�
	}
	catch (const char * e) { //���� ���ڿ��� �߻��ϴϱ� �Ű����� ���ڿ���
		//����ó����
		cout << "���� : " << e << endl;
	}
}
int main() {
	DynamicArray arr(10);
	useArray(arr);
}