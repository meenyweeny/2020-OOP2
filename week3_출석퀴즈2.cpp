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

//char�� 1byte�̹Ƿ� �ϳ��� 4bit�� 16������ ���� ���ڸ���
//0x42�� �� ���� �ƽ�Ű ���̺��� ã���� ���ĺ� B�̴�.
//�׷��� union���� char�� ũ�Ⱑ ���� ���� �޸� ������ ����ϹǷ�
//p�� �Ҵ����� B��� ���� i�� ������ �Ǿ
//uni.i�� ������� �� B��� ���� ������ �ȴ�.
//p�� �ּҰ��� ����ϰ� ������ cout<<&(uni.p); �ϸ� �ȴ�.