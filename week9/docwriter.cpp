#include"docwriter.h"
#include<iostream>
#include<fstream>
using namespace std;

DocWriter::DocWriter() {
	_fileName = "NoName.txt";
	_content = "There is no content.";
}

DocWriter::DocWriter(const string& fileName, const string& content) {
	_fileName = fileName;
	_content = content;
}

DocWriter::~DocWriter() {
	//따로할일없어서 구현안함
}

void DocWriter::SetFileName(const string& fileName) {
	_fileName = fileName;
}

void DocWriter::SetContent(const string& content) {
	_content = content;
}

void DocWriter::Write() {
	ofstream of(_fileName.c_str()); //파일 open
	//보조기억장치에 파일생성하고
	//파일이름을 보조기억장치의 문자열의 주소로 넘겨주기 위해
	//outputfilestream
	//출력용 객체

	of << "# Content #\n\n"; //헤더 쓰기
	of << _content; //파일 쓰기
	//콘솔에서 눈으로 볼 수 없다
	//파일에다가 쓰는 작업을 한다
}