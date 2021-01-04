//���ڿ�

/*
//����� ����
#include<iostream>
#include<string>
using namespace std;

int main() {
	char srcs[] = "Inha Univ"; //c���� ���ڿ��� ǥ���Ϸ��� �̹�����̾���
	string src = "Inha Univ";
	string dest;

	//modern style
	cout << src.size() << endl; //method ���·�
	//�� ���ϰ� �������� good
	dest = src; //�Ϲ� ���� �����ϵ��� ���԰���
	//c style���� �ξ� ����
	cout << src << endl;
	cout << dest << endl;

	//����ӵ��� �ٺ���ü�� �ٸ��� �ƴ϶� modern style(c++ style)��
	//old style(c style)�� ���� ū ������ ����
	//�׳� �� ���� ��
}
*/

//���հ� ��
/*
//Old Style
#include<iostream>
#include<string>
#include<cstring>
#pragma warning(disable : 4996)
using namespace std;

int main() {
	char str1[] = "Inha Univ";
	char str2[] = "Harvard Univ";
	strcat(str1, str2); //(str1�ڿ� str2��) �� ���ڿ��� ����
	cout << str1 << endl;
	cout << str2 << endl;

	return 0;
	//����ڰ� ������ �迭���� �� ū �����͸� �������� �Ҷ�
	//��Ÿ���� ������ ��Ÿ��

}
*/


//���ڿ� ��

//Old Style
/*
#include<cstring>
#include<iostream>
using namespace std;

int main() {
	char str1[10] = "Inha";
	char str2[] = "Harvard";
	char str3[] = "Inha";
	if (strcmp(str1, str2) == 0)
		cout << "����" << endl;
	else {
		cout << "�ٸ���" << endl;
	}

	if (strcmp(str1, str3) == 0)
		cout << "����" << endl;
	else
		cout << "�ٸ���" << endl;

	char a[10] = "I";
	char b[] = "H";
	char c[] = "J";

	if (strcmp(a, b) == 0)
		cout << "����" << endl;
	else {
		cout << "�ٸ���" << endl;
		cout << strcmp(a, b) << endl;
	}
	//�� 1�� ��µ�
	//I�� H��
	//���ĺ� ������� ���� �� �ڿ����� �� ũ�⶧���� 1�� ����

	if (strcmp(a, c) == 0)
		cout << "����" << endl;
	else {
		cout << "�ٸ���" << endl;
		cout << strcmp(a, c) << endl;
	}
	//�� -1�� ��µ�
	//���ĺ� �������� I�� �� ���̹Ƿ� -1�� ����

	//�ƽ�Ű�ڵ尪�� ���ϴ� ��
	//str1<str2 : -1 return
	//str1>str2 : +1 return

	//�������̸� 0�� ����
}
*/

//Modern style
/*
#include<iostream>
#include<string>
using namespace std;

int main() {
	//�̾���̱�
	
	string str5 = "Inha";
	string str6 = "Univ";

	str5 = str5 +str6;
	cout << str5 << endl;
	cout << str6 << endl;
	

	//��
	string str1 = "Inha";
	string str2 = "Inha";

	if (str1 == str2) {
		cout << "����" << endl;
		cout << (str1 == str2) << endl; //������ 1�� return //tf������ return
		cout << typeid((str1 == str2)).name() << endl; //bool ���(�񱳿������̹Ƿ�)
	}
	else {
		cout << "�ٸ���" << endl;
		cout << (str1 == str2) << endl; //�ٸ��� 0�� return
	}


}
*/


//find method
//���� ã�����ϴ� Ư�� ���ڿ� ã�Ƽ� ��ġ�� �������·� return

#include<iostream>
#include<string>
using namespace std;

int main() {
	string str = "Hi, Inha Univ.";
	cout << str.find("Inha") << endl; //I�� ��ġ �ε����� return
	cout << str.find("Univ") << endl; //U�� ��ġ �ε����� return
	//cout << str.find("univ") << endl; //����� �� ������� ���� �� ����

	//Ư�� ���ڿ��� ����

	string capture = str.substr(4, 4); //�ε��� 4���� 4�� (���� �ε����� ������ �Ķ���ͷ�)
	cout << capture << endl;
}