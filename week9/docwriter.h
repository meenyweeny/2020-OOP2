#pragma once
#include<string>
using namespace std;

class DocWriter {
public:
	DocWriter();
	DocWriter(const string& fileName, const string& content);
	~DocWriter();

	void SetFileName(const string& fileName);
	//const ��������� ������ �սǾ��� �����̸� �����ϰ� ����
	void SetContent(const string& content);
	void Write();

protected: //public�� private ����
	//��Ӱ��迡���� ���� ����ϴ� ����
	string _fileName;
	string _content;
};