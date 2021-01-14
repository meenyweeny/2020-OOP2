//문제점들
/*
1.AutoArray클래스의 연산자오버로딩 멤버함수의 인수는
템플릿 타입으로 주면 안된다, index값은 무조건 int여야하므로
int로 바꿔야한다.
2.main함수에서 int형으로 만든 AutoArray에서,
값을 초기화도 안해주고 할당도 안해줬던 값을 출력하니까
더미값이 출력된다.
이를 해결하려면, 초기화되지 않은 변수에 대한 접근을 하지 말거나
생성시에 size도 인수로 받아 생성자에서 초기화를 해주는 방법이 있다.
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