//inheritance
//���
//�θ�Ŭ������ �ڿ��� �ڽ�Ŭ�������� Ȱ���Ѵ�
//�θ�Ŭ������ �������,����Լ����� �ڽ�Ŭ������ ������ �������� ����� �� �ִ�
//���뼺�� ���̰� �ڵ� ������ ���� �� �ִ�

#include<iostream>
#include"docwriter.h"
#include"htmlwriter.h"
using namespace std;

int main() {
	/*
	DocWriter dw; //default
	dw.Write();

	dw.SetFileName("exam.txt"); //������ �����ڷ� ���뺯��
	dw.SetContent("���� �ߺ�!");
	dw.Write();
	*/

	/*
	DocWriter dw2("assignment.txt", "���� ����~~");
	dw2.Write();
	*/

	//���
	HTMLWriter hw("gta.html", "Ʈ���� �ʸ���"); //�θ�Ŭ������ ������Ȱ��
	hw.Write(); //�ڽ� Ŭ������ �������̵� �� html ���� �޼���
}