#include<iostream>
using namespace std;
#include<string>

//다중상속
//두개 이상의 부모클래스를 동시에 상속하는 경우
//양쪽의 기능을 다 활용할 수 있는 장점이 있다
//이 좋은 기능을 왜 다른 언어에선 안쓸까?

//문제점이 있다
//죽음의 다이아몬드 등등...


class UnderGradStudent { //학부생
public:
	string name;
	string dept;

	void Warn() {}; //학사경고
};

class DormStudent { //기숙사생
public:
	string building;
	int roomNo;

	void Warn() {}; //벌점 기숙사 경고
};

class UnderGrad_DormStudent :
	public UnderGradStudent, public DormStudent {
public:

};


int main() {
	UnderGrad_DormStudent s1;
	s1.name = "김인하";
	s1.dept = "CSE";
	s1.building = "1st";
	s1.roomNo = 1024;

	//s1.Warn(); //양쪽 부모로부터 상속을 받은 객체이기 때문에
	//어떤걸 상속받아야할지 모른다 //그래서 error


	//scope 지정으로 해결 가능
	s1.DormStudent::Warn();
}