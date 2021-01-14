//��������
/*
1.AutoArrayŬ������ �����ڿ����ε� ����Լ��� �μ���
���ø� Ÿ������ �ָ� �ȵȴ�, index���� ������ int�����ϹǷ�
int�� �ٲ���Ѵ�.
2.main�Լ����� int������ ���� AutoArray����,
���� �ʱ�ȭ�� �����ְ� �Ҵ絵 ������� ���� ����ϴϱ�
���̰��� ��µȴ�.
�̸� �ذ��Ϸ���, �ʱ�ȭ���� ���� ������ ���� ������ ���� ���ų�
�����ÿ� size�� �μ��� �޾� �����ڿ��� �ʱ�ȭ�� ���ִ� ����� �ִ�.
*/

#include<iostream>
using namespace std;

template<typename T>
class AutoArray {
public:
	AutoArray(T* ptr,int size) {
		_ptr = ptr;
		for (int i = 0; i < size; i++)
			_ptr[i] = (T)(0);
	}
	~AutoArray() {
		delete[] _ptr;
	}
	T& operator[](int index) {
		return _ptr[index];
	}
private:
	T * _ptr;
};

int main() {
	AutoArray<int> arri(new int[100],100);
	arri[0] = 100;
	cout << arri[1] << endl;

	AutoArray<short> arrs(new short[10],10);
	arrs[7] = 11;
	cout << arrs[7] << endl;
}