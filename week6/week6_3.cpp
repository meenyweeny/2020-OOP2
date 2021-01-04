//style 변환
//c- > c++
/*
#include<iostream>
#include<string>
using namespace std;

//c style은 묵시적 casting을 통해 c++ style로 변환가능
//그냥 알아서 변환됨

int main() {
	char cstyle[] = "Hi~";
	string cppstyle;
	cppstyle = cstyle; //묵시적 casting이 일어남
	//둘은 별도의 메모리 공간을 갖게된다
	cstyle[0] = 'A';
	//서로 하나만 바꿔줬을 때 영향을 안미친다

	cout << cstyle << endl;
	cout << cppstyle << endl;
}
*/

//c++ -> c
/*
#include<iostream>
#include<string>
using namespace std;

int main() {
	string cppstyle = "Hell!";
	const char * cstyle = NULL;

	cstyle = cppstyle.c_str();
	//cppstyle의 메모리 번지주소를 보관한 문자열의 주소를 얻어와서
	//포인터변수 cstyle에 전달해줌

	//c_str은 읽기전용으로, 값은 못바꿈

	cout << cstyle << endl;
	cout << cppstyle << endl;
}
*/


//동적할당과 다른 방법들
/*
#include<iostream>
#include<string>
using namespace std;
#pragma warning (disable : 4996)

int main() {
	string cppstyle = "Hell!";
	char * cstyle = new char[cppstyle.size() + 1]; //동적할당
	strcpy(cstyle, cppstyle.c_str());
	//참조할 주소를 주기위해 c_str
	//캐릭터형 포인터가 가리키는 생성된 메모리 번지에다가 복사
	//완벽한 카피본이 생김
	//cstyle이 가리키는 별도의 메모리 공간에 Hell!이 복사가 됐음

	cstyle[0] = 'Y';

	cout << cstyle << endl;
	cout << cppstyle << endl;

	delete[] cstyle; //메모리 해제
	cstyle = NULL; //불필요한 다른번지 참조를 예방
}
*/



//cin객체를 통해 입력

/*
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main() {
	char cstyle[10];
	string cppstyle;

	cin >> cstyle;
	cin >> cppstyle;
	//inha university를 입력하면 스페이스바를 기준으로 구분되어

	cout << cstyle << endl; //inha
	cout << cppstyle << endl; //university
	//이런 출력이 나옴


	//또다른문제
	//cstyle은 10칸짜리라 그 길이를 넘게 입력하면 문제가 생김
	//cstyle 배열사이즈 3으로 해놓고 abc를 입력해도 문제생김
	//ab는 가능 칸에 a,b,'\0' 이 들어감

	

	//라인단위로 바꾸려면 어떻게 해야할까


}
*/

//라인단위로
/*
#include<iostream>
#include<string>
using namespace std;

int main() {
	char cstyle[3];
	string cppstyle;

	cin.getline(cstyle,3); //몇개받을건지도 써줘야함(size 지정)
	//cin.getline은 객체에 속해있는 멤버 메서드

	//아까 ab까지 됐었는데 한번 abcde 입력해보면 어떻게될까?
	//ab까지만 받고 딱 끝남
	//cin객체는 자기자신의 상태를 관리하는데
	//세글자를 넘어가는 문자열을 입력받으며 cin객체는 자기 자신의 상태를
	//fail이라고 생각하게 됨
	//그래서 다음 라인이 정상동작하지 않음
	//그래서 cppstyle에는 아무런 문자가 출력되지 않는 문제가 생김

	//이러한 문제를 해결하기 위해 cin 객체의 fail 상태를 지워줄 메서드가 필요함

	cin.clear();


	//그럼 ab까지만 cstyle로 받고, clear를 해줬으니 나머지 cde를
	//cppstyle로 이어받음

	getline(cin, cppstyle);
	//getline은 일반함수

	cout << cstyle << endl;
	cout << cppstyle << endl;

}
*/


//헤더파일과 구현파일
#include<iostream>
#include"ex1.h" //main함수에게 지도같은역할을 함
using namespace std;

int main() {
	int r;
	r = Plus(3, 7);
	cout << r << endl;
	return 0;
}


//헤더파일 규칙
//1.공유될 함수가 있는 구현파일의 이름을 따서 헤더파일을 만든다
//ex1.cpp와 ex1.h처럼

//2.헤더파일에는 공유될 함수의 프로토타입을 적어준다
//int Plus(int a, int b);

//3. 공유될 함수를 호출을 할 구현파일에서 헤더파일을 포함한다
//#include "ex1.h"