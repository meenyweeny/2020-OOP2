#include<iostream>
using namespace std;

union QuizUnion {
	char i;
	char* p;
}uni;

int main() {
	uni.p = (char*)0x12345642;
	cout << uni.i << endl;
	return 0;
}

//char는 1byte이므로 하나당 4bit인 16진수의 뒤의 두자리는
//0x42고 이 값을 아스키 테이블에서 찾으면 알파벳 B이다.
//그런데 union에서 char는 크기가 같아 같은 메모리 공간을 사용하므로
//p에 할당해준 B라는 값을 i도 가지게 되어서
//uni.i를 출력했을 때 B라는 값이 나오게 된다.
//p의 주소값을 출력하고 싶으면 cout<<&(uni.p); 하면 된다.