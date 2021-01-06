#include<iostream>
using namespace std;

//구조체
struct StudentInfo {
	int id; //0으로 초기화 되어있음
	float grade; //0으로 초기화 되어있음
	char bloodType; //null로 초기화 되어있음
}s3 = { 20201236,4.4f,'O' },s4;
//초기화는 나중에 해도 됨 (기본값으로 초기화가 되어있어서 안해도 오류는 안남)

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
	//s2의 정보가 s4로 완벽히 복사됨
	cout << s4.bloodType << endl;

	//s2,s4는 서로 다른 메모리 공간을 갖기 때문에
	//둘 중 하나 바꾼다고 둘 다 바뀌는거 아님

	s4.bloodType = 'B';
	cout << s4.bloodType << endl;
	cout << s2.bloodType << endl;

	//========================================

	//범위기반 for문 (Modern)
	/*
	char letters[] = "Hell";
	void *ps;
	ps = letters;

	//old ver
	for (int i = 0; i < sizeof(letters) / sizeof(char); i++)
		cout << *((char*)ps + i);

	//ranged based for loop
	for (auto letter : letters) //얘도 5번 돔
		cout << letter;

	for (int i : {1, 3, 5, 7, -9})
		cout << i;
	*/

	//===========================================

	//2014년 이전 버전 (10,16,8진수 입력 가능)
	int q = 10;
	cout << q << endl; //10진수 10
	int w = 0xA; //16진수 A (=10진수 10)
	cout << w << endl;
	int e = 012; //8진수는 앞에 0붙임 (=10진수 10)
	cout << e << endl;

	//모두 10이라 나옴

	//바이너리 리터럴 binary literals
	//c++ 14 이후에 지원
	int r = 0b1010;
	cout << r << endl; //얘도 10이라 나옴
}