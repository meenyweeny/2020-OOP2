/*
#include<iostream>
using namespace std;

//template<typename T,typename A,int MAX> //여러개 올 수 있다
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
	AutoArray<int> arr(new int[100]); //어떤형인지 알려주기
	arr[0] = 100;
	AutoArray<float> arrf(new float[100]);
	arrf[99] = 2.71f;
	AutoArray<short> arrs(new short[100]);
	arrf[7] = 11;
	//각각 모든 type을 변경하지 않아도 되는 편리함
	//컴퓨터 내부적으로 해당 클래스가 만들어지는 것
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

//템플릿은 컴파일 시간에 코드를 만들어낸다
//템플릿은 프로그램이 실행되는 도중이 아니라,
//소스코드를 컴파일하는 도중에 클래스나 함수를 만들어낸다
//프로그램이 실행되기 전에 이미 만들어져있기 때문에 성능이 느려지거나는 아님
//하지만 컴파일할때 만들어야하기 때문에 컴파일 시간이 좀 더 걸릴 순 있다

//템플릿함수 정의부분은 헤더파일에 넣어야한다(일반함수, 멤버함수 모두 포함)
//이 부분이 의미하는게 일반적인 함수를 정의하는 것과는 다른 의미를 갖고있으므로
//함수를 정의한다기보단 컴퓨터한테 함수를 만드는 방법을 알려주는 느낌이니까
*/

//standart template library
//template을 사용하여 만들어진 클래스나 함수들의 모임
//장점 1.stl은 표준임 - > 어느 나라에서도 같이 쓸 수 있음 (동일한 코드)
//가독성이 good
//2.검증을 많이 받은 거니까 효율적이고 안정적임

/*
#include<iostream>
using namespace std;
#include<list>

int main() {
	list<int> ilist; //링크드리스트
	for (auto i = 0; i < 10; i++) {
		ilist.push_back(i);
	}

	ilist.remove(5); //5를 지움 //list method


	//OLD SCHOOL
	list<int>::iterator it; //포인터 역할 비슷
	//반복자 //컨테이너 안의 원소들을 하나하나 순회하면서 포인팅하기 위해 사용
	//컨테이너->다수의 정보를 담는 역할을 하는 클래스

	for (it = ilist.begin(); it != ilist.end(); it++)
		cout << *it << endl;
	//++할때마다 원소 단위로 이동


	//MODERN STYLE //auto가 oldschool 방식을 자동으로 구현해줌
	for (auto k = ilist.begin(); k != ilist.end(); k++)
		cout << *k << endl;

	auto i = ilist.begin();
	for (; i != ilist.end(); i++)
		cout << *i << endl;
	cout << typeid(i).name() << endl;
}
*/

//vector -> 동적배열, 동적으로 원소의 개수를 조절할 수 있는 배열
//vector는 remove 없음
//컨테이너마다 약간씩 다른 점이 있다

#include<iostream>
using namespace std;
#include<vector>
#include<list>

int main() {
	vector<int> ilist;

	for (auto i = 0; i < 10; i++) {
		ilist.push_back(i);
	}

	//ilist.remove(5);  //list전용 method라 오류


	//OLD SCHOOL - > list의 iterator라고 정확히 지정을해줬기때문에 오류
	//list<int>::iterator it;
	//for (it = ilist.begin(); it != ilist.end(); it++)
	//	cout << *it << endl;
	vector<int>::iterator it;
	//vector 컨테이너 안의 개체들을 가리킬 수 있는 iterator를 생성
	for (it = ilist.begin(); it != ilist.end(); it++)
		cout << *it << endl;


	//MODERN STYLE //auto가 oldschool 방식을 자동으로 구현해줌
	for (auto k = ilist.begin(); k != ilist.end(); k++)
		cout << *k << endl;
	//auto로 알아서처리해주기 때문에 오류 안남
}