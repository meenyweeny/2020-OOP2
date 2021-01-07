#pragma once
#include"docwriter.h"
#include<string>

class HTMLWriter : public DocWriter {
	//상속받은 class의 protected 사용 가능
public:
	HTMLWriter(void);
	HTMLWriter(const string& fileName, const string& content);
	~HTMLWriter(void);

	void Write(); //html 포맷으로 저장할 쓰기 메서드, 오버라이딩 됨
	void SetFont(const string& fontName, int fontSize, const string& fontColor);

protected:
	string _fontName;
	int _fontSize;
	string _fontColor;
	//HTMLWriter class의 전용변수
};