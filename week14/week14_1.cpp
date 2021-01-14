/*
#include<iostream>
using namespace std;

//template<typename T,typename A,int MAX> //������ �� �� �ִ�
template<typename T>
class AutoArray {
public:
	AutoArray(T* ptr) {
		_ptr = ptr;
	}
	~AutoArray() {
		delete[] _ptr;
	}
	T& operator[] (int index) {
		return _ptr[index];
	}
private:
	T * _ptr;
};

int main() {
	AutoArray<int> arr(new int[100]); //������� �˷��ֱ�
	arr[0] = 100;
	AutoArray<float> arrf(new float[100]);
	arrf[99] = 2.71f;
	AutoArray<short> arrs(new short[100]);
	arrf[7] = 11;
	//���� ��� type�� �������� �ʾƵ� �Ǵ� ����
	//��ǻ�� ���������� �ش� Ŭ������ ��������� ��
}
*/

/*
#include<iostream>
using namespace std;

template<typename T>
T max(T a, T b) {
	return (a > b) ? a : b;
}

int main() {
	int i1 = 7, i2 = 4;
	int i3 = max(i1, i2);
	cout << i3 << endl;

	int d1 = 3.14, d2 = 2.71;
	double d3 = max(d1, d2);
	cout << d3 << endl;
}

//���ø��� ������ �ð��� �ڵ带 ������
//���ø��� ���α׷��� ����Ǵ� ������ �ƴ϶�,
//�ҽ��ڵ带 �������ϴ� ���߿� Ŭ������ �Լ��� ������
//���α׷��� ����Ǳ� ���� �̹� ��������ֱ� ������ ������ �������ų��� �ƴ�
//������ �������Ҷ� �������ϱ� ������ ������ �ð��� �� �� �ɸ� �� �ִ�

//���ø��Լ� ���Ǻκ��� ������Ͽ� �־���Ѵ�(�Ϲ��Լ�, ����Լ� ��� ����)
//�� �κ��� �ǹ��ϴ°� �Ϲ����� �Լ��� �����ϴ� �Ͱ��� �ٸ� �ǹ̸� ���������Ƿ�
//�Լ��� �����Ѵٱ⺸�� ��ǻ������ �Լ��� ����� ����� �˷��ִ� �����̴ϱ�
*/

//standart template library
//template�� ����Ͽ� ������� Ŭ������ �Լ����� ����
//���� 1.stl�� ǥ���� - > ��� ���󿡼��� ���� �� �� ���� (������ �ڵ�)
//�������� good
//2.������ ���� ���� �Ŵϱ� ȿ�����̰� ��������

/*
#include<iostream>
using namespace std;
#include<list>

int main() {
	list<int> ilist; //��ũ�帮��Ʈ
	for (auto i = 0; i < 10; i++) {
		ilist.push_back(i);
	}

	ilist.remove(5); //5�� ���� //list method


	//OLD SCHOOL
	list<int>::iterator it; //������ ���� ���
	//�ݺ��� //�����̳� ���� ���ҵ��� �ϳ��ϳ� ��ȸ�ϸ鼭 �������ϱ� ���� ���
	//�����̳�->�ټ��� ������ ��� ������ �ϴ� Ŭ����

	for (it = ilist.begin(); it != ilist.end(); it++)
		cout << *it << endl;
	//++�Ҷ����� ���� ������ �̵�


	//MODERN STYLE //auto�� oldschool ����� �ڵ����� ��������
	for (auto k = ilist.begin(); k != ilist.end(); k++)
		cout << *k << endl;

	auto i = ilist.begin();
	for (; i != ilist.end(); i++)
		cout << *i << endl;
	cout << typeid(i).name() << endl;
}
*/

//vector -> �����迭, �������� ������ ������ ������ �� �ִ� �迭
//vector�� remove ����
//�����̳ʸ��� �ణ�� �ٸ� ���� �ִ�

#include<iostream>
using namespace std;
#include<vector>
#include<list>

int main() {
	vector<int> ilist;

	for (auto i = 0; i < 10; i++) {
		ilist.push_back(i);
	}

	//ilist.remove(5);  //list���� method�� ����


	//OLD SCHOOL - > list�� iterator��� ��Ȯ�� ����������⶧���� ����
	//list<int>::iterator it;
	//for (it = ilist.begin(); it != ilist.end(); it++)
	//	cout << *it << endl;
	vector<int>::iterator it;
	//vector �����̳� ���� ��ü���� ����ų �� �ִ� iterator�� ����
	for (it = ilist.begin(); it != ilist.end(); it++)
		cout << *it << endl;


	//MODERN STYLE //auto�� oldschool ����� �ڵ����� ��������
	for (auto k = ilist.begin(); k != ilist.end(); k++)
		cout << *k << endl;
	//auto�� �˾Ƽ�ó�����ֱ� ������ ���� �ȳ�
}