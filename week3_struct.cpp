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
//s2�� ������� s�� ����,  s1�� ������� s�� ���� ��µȴ�.
//short�̹Ƿ� 2byte��
//16���� �� �ڸ��� 4bit �̹Ƿ�
//���� ���ڸ��� ������ �ȴ�.