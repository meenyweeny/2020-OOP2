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
	//�������Ͼ�� ��������
}

void DocWriter::SetFileName(const string& fileName) {
	_fileName = fileName;
}

void DocWriter::SetContent(const string& content) {
	_content = content;
}

void DocWriter::Write() {
	ofstream of(_fileName.c_str()); //���� open
	//���������ġ�� ���ϻ����ϰ�
	//�����̸��� ���������ġ�� ���ڿ��� �ּҷ� �Ѱ��ֱ� ����
	//outputfilestream
	//��¿� ��ü

	of << "# Content #\n\n"; //��� ����
	of << _content; //���� ����
	//�ֿܼ��� ������ �� �� ����
	//���Ͽ��ٰ� ���� �۾��� �Ѵ�
}