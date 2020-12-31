#include<iostream>
using namespace std;

struct QuizStruct {
	short s;
	QuizStruct * p;
}s1,s2;

int main() {
	s1.s = 0x17171771;
	s1.p = &s2;
	s2.s = 0x486;
	s2.p = &s1;

	cout << hex;
	cout << (*s1.p).s << endl;
	cout << s2.p->s << endl;
}

//486,1771
//s2의 멤버변수 s의 값과,  s1의 멤버변수 s의 값이 출력된다.
//short이므로 2byte고
//16진수 한 자리가 4bit 이므로
//뒤의 네자리만 나오게 된다.