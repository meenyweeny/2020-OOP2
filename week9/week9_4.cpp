//inheritance
//상속
//부모클래스의 자원을 자식클래스에서 활용한다
//부모클래스의 멤버변수,멤버함수들을 자식클래스가 별도의 구현없이 사용할 수 있다
//재사용성을 높이고 코드 라인을 줄일 수 있다

#include<iostream>
#include"docwriter.h"
#include"htmlwriter.h"
using namespace std;

int main() {
	/*
	DocWriter dw; //default
	dw.Write();

	dw.SetFileName("exam.txt"); //생성후 접근자로 내용변경
	dw.SetContent("시험 잘봄!");
	dw.Write();
	*/

	/*
	DocWriter dw2("assignment.txt", "과제 많다~~");
	dw2.Write();
	*/

	//상속
	HTMLWriter hw("gta.html", "트레버 필립스"); //부모클래스의 생성자활용
	hw.Write(); //자식 클래스의 오버라이딩 된 html 쓰기 메서드
}