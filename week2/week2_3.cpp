#include<iostream>
using namespace std;

//����ü
struct StudentInfo {
	int id; //0���� �ʱ�ȭ �Ǿ�����
	float grade; //0���� �ʱ�ȭ �Ǿ�����
	char bloodType; //null�� �ʱ�ȭ �Ǿ�����
}s3 = { 20201236,4.4f,'O' },s4;
//�ʱ�ȭ�� ���߿� �ص� �� (�⺻������ �ʱ�ȭ�� �Ǿ��־ ���ص� ������ �ȳ�)

int main() {
	StudentInfo s1 = { 20201234,3.5f,'O' };
	StudentInfo s2 = { 20201235,3.7f,'A' };
	cout << s2.grade << endl;
	cout << s1.id << endl;
	cout << s3.bloodType << endl;

	s4.bloodType = 'B';
	s4.id = 20201237;
	s4.grade = 2.9f;

	s4 = s2;
	//s2�� ������ s4�� �Ϻ��� �����
	cout << s4.bloodType << endl;

	//s2,s4�� ���� �ٸ� �޸� ������ ���� ������
	//�� �� �ϳ� �ٲ۴ٰ� �� �� �ٲ�°� �ƴ�

	s4.bloodType = 'B';
	cout << s4.bloodType << endl;
	cout << s2.bloodType << endl;

	//========================================

	//������� for�� (Modern)
	/*
	char letters[] = "Hell";
	void *ps;
	ps = letters;

	//old ver
	for (int i = 0; i < sizeof(letters) / sizeof(char); i++)
		cout << *((char*)ps + i);

	//ranged based for loop
	for (auto letter : letters) //�굵 5�� ��
		cout << letter;

	for (int i : {1, 3, 5, 7, -9})
		cout << i;
	*/

	//===========================================

	//2014�� ���� ���� (10,16,8���� �Է� ����)
	int q = 10;
	cout << q << endl; //10���� 10
	int w = 0xA; //16���� A (=10���� 10)
	cout << w << endl;
	int e = 012; //8������ �տ� 0���� (=10���� 10)
	cout << e << endl;

	//��� 10�̶� ����

	//���̳ʸ� ���ͷ� binary literals
	//c++ 14 ���Ŀ� ����
	int r = 0b1010;
	cout << r << endl; //�굵 10�̶� ����
}