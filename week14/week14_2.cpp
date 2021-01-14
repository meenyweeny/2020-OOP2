/*
#include<iostream>
#include<list> //링크드 리스트 (삽입,삭제에 강점)
#include<vector> //동적 배열 (검색 위주에 강점)
#include<algorithm> //정렬, 검색 등과 같은 알고리즘을 구현해놓은 함수들
using namespace std;
//stl 사용은 프로그램의 개발,유지보수 시간이 good

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
	//end는 맨 끝의 원소 +1 위치의 주소

	for (auto i = vec.begin(); i != vec.end(); i++)
		cout << *i;

	cout << endl;

	char arr[5] = { 'e','a','c','b','d' };
	//일반적인 배열도 stl 컨테이너와 유사한 형식으로 다룰 수 있다
	//stl은 정보를 담는 컨테이너와 정보를 처리하는 알고리즘이 서로 분리되어있음
	//모든 컨테이너에서 잘 다룰 수 있게 범용적으로 만들어짐

	sort(arr, arr + 5);
	//sort의 두번째 인수는 끝에서 +1된 것을 줘야함

	for (char * p = arr; p != arr + 5; p++)
		cout << *p;

	cout << endl;

	for (auto p = arr; p != arr + 5; p++) {
		cout << *p << " ";
		cout << typeid(p).name() << endl;
	}

	cout << endl;

	//OLD SCHOOL - > iterator 필요
	vector<char>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
		cout << *it; //연산자 오버로딩이 된 부분
	//iterator를 포인터처럼 동작하게 * 기호로 오버로딩함

	cout << endl;

	//더 개선된 MODERN (c++ 11의 range based for loop)
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

	sort(vec.begin(), vec.end()); //오름차순
	sort(vec.begin(), vec.end(), myfunc); //내림차순(함수를 통해)
	sort(vec.begin(), vec.end(), myobject); //내림차순(구조체변수를 통해)
	sort(vec.begin(), vec.end(), my1); //내림차순(클래스를 통해)

	for (auto v : vec)
		cout << v;
	cout << endl;

}