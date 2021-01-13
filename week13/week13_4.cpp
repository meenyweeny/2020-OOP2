#include<iostream>
using namespace std;

//관련된 코드별로 구역을 나눠서 담으면 효율적
//namespace 사용하자!
//소스파일과 코드를 구조적으로 관리할 수 있다는 이점이 있음


namespace Python {
	struct Info {
		//struct는 무조건 다 public
		string prof;
		int id;
		//구조체 안에도 멤버변수 선언 가능
	};

	float grade;
	void talk() {
		cout << "Python 토크함수" << endl;
	}
}

namespace Cplusplus {
	class Info {
	public:
		string prof;
		int id;
	};
	float grade;
	void talk();
}

float grade = 0.0f; //default namespace에 속하니까
//별도로 지정하지 않고 앞에 콜론 두개만 붙여서 사용 가능


//using Cplusplus::talk; //talk 함수만 씀
//using Python::talk;
using namespace Cplusplus; //여기에 있는 전체를 다 씀

int main() {
	Cplusplus::grade = 4.5f;
	::grade = 4.0f; //전역변수인 grade에 접근

	cout << ::grade << endl;

	Cplusplus::talk(); //이것도 가능하고
	//main 위에 using Cplusplus::talk; 써두면
	//그냥 talk(); 해도 Cplusplus의 talk 함수가 실행된다
	//근데 그렇게 하는 것 보다 이렇게 명확하게 하는게 오류도 안나고 좋다

	talk(); //위에 using namespace ㅁㅁㅁ 정의 안되어있으면 오류
	Python::talk();


	Info p1; //Cplusplus의 Info 객체로 자동으로 생성
	p1.prof = "김인하";
	p1.id = 2020;
	//grade = 3.9f; //이렇게하면 전역변수 grade말하는건지 cplusplus꺼 말하는건지 몰라
	//전역변수 grade 없애던가 grade를 클래스의 멤버변수로 넣던가

}

namespace Cplusplus { //구현코드
	//밖으로 빼서 구현하는 방법
	void talk() {
		cout << "C++ 토크함수" << endl;
	}
}