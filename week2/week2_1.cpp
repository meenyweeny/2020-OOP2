#include<iostream>
using namespace std;

int main() {

	//자료형/음수표현방식(2의 보수법)/자료형size

	/*
	int k = 5;
	//int 4byte
	//양수만 고려했을 때 0~2^32-1까지
	//32bit

	const int i = 5;
	//중간에 값을 바꿀 수 없다.
	//i=7; //수정불가라 error

	short s = 20;
	//16bit
	//2byte
	//0~2^16-1의 unsigned 범위
	//0~65535

	short o = 65535;
	cout << o << endl;
	//-1이 나온다
	//왜냐면 unsigned로 선언하지 않았기 때문
	//unsigned가 아니라면 -2^15~2^15-1의 범위를 가짐
	//65535는 short 의 양수범위를 넘어섬

	unsigned short l = 65535;
	cout << l << endl;
	//얜 잘 나옴

	//unsigned일 때는
	//1111 1111 1111 1111
	//이게 꽉 찬거고

	//signed일 때는
	//1111 1111 1111 1111 에서 맨 앞의 1이 부호비트로 동작해서
	//음수 처리하는 방식(2의 보수법) 으로 처리가 된 것
	

	unsigned short u = 65536;
	//1111 1111 1111 1111
	//+                 1
	//----------------------
  //1 0000 0000 0000 0000
	//컴퓨터가 short 자료형 16bit이므로
	//뒤의 16자리만 읽게 된다
	//그래서 0으로 출력이 된다
	cout << u << endl;
	*/

	//==============================================================



	//배열
	/*
	int arr[4];
	arr[0] = -9;
	arr[3] = 30000;
	cout << arr[3] << endl;
	//cout << arr[2] << endl; //값 지정안해줬으니까 더미값이 나옴

	int arr2[4] = { 0 }; //모두 0으로 초기화
	for (auto i : arr2)
		cout << arr2[i] << endl;
	*/

	/*
	int arr3[4] = { -9,0,0,30000 }; //선언과 동시에 초기화
	for (auto i : arr3)
		cout << i << endl;

	//포인터로 나오게 해보기
	int * p = &arr3[0]; //arr3 제일 앞칸의 주소가 그 어레이의 주소
	for (int i=0; i<4; i++)
		cout << p << endl; //arr3[0]의 주소만 네번찍힘
	for (int i=0; i<4; i++)
		cout << p + i << endl;
	//운영체제가 할당해준 각 arr의 칸의 주소가 나옴
	//값이 4씩 증가 (4byte씩)
	//16진수로 나옴 주소값은
	
	for (int i = 0; i < 4; i++)
		cout << *(p + i) << endl;
	//*를 통해그 주소에 해당하는 값을 pointing 해줌
	//안에 들어있는 값이 나옴

	for (int i = 0; i < 4; i++)
		cout << p[i] << endl;
	//배열 안에 들어있는 값이 나옴
	//배열명은 포인터 상수이므로
	//포인터를 이용해서 배열같이 쓸 수 있다

	//배열명을 포인터처럼 쓸 수도 있다
	for (int i = 0; i < 4; i++)
		cout << arr3 + i << endl; //주소 출력됨

	for (int i = 0; i < 4; i++)
		cout << *(arr3 + i) << endl; //배열 안의 값 출력됨


	//배열명은 포인터 상수다.

	//그래서 포인터를 배열처럼 배열을 포인터처럼 쓸 수 있다.
	*/
	


	//===============================================

	//auto 키워드
	//auto가 뒤에 나오는 것들을 보고 타입을 알아서 추론
	//c++ 11부터 지원

	int arr5[4] = { -9,0,0,30000 };
	auto * parr = &arr5[0];

	for (auto i = 0; i < 4; i++)
		cout << *(arr5 + i) << endl;

	//auto arr[4]처럼 배열엔 auto 못씀
}