//style ��ȯ
//c- > c++
/*
#include<iostream>
#include<string>
using namespace std;

//c style�� ������ casting�� ���� c++ style�� ��ȯ����
//�׳� �˾Ƽ� ��ȯ��

int main() {
	char cstyle[] = "Hi~";
	string cppstyle;
	cppstyle = cstyle; //������ casting�� �Ͼ
	//���� ������ �޸� ������ ���Եȴ�
	cstyle[0] = 'A';
	//���� �ϳ��� �ٲ����� �� ������ �ȹ�ģ��

	cout << cstyle << endl;
	cout << cppstyle << endl;
}
*/

//c++ -> c
/*
#include<iostream>
#include<string>
using namespace std;

int main() {
	string cppstyle = "Hell!";
	const char * cstyle = NULL;

	cstyle = cppstyle.c_str();
	//cppstyle�� �޸� �����ּҸ� ������ ���ڿ��� �ּҸ� ���ͼ�
	//�����ͺ��� cstyle�� ��������

	//c_str�� �б���������, ���� ���ٲ�

	cout << cstyle << endl;
	cout << cppstyle << endl;
}
*/


//�����Ҵ�� �ٸ� �����
/*
#include<iostream>
#include<string>
using namespace std;
#pragma warning (disable : 4996)

int main() {
	string cppstyle = "Hell!";
	char * cstyle = new char[cppstyle.size() + 1]; //�����Ҵ�
	strcpy(cstyle, cppstyle.c_str());
	//������ �ּҸ� �ֱ����� c_str
	//ĳ������ �����Ͱ� ����Ű�� ������ �޸� �������ٰ� ����
	//�Ϻ��� ī�Ǻ��� ����
	//cstyle�� ����Ű�� ������ �޸� ������ Hell!�� ���簡 ����

	cstyle[0] = 'Y';

	cout << cstyle << endl;
	cout << cppstyle << endl;

	delete[] cstyle; //�޸� ����
	cstyle = NULL; //���ʿ��� �ٸ����� ������ ����
}
*/



//cin��ü�� ���� �Է�

/*
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main() {
	char cstyle[10];
	string cppstyle;

	cin >> cstyle;
	cin >> cppstyle;
	//inha university�� �Է��ϸ� �����̽��ٸ� �������� ���еǾ�

	cout << cstyle << endl; //inha
	cout << cppstyle << endl; //university
	//�̷� ����� ����


	//�Ǵٸ�����
	//cstyle�� 10ĭ¥���� �� ���̸� �Ѱ� �Է��ϸ� ������ ����
	//cstyle �迭������ 3���� �س��� abc�� �Է��ص� ��������
	//ab�� ���� ĭ�� a,b,'\0' �� ��

	

	//���δ����� �ٲٷ��� ��� �ؾ��ұ�


}
*/

//���δ�����
/*
#include<iostream>
#include<string>
using namespace std;

int main() {
	char cstyle[3];
	string cppstyle;

	cin.getline(cstyle,3); //����������� �������(size ����)
	//cin.getline�� ��ü�� �����ִ� ��� �޼���

	//�Ʊ� ab���� �ƾ��µ� �ѹ� abcde �Է��غ��� ��Եɱ�?
	//ab������ �ް� �� ����
	//cin��ü�� �ڱ��ڽ��� ���¸� �����ϴµ�
	//�����ڸ� �Ѿ�� ���ڿ��� �Է¹����� cin��ü�� �ڱ� �ڽ��� ���¸�
	//fail�̶�� �����ϰ� ��
	//�׷��� ���� ������ ���������� ����
	//�׷��� cppstyle���� �ƹ��� ���ڰ� ��µ��� �ʴ� ������ ����

	//�̷��� ������ �ذ��ϱ� ���� cin ��ü�� fail ���¸� ������ �޼��尡 �ʿ���

	cin.clear();


	//�׷� ab������ cstyle�� �ް�, clear�� �������� ������ cde��
	//cppstyle�� �̾����

	getline(cin, cppstyle);
	//getline�� �Ϲ��Լ�

	cout << cstyle << endl;
	cout << cppstyle << endl;

}
*/


//������ϰ� ��������
#include<iostream>
#include"ex1.h" //main�Լ����� �������������� ��
using namespace std;

int main() {
	int r;
	r = Plus(3, 7);
	cout << r << endl;
	return 0;
}


//������� ��Ģ
//1.������ �Լ��� �ִ� ���������� �̸��� ���� ��������� �����
//ex1.cpp�� ex1.hó��

//2.������Ͽ��� ������ �Լ��� ������Ÿ���� �����ش�
//int Plus(int a, int b);

//3. ������ �Լ��� ȣ���� �� �������Ͽ��� ��������� �����Ѵ�
//#include "ex1.h"