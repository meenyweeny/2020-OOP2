//constant 함수
//포인터나 레퍼런스에서는
//const 키워드가 자료타입 앞에 오면 해당 대상의 값을 변경할 수 없었고
//자료타입과 변수 사이에 오면 주소를 바꾸지 못하게 함
//일반 변수에 상수형태로 선언하기위해서도 쓰임

//함수에 const 속성을 부여하는게 어떤 의미를 가지고 있을까?


//자격 -> 멤버변수의 값을 변경하지 않는 메서드에서만 사용
//안에 멤버변수 값이 함부로 바뀌지 않도록 해줌
//다른 개발자에게 "이 함수의 멤버 변수의 값은 변경하지 않는다"라는 메세지 전달
//실수로 멤버변수의 값을 바꾸려고 시도할 때, 컴파일러 단에서 오류 메세지
//const 객체를 사용해서 이 함수를 호출 할 수 있다

#include"point.h"
#include<iostream>
using namespace std;

void area(const Point & pt) {
	//int area = pt.getX()*pt.getY();
	//pt.getY() 에서 오류난다
	//const로 파라미터를 받아왔으니까 아예 받아올 때 부터
	//값을 변경시킬 여지가 있는 메서드들은 다 빼고 const 메서드들만
	//받아올 수 있다.


	//getY라는 함수도 const로 고쳐서 해결해준다


	int area = pt.getX()*pt.getY();
	cout << "0,0 과 이 점이 이루는 사각형의 면적 = " << area << endl;
}
int main() {
	Point pt(100, 100);
	area(pt);
}