#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
//sort, find(linear search), replace, reverse, binary_search
#include<functional>
//map,deque ���..
using namespace std;

int main() {
	vector<char> vec;
	vec.push_back('e');
	vec.push_back('b');
	vec.push_back('a');
	vec.push_back('d');
	vec.push_back('c');

	sort(vec.begin(), vec.end(), greater<char>()); //������������

	//����ǥ���� �Ἥ �������� ����
	sort(vec.begin(), vec.end(), [](int i, int k) { return i > k; });

	for (auto v : vec)
		cout << v;
	cout << endl;

}