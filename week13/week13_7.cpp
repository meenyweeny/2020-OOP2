//c++�� template
#include<iostream>
using namespace std;

class AutoArray {
public:
	AutoArray(int * ptr) {
		_ptr = ptr;
	}
	~AutoArray() {
		delete[] _ptr;
	}
	int & operator[] (int index) { //������ �����ε�
		return _ptr[index];
		//��ȯ���� �׳� int�� �ƴ϶� int ���۷�����
		//�̷��� ���ϸ� ���ÿ� ���� ���� �� ����
		//���۷����� �޾ƾ����� �����ؼ� ������ �� ����
	}

private:
	int * _ptr;
};


int main() {
	AutoArray arr(new int[100]);
	//�����ϰ� �Ҹ����ʿ��� �ڵ����� �������ִϱ�
	//main���� delete ���� �Ű� �Ƚᵵ ������
	arr[0] = 100;
	//�Ѿ�� �ε��� ������ �ش� �����Ҵ�� ������ �����ؼ� ���� �־��ְ�

	
	//�ٵ� �ڷ��� Ÿ���� ���� double�� �ٲٰ� �ʹٸ�?
	//������ ���� �� �ٲ���ϴϱ�
	//�׷��� �̰��� template���� �����θ�
	//Ÿ���� �Ű�Ⱦ��� �ڵ����� �� �� �ְ� �ȴ�
}