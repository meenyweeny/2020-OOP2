//�����Ҵ�
/*
#include<iostream>
using namespace std;

char * ReverseString(const char * src, int len) { 
	char * rev = new char[len + 1];
	//+1�ؼ� ���� ���� - > ���� NULL ���� ������ ���ؼ�
	for (auto i = 0; i < len; ++i) {
		rev[i] = src[len - i - 1];
	}
	rev[len] = NULL;
	//���� NULL ó�� '\0'
	return rev;
	//���� ������ heap ������ �� �չ����� �ּҸ� return
}

int main() {

	char orig[] = "Inha"; //a�ڿ� null���� ������ ��
	char * copy = ReverseString(orig, 4);
	//�Լ��� ù��° ���ڷ� �޸� ������ ������
	//�Ķ���� ù��°�� const�ϱ� �б� ��������
	//const char * src�� orig�� �� �չ�° ��, I
	//�Ķ���� len���δ� 4�� copy ������
	//src�δ� �׳� �ּҸ� ���޵Ǵ� ��

	//copy�� ReverseString�� rev�� ù��° ĭ�� �ּҰ��� �����������鼭 �������� �ϰԵȴ�

	cout << orig << endl;
	cout << copy << endl;
	delete[] copy; //�����Ҵ� �� �κ� ����
	copy = NULL; //���� copy�� ����ִ� rev�� ù ĭ�� �ּҸ� 0���� ���� �ƿ� ������ ���� ȿ��

}
*/


//���ڿ��� ���̿� ���� ����
#include<iostream>
#include<cstring>
#pragma warning (disable : 4996)
using namespace std;

int main() {
	//���� ���ڿ� ����
	char src[] = "Inha Univ";
	int len = strlen(src);
	cout << len << endl; //->9

	//���� ���ڿ� ����
	char * dest = new char[len + 1]; //null���ڸ� ����ؼ� +1
	strcpy(dest, src);
	cout << src << endl;
	cout << dest << endl;


	delete[] dest;
	dest = NULL; //���� ��ü�� ����Ű�� �ּҵ� ������ ����
}