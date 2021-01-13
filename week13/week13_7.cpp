//c++의 template
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
	int & operator[] (int index) { //연산자 오버로딩
		return _ptr[index];
		//반환값이 그냥 int가 아니라 int 레퍼런스임
		//이렇게 안하면 사용시에 문제 생길 수 있음
		//레퍼런스로 받아야지만 참조해서 수정할 수 있음
	}

private:
	int * _ptr;
};


int main() {
	AutoArray arr(new int[100]);
	//생성하고 소멸자쪽에서 자동으로 해제해주니까
	//main에서 delete 따로 신경 안써도 괜찮음
	arr[0] = 100;
	//넘어온 인덱스 값으로 해당 동적할당된 공간에 접근해서 값을 넣어주게

	
	//근데 자료의 타입을 전부 double로 바꾸고 싶다면?
	//문제가 생김 다 바꿔야하니까
	//그래서 이것을 template으로 만들어두면
	//타입을 신경안쓰고 자동으로 할 수 있게 된다
}