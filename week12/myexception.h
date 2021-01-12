#pragma once

class MyException {
	//어디에서 어떻게 어떤 인덱스가 문제가 있는지를
	//객체를 하나 선언해줘서 에러를 더 디테일하게 표현할 수 있게 함

public:
	const void * sender; //예외를 throw할 객체의 주소를 보관할
	const char * description; //예외에 대한 설명을 담을 변수
	int info; //부가정보

	/*
	MyException(const void * _sender,const char * _description, int _info) {
		sender = _sender;
		description = _description;
		info = _info;
	}
	*/


	//this로 해결
	//this->현재 실행시점의 객체를 의미
	//this는 현재 실행시점의 객체의 메모리 번지 주소를 가지고있음

	MyException(const void * sender, const char * description, int info) {
		this->sender = sender;
		//멤버변수     //지역변수

		this->description = description;
		this->info = info;
	}

};