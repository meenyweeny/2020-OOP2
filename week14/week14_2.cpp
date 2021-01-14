/*
#include<iostream>
#include<list> //��ũ�� ����Ʈ (����,������ ����)
#include<vector> //���� �迭 (�˻� ���ֿ� ����)
#include<algorithm> //����, �˻� ��� ���� �˰����� �����س��� �Լ���
using namespace std;
//stl ����� ���α׷��� ����,�������� �ð��� good

int main() {
	vector<char> vec;
	vec.push_back('e');
	vec.push_back('a');
	vec.push_back('c');
	vec.push_back('b');
	vec.push_back('d');


	//MODERN
	for (auto i = vec.begin(); i != vec.end(); i++)
		cout << *i;

	cout << endl;

	sort(vec.begin(), vec.end());
	//end�� �� ���� ���� +1 ��ġ�� �ּ�

	for (auto i = vec.begin(); i != vec.end(); i++)
		cout << *i;

	cout << endl;

	char arr[5] = { 'e','a','c','b','d' };
	//�Ϲ����� �迭�� stl �����̳ʿ� ������ �������� �ٷ� �� �ִ�
	//stl�� ������ ��� �����̳ʿ� ������ ó���ϴ� �˰����� ���� �и��Ǿ�����
	//��� �����̳ʿ��� �� �ٷ� �� �ְ� ���������� �������

	sort(arr, arr + 5);
	//sort�� �ι�° �μ��� ������ +1�� ���� �����

	for (char * p = arr; p != arr + 5; p++)
		cout << *p;

	cout << endl;

	for (auto p = arr; p != arr + 5; p++) {
		cout << *p << " ";
		cout << typeid(p).name() << endl;
	}

	cout << endl;

	//OLD SCHOOL - > iterator �ʿ�
	vector<char>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
		cout << *it; //������ �����ε��� �� �κ�
	//iterator�� ������ó�� �����ϰ� * ��ȣ�� �����ε���

	cout << endl;

	//�� ������ MODERN (c++ 11�� range based for loop)
	for (auto item : vec)
		cout << item;

	cout << endl;
}
*/

#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

bool myfunc(int i, int k) { return i > k; }
//'e'>'b' - > true

struct myclass {
	bool operator()(int i, int j) { return i > j; }
}myobject;

class my {
public:
	bool operator()(int i, int j) { return i > j; }
}my1;

int main() {
	vector<char> vec;
	vec.push_back('e');
	vec.push_back('b');
	vec.push_back('a');
	vec.push_back('d');
	vec.push_back('c');

	sort(vec.begin(), vec.end()); //��������
	sort(vec.begin(), vec.end(), myfunc); //��������(�Լ��� ����)
	sort(vec.begin(), vec.end(), myobject); //��������(����ü������ ����)
	sort(vec.begin(), vec.end(), my1); //��������(Ŭ������ ����)

	for (auto v : vec)
		cout << v;
	cout << endl;

}