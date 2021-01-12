/*
#include<iostream>
#include<memory>
using namespace std;

//<<<unique_ptr에 대해서>>>
//c++11 (기존의 auto_ptr을 보완 대체)
//smart 포인터 (unique ptr) -> memory 라이브러리 필요
//무슨 특징 갖고있나? 우리가 한번 어떤 객체를 생성하고 그 객체를 가리키던
//포인터를 메모리 해제할 때, 포인터가 두개있다고 가정하면
//각각의 포인터가 한곳을 가리키고 있었는데 한쪽 포인터가 delete해서 해제됐는데
//또 다른 포인터가 같은주소니까 그걸 또 해제하려고하면 소멸된객체를 다시 소멸시켜서
//버그가 발생함 ->만들어진 객체에 대한 소유권이 명확하지 않아서 이런 일이 발생
//이를 해결하기 위해 객체한테 유일한 소유권을 부여하고, 이 포인터 말고는 객체를
//소멸시킬수 없다는 개념을 적용시킨 것

class Test {
	int * data;
public:
	Test() {
		cout << "생성자!" << endl;
		data = new int[100]; //400byte
	}
	~Test() { //해제가 되면 data를 통해 delete 해주는 역할
		cout << "소멸자!" << endl;
		delete[] data;
	}
	void t() { cout << "테스트 중..." << endl; }
};

void testing() {
	unique_ptr<Test> up(new Test());
	//unique_ptr 포인터 객체 up를 생성 (Test 타입의 객체를 가리킬 수 있는 애)
	//new Test() 시점에 생성자가 돌아가고, 400바이트 할당된 힙메모리 영역의 번지주소를
	//클래스의 data 에게 전달하는 것, 그럼 클래스에선 그 data를 통해 자원을 사용

	//up은 Test 객체를 갖고있으니 그 안의 원소나 멤버에 접근 가능

	up->t();
} //이 함수가 끝나는 시점에서 이 안에서 생성된 Test 객체가 소멸하게 된다
//그럼 이 안쪽에서 생성된 모든게 끝나고 소멸자가 동작하게 된다

int main() {
	testing();
}
*/


//=================================

//문제 일으켜보기

#include<iostream>
#include<memory>
using namespace std;

class Test {
	int * data;
public:
	Test() {
		cout << "생성자!" << endl;
		data = new int[100];
	}
	~Test() { 
		cout << "소멸자!" << endl;
		delete[] data;
	}
	void t() { cout << "테스트 중..." << endl; }
};

void testing() {
	/*
	Test * t1 = new Test();
	Test * t2 = t1; //소유권에 대한 문제 생김

	delete t1;
	delete t2; //객체는 하난데 소멸이 두번 되는 문제가 생김
	*/

	unique_ptr<Test> up1(new Test()); //Test * up1=new Test(); 와 같은 의미

	//unique_ptr<Test> up2 = up1; //유일한 주소로 받은거니까 에러가 남
	//Test * up3 = up1; //얘도 에러

	//unique_ptr은 delete까지 다 해주니까 따로 delete 해줄 필요도 없다
	//안전하게 메모리 문제를 해결하면서 쓸 수 있음
}

int main() {
	testing();
}