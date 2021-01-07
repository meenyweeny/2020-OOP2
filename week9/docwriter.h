#pragma once
#include<string>
using namespace std;

class DocWriter {
public:
	DocWriter();
	DocWriter(const string& fileName, const string& content);
	~DocWriter();

	void SetFileName(const string& fileName);
	//const 사용함으로 원본의 손실없이 파일이름 지정하게 해줌
	void SetContent(const string& content);
	void Write();

protected: //public과 private 사이
	//상속관계에서는 접근 허용하는 개념
	string _fileName;
	string _content;
};