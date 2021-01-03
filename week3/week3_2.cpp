#include<iostream>
using namespace std;



//구조체 배열
/*
struct Student {
	//구조체 왜 씀?
	//공통된 부분을 묶어서 자료 관리하려고
	//배열은 type이 같아야하는데 구조체는 아님
	int id; //4byte
	char name[20]; //20byte
	float grade[2]; //1,2학기 성적 //8byte

	//32byte 단위의 구조체
	//os에서 40byte 단위로 좀 더 큼직큼직하게??
};

int main() {

	Student sInfos[4] = {
		{202001,"Lee",{4.3f,4.1f}},
		{202010,"Choi",{3.3f,3.1f}},
		{202107,"Park",{3.5f,4.1f}},
		{202101,"Kim",{4.2f,3.7f}}
	};

	for (auto i = 0; i < 4; i++) {
		cout << sInfos[i].id << endl;
		cout << sInfos[i].name << endl;
		cout << sInfos[i].grade[0] << endl; //1학기 성적
		cout << sInfos[i].grade[1] << endl;
		cout << endl;
	}
}
*/


//구조체와 포인터
/*
#include<iostream>
using namespace std;

//구조체를 먼저 설계하고 포인터를 작성해서 구조체를 포인팅

struct Rectangle {
	//멤버변수
	int x, y; //좌표 x,y
	int w, h; //width,height

};

int main(){

	Rectangle r = { 15,10,50,70 };
	Rectangle * pr = &r; //구조체 r을 가리키는 포인터

	cout << r.x << endl;
	cout << (*pr).x << endl;
	//연산자 우선순위가 * 먼저 처리하니까 괄호로 꼭 묶어서 여기의 x값을 출력

	cout << endl;

	cout << (*pr).y << endl; // (,),*,. 네개의 연산자 필요
	cout << pr->y << endl; //하나의 화살표 연산자
	//밑에 방식이 훨씬 간단하고 가독성이 뛰어나고 실수할일도 없어서 더 많이 씀

	cout << endl;

	cout << (*pr).h << "\n" << pr->h << endl;
	cout << endl;

	pr->h = 40; //사각형의 높이를 바꿔보자

	cout << (*pr).h << "\n" << pr->h << endl;

	cout << endl;

	(*pr).w = 100;
	cout << r.w << "\n" << pr->w << endl;
}
*/

//구조체와 포인터를 이용한 링크드리스트 구현
//구조체의 포인터 형태여야겠다
#include<iostream>
using namespace std;

struct LinkedList {
	int data;
	LinkedList * p; //내가 가리킬 대상도 구조체 변수니까
	//다음 노드를 가리킬 포인터 변수
};

int main() {
	LinkedList a, b, c;
	a.data = 99;
	a.p = &b; //setup
	b.data = 93;
	b.p = &c;
	c.data = 94;
	c.p = &a;

	//a를 이용해서 b의 data 찍기
	cout << b.data << endl;
	cout << a.p->data << endl;
	//a.p는 b의 주소니까
	//화살표 연산자로 그 data를찍음

	cout << endl;

	//c의 data 찍기
	cout << c.data << endl;

	//b를 이용해서 c의 data 찍기
	cout << b.p->data << endl;
	cout << (*b.p).data << endl; //간접멤버참조형태

	//a를 이용해서 c의 data 찍기
	cout << a.p->p->data << endl;

	//c가 자기자신을 한바퀴 돌아와서 찍기
	cout << c.p->p->p->data << endl;
}
