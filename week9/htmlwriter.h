#pragma once
#include"docwriter.h"
#include<string>

class HTMLWriter : public DocWriter {
	//��ӹ��� class�� protected ��� ����
public:
	HTMLWriter(void);
	HTMLWriter(const string& fileName, const string& content);
	~HTMLWriter(void);

	void Write(); //html �������� ������ ���� �޼���, �������̵� ��
	void SetFont(const string& fontName, int fontSize, const string& fontColor);

protected:
	string _fontName;
	int _fontSize;
	string _fontColor;
	//HTMLWriter class�� ���뺯��
};