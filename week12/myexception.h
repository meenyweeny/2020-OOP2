#pragma once

class MyException {
	//��𿡼� ��� � �ε����� ������ �ִ�����
	//��ü�� �ϳ� �������༭ ������ �� �������ϰ� ǥ���� �� �ְ� ��

public:
	const void * sender; //���ܸ� throw�� ��ü�� �ּҸ� ������
	const char * description; //���ܿ� ���� ������ ���� ����
	int info; //�ΰ�����

	/*
	MyException(const void * _sender,const char * _description, int _info) {
		sender = _sender;
		description = _description;
		info = _info;
	}
	*/


	//this�� �ذ�
	//this->���� ��������� ��ü�� �ǹ�
	//this�� ���� ��������� ��ü�� �޸� ���� �ּҸ� ����������

	MyException(const void * sender, const char * description, int info) {
		this->sender = sender;
		//�������     //��������

		this->description = description;
		this->info = info;
	}

};